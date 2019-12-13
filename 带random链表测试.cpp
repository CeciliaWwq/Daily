// 带random链表测试.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
typedef struct Node {
	int val;
	struct Node* next;
	struct Node* random;
};

Node* CopeList(Node* head)
{
	//把原链表和拷贝链表连接在一起
	Node* cur = head;
	while (cur != NULL) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->val = cur->val;
		node->next = cur->next;
		cur = node;
		cur = node->next;//node->next = NULL;让循环跑起来！！
	}
	cur = head;
	//拷贝random
	while (cur != NULL) {
		if (cur->random == NULL) {
			cur->next->random = NULL;
		}
		else {
			cur->next->random = cur->random->next;
		}
		cur = cur->next->next;//cur = cur->next;让循环跑起来要注意拷贝的是哪个
	}
	//将两个合在一起的链表分开
	cur = head;
	Node* newhead = head->next;
	while (cur != NULL)
	{
		Node* node = cur->next;
		head->next = node->next;
		if (node->next->next != NULL)
		{
			node->next = node->next->next;
		}
		cur = cur->next;
	}
	return newhead;
}

int main() {
	//测试用例，创建一个链表
	Node* node1 = (Node*)malloc(sizeof(Node*));
	Node* node2 = (Node*)malloc(sizeof(Node*));
	Node* node3 = (Node*)malloc(sizeof(Node*));
	Node* node4 = (Node*)malloc(sizeof(Node*));
	Node* node5 = (Node*)malloc(sizeof(Node*));
	node1->val = 1;
	node1->next = node2;
	node1->random = node4;
	node2->val = 2;
	node2->next = node3;
	node2->random = node2;
	node3->val = 3;
	node3->next = node4;
	node3->random = node1;
	node4->val = 4;
	node4->next = node5;
	node4->random = node2;
	node5->val = 5;
	node5->next = NULL;
	node5->random = node3;
	Node* result = CopeList(node1);
	for (Node*cur = node1; cur != NULL; cur=cur->next) {
		printf("%p (%d,%p)",cur, cur->val, cur->random);
	
	}
	printf("\n");
	
	for (Node*cur = result; cur != NULL; cur = cur->next) {
		printf("%p (%d,%p)", cur, cur->val, cur->random);

	}
	system("pause");
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
