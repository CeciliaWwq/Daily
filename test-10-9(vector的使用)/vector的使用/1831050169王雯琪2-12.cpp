/*
#include<stdio.h>
#include<stdlib.h>
//������һ��ѭ�������ȴ���һ
//����ͷ���Ҳ��ͷָ�룬��֪sΪָ�������ָ��
//����������ɾ��ָ��S��ָ�Ľ���ǰ���ڵ�
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