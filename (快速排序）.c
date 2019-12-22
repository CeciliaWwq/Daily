#define _CRT_SECURE_NO WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Hover
int partition1(int a[], int left, int right) {
	//1.选取数组最右边元素为基准值
	int begin = left;
	int end = right;
	int pivotIndex = a[right];
	while (begin < end) {
		while (begin<end&&a[begin] <= pivotIndex) {
			begin++;
		}
		while (begin<end&&a[begin] >= pivotIndex) {
			end--;
		}
		swap(a[begin], a[end]);
	}
	swap(a[begin], a[right]);
	return begin;
}
//挖坑
int partition2(int a[], int left, int right) {
	int begin = left;
	int end = right;
	int pivotIndex = a[right];
	while (begin < end) {
		while (begin < end && a[begin] <=pivotIndex) {
			begin++;
		}
		//如果a[begin]>=pivotIndex
		swap(a[begin], a[end]);
		while (begin<end && a[begin] >= pivotIndex) {
			end--;
		}
		swap(a[end], a[begin]);
	}
	swap(a[begin], a[right]);
	return begin;
}
//前后下标法，div是可动的标准值，向后遍历
//如果比div小的放在div之前，比div大的放在div之后
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
	//[left,right]区间内只剩1个或0个数
	int pivotIndex = partition2(a, left, right);
	//1.确定基准值
	//2.做partition小的左，大的右，返回基准值最终下标
	//3.分治左右两边
	quickSortInternal(a, left, pivotIndex - 1);
	quickSortInternal(a, pivotIndex + 1, right);
}
void quickSort(int a[], int size) {
	quickSortInternal(a, 0, size - 1);
}
int main() {
	int a[] = {2,3,4,3,6,5,9};
	int size = sizeof(a) / sizeof(int);
	quickSort(a, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}


void bubbleSort(int a[], int size) {
	for (int i = 0; i < size; i++) {
		int flag = 1;
		for (int j = 0; j < size - i-1; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
				flag = -1;
			}
		}
		if (flag == 1) { break; }
	}
}

int main()
{
	int a[6] = {3,1,2,4,5,7};
	int size = sizeof(a) / sizeof(a[0]);
	//bubbleSort(a, size);
	quickSort(a, size);
	for (int i = 0; i < 6; i++) {
		printf("%d\n", a[i]);
	}
	system("pause");
	return 0;
}
//希尔排序
void shellSort(int a[], int size) {
	int gap = size;
	while (1) {
		gap = gap / 3 + 1;
		for (int i = 0; i < size; i++) {
			int k = a[i];
			int j;
			for (j = i - gap; j >= 0 && a[j] < k; j -= gap) {
				a[j + gap] = a[j];
			}
			a[j + gap] = k;
		}
		if (gap == 1) {
			break;
		}
	}
}
void Insertsort(int a[], int size) {
	
}