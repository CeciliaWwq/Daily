#include<iostream>r
#include<math.h>
#pragma once
using namespace std;
static int DEFAULT_DEEP = 8;
class OrderBinaryTree {
	OrderBinaryTree() {
		this->deep = DEFAULT_DEEP;
		this->arraysize = pow(2, deep) - 1;
		OrderBinaryTree* _array = new OrderBinaryTree[arraysize];
	}
	OrderBinaryTree(int deep) {
		this->deep = DEFAULT_DEEP;
		this->arraysize = pow(2, deep) - 1;
		OrderBinaryTree* _array = new OrderBinaryTree[arraysize];
	}
	OrderBinaryTree* operator=(int x) {
		 if (this->val == x) {
			 return ;
		 }
	}
	int operator[](int x)
	{
		return array[x];
	}
	int FindLeaf(int* array) {
		int i = 0;
		int count=0;
		for (i = arraysize; i >arraysize/2; i--) {
			count++;
		}//�ҵ����һ��Ҷ�ӽڵ��˫�ף�˫�׵���һλ����Ҷ�ӽڵ�
	}
	int FingUnleaf(int x) {
		int result = arraysize - x;
		return result;
	}

private:
	int arraysize;
	int deep;
	int val;
	int* array;
};