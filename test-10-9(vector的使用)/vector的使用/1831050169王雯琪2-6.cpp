/*
#include<stdio.h>
#include<stdlib.h>
//6.已知顺序表L中的元素为int,请写一时间复杂度为O(n),
//空间复杂度为O(1)的算法将奇数元素排在前面
//偶数元素排在后面
typedef struct Node {
    struct Node* next;
	struct Node* prev;
	int val;
}Node;
Node* Solution1(Node*head)
{
	Node* prev = NULL;
	Node* cur = head;
	Node* node = head;
	Node* last = head;
	while (last->next != NULL) {
		last = last->next;
	}
	Node* aim = last;
	while (cur->next != aim) {
		if (cur==head&&cur->val%2==0) {
			node = cur;
			prev = cur->next;
			last->next = node;
			last = node;
		}

		if (cur->val % 2 == 0) {
			node = cur;
			prev = cur->next;
			last->next = node;
			last = node;
		}
		prev = cur;
		cur = cur->next;
	}
	last->next = NULL;
	return head;
}
int main()
{
	Node* node1 = (Node*)malloc(sizeof(Node*));
	Node* node2 = (Node*)malloc(sizeof(Node*));
	Node* node3 = (Node*)malloc(sizeof(Node*));
	Node* node4 = (Node*)malloc(sizeof(Node*));
	Node* node5 = (Node*)malloc(sizeof(Node*));
	node1->val = 1;
	node1->next = node2;
	node2->val = 4;
	node2->next = node3;
	node3->val = 7;
	node3->next = node4;
	node4->val = 2;
	node4->next = node5;
	node5->val = 8;
	node5->next = NULL;
	Node* Result = Solution1(node1);
	for (Node* cur = node1; cur != NULL; cur = cur->next) {
		printf("%d" ,cur->val);
	}
}
*/