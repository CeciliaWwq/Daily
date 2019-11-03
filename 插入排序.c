#define _CRT_SECURE_NO WARNINGS 1
#include<stdio.h>
void insertsort(int a[], int size) {
	//选定第一个为有序，从下标为1开始向前插入
	for (int i = 0; i < size; i++) {
		//有序区间[0,i)
		//无序区间[i,size)
		//抓的牌是[i]
		int j;
		//选择插入下标
		for (j = i - 1; j >= 0; j--) {
			if (a[i] >= a[j]) {
				break;
			}
		}
		int index = j + 1;
		//再把i插入合适下标
		int k = a[i];
		//k插入到index位置
		for (int t = i; t > index; t--) {
			a[t ] = a[t-1];
		}
		a[index] = k;
	}
}
void insertsort2(int a[], int size) {
	//有序区间【0，i)
	//无序区间【i,size)
	for (int i = 0; i < size; i++) {
		int k = a[i];
		int j;
		for (j = i - 1; j >= 0 && a[j] > a[i]; j--) {
			a[j+1] = a[j];
		}
		a[j + 1] = k;
	}
}
//希尔排序
void shellsort(int a[], int size,int gap) {
	for (int i = 0; i < size; i++) {
		int k = a[i];
		int j;
		while (1) {
			gap = gap / 3 + 1;
			for (j = i - gap; j >= 0 && a[j] > a[i]; j -= gap) {
				a[j + gap] = a[j];
			}
			a[j + gap] = k;
			if (gap == 1) { break; }
		}
		
	}
}
int main()
{
	int a[6] = { 3,1,2,4,5,7 };
	shellsort(a, 6,6);
	for (int i = 0; i < 6; i++) {
		printf("%d\n", a[i]);
	}
	system("pause");
	return 0;
}