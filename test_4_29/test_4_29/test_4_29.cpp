#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int my_strlen(char* str)//��¼�ַ��ĸ������õݹ飻
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//	printf("%d\n", count);
//	system("pause");
//
//}

//my_strlen("abc")
//1+my_strlen("bc")
//1+1+my_strlen("c")
//1+1+1+my_strlen("/0")
 /*int my_strlen(char* str)
{
	char *start = str;
	while (*str != '/0')
	{
		str++;
	}
	return str - start;
}
int main()
{
	int len = my_strlen("abcfd");
	printf("%d\n", len);
	system("pause");
	return 0;
}*/
//int main����
//{
//	int arr[10] = { 0 };
//	int *p = arr;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	printf("\n");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", *(p + i));
//	}
//	system("pause");
//	return 0;
//}
//int main()
//
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", (p + i));
//		printf("\n");
//		
//	}
//	printf("\n");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	system("pause");
//	return 0;
//}
//printf("%p\n,arr);//�������Ԫ�ص�ַ��
//printf("%p\n",&arr[0]);//������Ԫ�ص�ַ��

//�����������ȡ��������
//���1��sizeof(arr)//�������Ǳ�ʾ�������飬���������������ĳ��ȣ�ע��sizeof��strlen������
//���2��printf("%p",&arr);//ȡ������������ĵ�ַ��
//
//ָ������
//int main()
//{
//	int arr[10];//�������飻
//	char ch[5];
//	int* arr2[6];
//	char* arr3[5];
//
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = 3;
//	int d = 4;
//	int e = 5;
//
//
//	int* arr[5] = { &a, &b, &c, &d, &e };
//	printf("%d\n",*arr[4]);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int arr1[5] = { 1, 2, 3, 4, 5 };
//	int arr2[5] = { 2, 3, 4, 5, 6 };
//	int arr3[5] = { 3, 4, 5, 6, 7 };
//	int* arr[3] = { arr1, arr2, arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d", arr[i][j]);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int arr1[5] = { 1, 2, 3, 4, 5 };
//	int arr2[5] = { 2, 3, 4, 5, 6 };
//	int arr3[5] = { 3, 4, 5, 6, 7 };
//	int* arr[3] = { arr1, arr2, arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d", *(arr[i]+j));//arr[j]=*(arr+j)
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
//int main()
//{
//	char* arr1[15];//sizeof(arr1)-20;
//	int* arr2[5];//sizeof(arr)-20;
//	return 0;
//}