#define _CRT_SECURE NO WARNINGS 1
#include<stdio.h>
int findmaxindex(int a[], int size) {
		int max = a[0];
        int pos = 0;
	    for (int i = 0; i < size; i++) {
			if (a[i] > a[0]) {
				max = a[i];
				pos = i;
			}
		}
		return pos;
	}
	void selectsort(int a[], int size) {
		for (int i = size; i >1; i--) {
			int b = findmaxindex(a,i);
			int temp = a[b];
			a[b] = a[i-1];
			a[i-1]=temp;
		}
	}

//��ʵ��ѡ������
	void adjustup(int a[], int size, int index) {
		//���ϵ���
		while (1) {
			int left = index * 2 + 1;
			int right = index * 2 + 2;
			if (left >= size) { return; }
			int max = left;
			if (right<size && a[right]>a[left]) {
				max = right;
			}
			if (a[index] >= a[max]) {
				return;
			}
			else {
				int t = a[index];
				a[index] = a[max];
				a[max] = t;
			}
			index = max;
		}
	}

	void selectsort2(int a[], int size) {
		//�����
		for (int i = (size - 2) / 2; i >= 0; i--) {
			adjustup(a, size, i);
		}
		//ÿ���ڴ����ѡ�������β������
		for (int i = 0; i < size; i++) {
			int t = a[0];
			a[0] = a[size - 1 - i];
			a[size - 1 - i] = t;
			//�������������ڶ�β�������������µ�����ȡ������Ķ���Ԫ��
			adjustup(a, size - i - 1, 0);
		}

	}

	int main()
	{
		int a[6] = { 3,1,2,4,6,5 };
		int size = sizeof(a) / sizeof(a[0]);
		selectsort2(a, size);
		for (int i = 0; i < size; i++) {
			printf("%d\n", a[i]);
		}
		system("pause");
	}