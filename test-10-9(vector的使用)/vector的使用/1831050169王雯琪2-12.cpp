/*
#include<stdio.h>
#include<stdlib.h>
//假设有一个循环链表长度大于一
//且无头结点也无头指针，已知s为指向链表的指针
//试在链表中删除指针S所指的结点的前驱节点
typedef struct Node {
	int val;
	struct Node* prev;
	struct Node* next;
	struct Node* random;
}Node;

Node* Solution2(Node* head,Node*s)
{
	Node* cur = head;
	Node* prev = head;
	while (cur != cur->prev) {
		if (cur == s) {
			prev->next = cur->next;
			cur = cur->next;
		}
		prev=cur;
		cur = cur->next;
	}

}
*/