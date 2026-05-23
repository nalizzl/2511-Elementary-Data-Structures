#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 200   // 每行最大字符数
#define MAX_LINES 50      // 最大行数
#define MAX_UNDO 50        // 最大撤销步数

 //撤销
typedef struct {
    int type;               // 0添加, 1删除
    char content[MAX_LINE_LEN]; //撤销内容
} UndoRecord;

//编辑器
typedef struct {
    char lines[MAX_LINES][MAX_LINE_LEN]; // 二维数组存储文本行
    int line_count;                      // 当前行数
    UndoRecord undo_stack[MAX_UNDO];     // 撤销栈
    int undo_top;                        // 栈顶索引，-1为空栈
} Editor;

//初始化
void init_editor(Editor* ed) {
    ed->line_count = 0;
    ed->undo_top = -1;
}

//压栈最后一步操作
void push_undo(Editor* ed, int type, const char* content) {
    if (ed->undo_top + 1 >= MAX_UNDO) {
        printf("撤销栈已满，无法记录更多操作\n");
        return;
    }
    ed->undo_top++;
    ed->undo_stack[ed->undo_top].type = type;
    strncpy(ed->undo_stack[ed->undo_top].content, content, MAX_LINE_LEN - 1);
    ed->undo_stack[ed->undo_top].content[MAX_LINE_LEN - 1] = '\0';
}

//出栈最后一步操作
void undo(Editor* ed) {
    if (ed->undo_top < 0) {
        printf("没有可撤销的操作！\n");
        return;
    }
    UndoRecord* top = &ed->undo_stack[ed->undo_top];
    ed->undo_top--;   // 出栈

    if (top->type == 0) {  // 撤销添加，删除最后一行
        if (ed->line_count > 0) {
            ed->line_count--;
            printf("已删除刚添加的一行 \"%s\"\n", top->content);
        }
    }
    else if (top->type == 1) { // 撤销删除，恢复被删的行到末尾
        if (ed->line_count < MAX_LINES) {
            strcpy(ed->lines[ed->line_count], top->content);
            ed->line_count++;
            printf("已恢复被删除行 \"%s\"\n", top->content);
        }
        else {
            printf("文本行数已达上限\n");
        }
    }
}

//添加一行到末尾
void add_line(Editor* ed, const char* text) {
    if (ed->line_count >= MAX_LINES) {
        printf("已达到最大行数 %d\n", MAX_LINES);
        return;
    }
    // 先记录操作（压栈）
    push_undo(ed, 0, text);
    // 再添加
    strcpy(ed->lines[ed->line_count], text);
    ed->line_count++;
    printf("已添加: %s\n", text);
}

//删除最后一行
void delete_last_line(Editor* ed) {
    if (ed->line_count == 0) {
        printf("没有内容可删除\n");
        return;
    }
    // 先记录被删除的行内容（压栈）
    push_undo(ed, 1, ed->lines[ed->line_count - 1]);
    // 再删除
    ed->line_count--;
    printf("已删除最后一行\n");
}

//显示所有行
void show_all(Editor* ed) {
    if (ed->line_count == 0) {
        printf("当前文本为空\n");
        return;
    }
    printf("\n=====当前文本内容=====\n");
    for (int i = 0; i < ed->line_count; i++) {
        printf("%d. %s\n", i + 1, ed->lines[i]);
    }
    printf("共 %d 行\n", ed->line_count);
}


int main() {
    Editor ed;
    init_editor(&ed);
    int choice = -1;
    char buffer[MAX_LINE_LEN];

    while (1) {
        printf("\n==========简易文本编辑器==========\n");
        printf("1. 添加一行\n");
        printf("2. 删除最后一行\n");
        printf("3. 撤销\n");
        printf("4. 显示所有行\n");
        printf("0. 退出\n");
        printf("请输入要执行的操作：\n");
        scanf("%d", &choice);
        getchar(); //删回车

        switch (choice) {
        case 1:
            printf("请输入文本: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0'; // 去掉末尾换行符
            add_line(&ed, buffer);
            break;
        case 2:
            delete_last_line(&ed);
            break;
        case 3:
            undo(&ed);
            break;
        case 4:
            show_all(&ed);
            break;
        case 0:
            printf("已退出！\n");
            return 0;
        default:
            printf("输入有误！请重新输入\n");
        }
    }
    return 0;
}