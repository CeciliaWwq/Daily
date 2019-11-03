#define _CRT_SECURE_NO WARNINGS 1
#include<stdio.h>
//ð������
void bubble(int a[], int size)
{
	for (int i = 0; i < size; i++) {
		if (a[i] > a[i + 1])
		{
			int temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
		}
	}
}
void bubblesort(int a[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++)
		{
			if (a[i] > a[i + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
//��������
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Hover
int partition1(int a[], int left, int right) {
	//1.ѡȡ�������ұ�Ԫ��Ϊ��׼ֵ
	int begin = left;
	int end = right;
	int pivotIndex = a[right];
	while (begin < end) {
		while (begin < end && a[begin] <= pivotIndex) {
			begin++;
		}
		while (begin < end && a[begin] >= pivotIndex) {
			end--;
		}
		swap(a[begin], a[end]);
	}
	swap(a[begin], a[right]);
	return begin;
}
//�ڿ�
int partition2(int a[], int left, int right) {
	int begin = left;
	int end = right;
	int pivotIndex = a[right];
	while (begin < end) {
		while (begin < end && a[begin] <= pivotIndex) {
			begin++;
		}
		//���a[begin]>=pivotIndex
		swap(a[begin], a[end]);
		while (begin < end && a[begin] >= pivotIndex) {
			end--;
		}
		swap(a[end], a[begin]);
	}
	swap(a[begin], a[right]);
	return begin;
}
//ǰ���±귨��div�ǿɶ��ı�׼ֵ��������
//�����divС�ķ���div֮ǰ����div��ķ���div֮��
int partition3(int a[], int left, int right) {
	int div = left;
	int i = left;
	for (; i < right; i++) {
		if (a[i] < a[right]) {
			swap(a[i], a[div]);
		}
	}
	swap(a[div], a[right]);
	return left;
}
int quickSortInternal(int a[], int left, int right) {
	if (left >= right) { return; }
	//[left,right]������ֻʣ1����0����
	int pivotIndex = partition2(a, left, right);
	//1.ȷ����׼ֵ
	//2.��partitionС���󣬴���ң����ػ�׼ֵ�����±�
	//3.������������
	quickSortInternal(a, left, pivotIndex - 1);
	quickSortInternal(a, pivotIndex + 1, right);
}
void quickSort(int a[], int size) {
	quickSortInternal(a, 0, size - 1);
}
int main() {
	int a[] = { 2,3,4,3,6,5,9 };
	int size = sizeof(a) / sizeof(int);
	quickSort(a, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}