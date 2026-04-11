#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


//typedef struct 
//{
//	char id;//学号
//	char name;//姓名
//	int i;
//}Student;
//
//typedef struct
//{
//	char id;//学号
//	int i;
//	char name;//姓名
//}Student2;
//
//
//int Add(int a2, int b2)
//{
//	return a2 + b2;
//}
//
//int main()
//{
//	int a = 18;
//	int b = 25;
//
//	/*Student s1;
//	Student2 s2;
//	printf("%d\n%d\n", sizeof(s1), sizeof(s2));*/
//
//
//	int(*p1)(int, int) = Add;
//
//	printf("%d\n", (*p1)(a, b));
//	printf("%d\n", p1(66, 77));
//
//	return 0;
//}



//// 定义单链表节点
//typedef struct Node
//{
//    int data;
//   struct Node* next;
//} Node;
//
//// 创建新节点
//Node* createNode(int data) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    newNode->data = data;
//    newNode->next = NULL;
//    return newNode;
//}
//
//// 头插法
//Node* insertAtHead(Node* head, int data) {
//    Node* newNode = createNode(data);
//    if (head == NULL) {
//        return newNode;
//    }
//    newNode->next = head;
//    return newNode;
//}
//
//// 尾插法
//Node* insertAtTail(Node* head, int data) {
//    Node* newNode = createNode(data);
//    if (head == NULL) {
//        return newNode;
//    }
//    Node* cur = head;
//    while (cur->next != NULL) {
//        cur = cur->next;
//    }
//    cur->next = newNode;
//    return head;
//}
//
//// 遍历打印
//void printList(Node* head) {
//    Node* cur = head;
//    while (cur != NULL) {
//        printf("%d ", cur->data);
//        cur = cur->next;
//    }
//    printf("\n");
//}
//
//int main() {
//    Node* head = NULL;
//    int num;
//    printf("输入整数（-1结束）：");
//    while (1) {
//        scanf("%d", &num);
//        if (num == -1) break;
//        //head = insertAtHead(head, num);
//        head = insertAtTail(head, num);
//    }
//    //printf("头插法链表：");
//    printf("尾插法链表：");
//    printList(head);
//    return 0;
//}



//第 4 题：双向链表基础操作
//题目要求
//实现双向链表的头插、尾插、删除、遍历
//维护prev和next两个指针
//输出操作后的链表，验证双向结构
#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    struct DNode* prev;
    int data;
    struct DNode* next;
}DNode;

//创建节点
DNode* createDNode(int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
// 头插
DNode* insertAtHead(DNode* head, int data) {
    DNode* newNode = createDNode(data);
    if (head == NULL)
    {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// 尾插
DNode* insertAtTail(DNode* head, int data) {
    DNode* newNode = createDNode(data);
    if (head == NULL)
    {
        return newNode;
    }
    DNode* cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    newNode->prev = cur;
    cur->next = newNode;
    return head;
}

// 删除
DNode* deleteDNode(DNode* head, int data) {
    DNode* cur = head;
    while (cur && cur->data != data) cur = cur->next;
    if (!cur) return head;
    if (cur->prev) cur->prev->next = cur->next;
    else head = cur->next;
    if (cur->next) cur->next->prev = cur->prev;
    free(cur);
    return head;
}

//遍历打印
void printDList(DNode* head) {
    DNode* cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    DNode* head = NULL;
    head = insertAtHead(head, 10);
    head = insertAtTail(head, 20);
    head = insertAtTail(head, 30);
    printf("双向链表：");
    printDList(head);

    head = deleteDNode(head, 20);
    printf("删除20后：");
    printDList(head);
    return 0;
}

















