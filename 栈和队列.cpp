/*
#define _CRT_SECURE_NO WARNINGS 1
#include<iostream>
#include<assert.h>
typedef int SDataType;
typedef struct Stack
{
	SDataType* _array;
	int _capacity;
	int _top; // ���ջ��λ�� 
}Stack;

// ��ʼ��ջ 
void StackInit(Stack* ps) {
	ps->_top = 0;
}

// ��ջ 
void StackPush(Stack* ps, SDataType data) {
	ps->_array[ps->_top] = data;
	ps->_top++;
}

// ��ջ 
void StackPop(Stack* ps) {
	assert(ps->_top != NULL);
	ps->_array[ps->_top--];
}

// ��ȡջ��Ԫ�� 
SDataType StackTop(Stack* ps) {
	return ps->_array[ps->_top];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps) {
	int count = 0;
	while (ps->_array[count] != NULL) {
		count++;
	}
	return count;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps) {
	return ps->_top == 0 ? 1 : 0;
}

// ����ջ 
void StackDestroy(Stack* ps) {
	free(ps->_array);
}


typedef int QDataType;

// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q) {
	q->front = q->rear = NULL;
}

// ��β����� 
void QueuePush(Queue* q, QDataType data) {
	QListNode* node = (QListNode*)malloc(sizeof(QListNode));
	node->_data = data;
	if (q->front == NULL) {
		q->front = node;
	}
	else { q->rear->_pNext = node; }
	q->rear = node;//���¶������һ���ڵ�Ϊnode��

}

// ��ͷ������ 
void QueuePop(Queue* q) {
	assert (q->front != NULL);
	QListNode* second = q->front->_pNext;
	int val = q->front->_pNext->_data;
	free(q->front);
	q->front = second;
	second->_data = val;
	if (q->front == NULL) {  //������ֻ��һ��Ԫ��ʱrearҲҪ�ֶ�ָ���
		q->rear = NULL;
	}
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q) {
	assert(q->front != NULL);
	return q->front->_data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q) {
	assert(q->rear != NULL);
	return q->rear->_data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q) {
	int count = 0;
	while (q->front->_pNext != NULL) {
		count++;
	}
	return count;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q) {
	if (q->front == NULL) { return 1; }
	else { return 0; }
}

// ���ٶ��� 
void QueueDestroy(Queue* q) {
	free(q);
	q->front == NULL;
	q->rear == NULL;
}
*/