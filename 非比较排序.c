#define _CRT_SECURE_NO WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//归并排序
int Min(int a, int b) {
	a < b ? a : b;
}
void MergeSorttest(int*array, int left, int right,int temp) {
	if (left + 1 < right) {
		int mid = left + ((right - left) >> 1);
		MergeSort(array, left, mid, temp);
		MergeSort(array, mid, right, temp);
		MergeData(array, left, mid, right, temp);
		memcpy(array + left, temp + left, (right - left) * sizeof(int*));
	}
}
void MergeData(int* array, int left, int mid, int right, int*temp) {
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid;
	int end2 = right;
	int index = left;
	while (begin1 < end1 && begin2 < end2) {
		if (array[begin1] <= array[begin2]) {
			temp[index++] = array[begin1++];
		}
		else {
			temp[index++] = array[begin2++];
		}
	}
	while (begin1 < end1) {
		temp[index++] = array[begin1++];
	}
	while (begin2 < end2) {
		temp[index++] = array[begin2++];
	}
	array = temp;
	free(temp);
}
int main() {
	int a[] = { 2,3,4,3,6,5,9 };
	int size = sizeof(a) / sizeof(int);
	int* temp = (int*)malloc((size) * sizeof(int*));
	MergeSorttest(a,0,7,temp); 
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}

//计数排序
void CountNumberSort(int a[], int n) {
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}
	int* c;
	memset(c, 0, sizeof(int) * ((max-min) + 1));
	for (int i = 0; i < n; i++) {
		c[a[i]]++;
	}
	int k = 0;
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < c[i]; j++)//值i出现c[i]次
		{
			a[k++] = i;
		}
	}
	
}

int main() {
	int a[] = { 52,53,54,3,6,5,9 };
	int size = sizeof(a) / sizeof(int);
	int* temp = (int*)malloc((size) * sizeof(int*));
	CountNumberSort(a, 7);
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}