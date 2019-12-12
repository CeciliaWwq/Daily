/*
#define _CRT_SECURE_NO WARNINGS 1
#include<iostream>
#include<assert.h>
typedef int SDataType;
typedef struct Stack
{
	SDataType* _array;
	int _capacity;
	int _top; // 标记栈顶位置 
}Stack;

// 初始化栈 
void StackInit(Stack* ps) {
	ps->_top = 0;
}

// 入栈 
void StackPush(Stack* ps, SDataType data) {
	ps->_array[ps->_top] = data;
	ps->_top++;
}

// 出栈 
void StackPop(Stack* ps) {
	assert(ps->_top != NULL);
	ps->_array[ps->_top--];
}

// 获取栈顶元素 
SDataType StackTop(Stack* ps) {
	return ps->_array[ps->_top];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps) {
	int count = 0;
	while (ps->_array[count] != NULL) {
		count++;
	}
	return count;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps) {
	return ps->_top == 0 ? 1 : 0;
}

// 销毁栈 
void StackDestroy(Stack* ps) {
	free(ps->_array);
}


typedef int QDataType;

// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;

// 初始化队列 
void QueueInit(Queue* q) {
	q->front = q->rear = NULL;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data) {
	QListNode* node = (QListNode*)malloc(sizeof(QListNode));
	node->_data = data;
	if (q->front == NULL) {
		q->front = node;
	}
	else { q->rear->_pNext = node; }
	q->rear = node;//更新队列最后一个节点为node；

}

// 队头出队列 
void QueuePop(Queue* q) {
	assert (q->front != NULL);
	QListNode* second = q->front->_pNext;
	int val = q->front->_pNext->_data;
	free(q->front);
	q->front = second;
	second->_data = val;
	if (q->front == NULL) {  //当队列只有一个元素时rear也要手动指向空
		q->rear = NULL;
	}
}

// 获取队列头部元素 
QDataType QueueFront(Queue* q) {
	assert(q->front != NULL);
	return q->front->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q) {
	assert(q->rear != NULL);
	return q->rear->_data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q) {
	int count = 0;
	while (q->front->_pNext != NULL) {
		count++;
	}
	return count;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q) {
	if (q->front == NULL) { return 1; }
	else { return 0; }
}

// 销毁队列 
void QueueDestroy(Queue* q) {
	free(q);
	q->front == NULL;
	q->rear == NULL;
}
*/