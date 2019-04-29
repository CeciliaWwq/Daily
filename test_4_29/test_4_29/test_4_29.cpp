#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int my_strlen(char* str)//记录字符的个数利用递归；
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
//int main（）
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
//printf("%p\n,arr);//数组的首元素地址；
//printf("%p\n",&arr[0]);//数组首元素地址；

//有两种情况是取整个数组
//情况1：sizeof(arr)//数组名是表示整个数组，计算的是整个数组的长度（注意sizeof和strlen的区别）
//情况2：printf("%p",&arr);//取的是整个数组的地址；
//
//指针数组
//int main()
//{
//	int arr[10];//整形数组；
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