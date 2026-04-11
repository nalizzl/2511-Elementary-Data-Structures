#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10  // 哈希表大小

// 节点结构（存 key-value）
typedef struct Node {
	char key[50];
	int value;
	struct Node* next;
} Node;

// 哈希表 = 数组 + 链表
Node* hashTable[SIZE];

// 哈希函数：把字符串 → 数组下标
int hash(char* key) {
	int sum = 0;
	for (int i = 0; key[i] != '\0'; i++) {
		sum += key[i];
	}
	return sum % SIZE;
}

// 创建节点
Node* createNode(char* key, int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->key, key);
	newNode->value = value;
	newNode->next = NULL;
	return newNode;
}

// 插入
void insert(char* key, int value) {
	int index = hash(key);
	Node* newNode = createNode(key, value);

	// 发生冲突：头插法加到链表前面
	newNode->next = hashTable[index];
	hashTable[index] = newNode;
}

// 查找
int find(char* key) {
	int index = hash(key);
	Node* cur = hashTable[index];

	while (cur != NULL) {
		if (strcmp(cur->key, key) == 0) {
			return cur->value;
		}
		cur = cur->next;
	}
	return -1; // 没找到
}

int main() {
	insert("apple", 100);
	insert("banana", 200);
	insert("cat", 300);


	printf("apple = %d\n", find("apple"));
	printf("banana = %d\n", find("banana"));
	printf("cat = %d\n", find("cat"));

	return 0;
}