#define _CRT_SECURE_NO WARNINGS 1
#include<stdio.h>
void insertsort(int a[], int size) {
	//ѡ����һ��Ϊ���򣬴��±�Ϊ1��ʼ��ǰ����
	for (int i = 0; i < size; i++) {
		//��������[0,i)
		//��������[i,size)
		//ץ������[i]
		int j;
		//ѡ������±�
		for (j = i - 1; j >= 0; j--) {
			if (a[i] >= a[j]) {
				break;
			}
		}
		int index = j + 1;
		//�ٰ�i��������±�
		int k = a[i];
		//k���뵽indexλ��
		for (int t = i; t > index; t--) {
			a[t ] = a[t-1];
		}
		a[index] = k;
	}
}
void insertsort2(int a[], int size) {
	//�������䡾0��i)
	//�������䡾i,size)
	for (int i = 0; i < size; i++) {
		int k = a[i];
		int j;
		for (j = i - 1; j >= 0 && a[j] > a[i]; j--) {
			a[j+1] = a[j];
		}
		a[j + 1] = k;
	}
}
//ϣ������
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