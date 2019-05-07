#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
//int fabonacci(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else{ return fabonacci(n - 1) + fabonacci(n - 2); }
//}
//int main()
//{
//	int n = 3;
//	printf("请输入第几个数");
//	scanf("%d/n", &n);
//	int ret = fabonacci(n);
//	printf("ret=%d\n", ret);
//	system("pause");
//	return 0;
//
//}

//int fabonacci(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	if (n>2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n = 3;
//	printf("请输入第几个数");
//	scanf("%d/n", &n);
//	int ret = fabonacci(n);
//	printf("ret=%d\n", ret);
//	system("pause");
//	return 0;
//}
//int Factor(int n, int k)
//{
//	if (k == 1)
//	{
//		return n;
//	}
//	if (k == 0)
//	{
//		return 1;
//	}
//
//	return n * Factor(n, k - 1);
//}
//
//
//int main()
//{
//	int n;
//	int k;
//	scanf_s("%d %d", &n, &k);
//	printf("%d\n", Factor(n, k));
//	system("pause");
//}

//int DigitSum(int n)
//{
//	int sum = 0;
//	int m;
//	if (n != 0)
//	{
//		m = n % 10;
//		n = n / 10;
//		sum = m + DigitSum(n);
//	}
//	return sum;
//}
//int main（）
//{
//	int a;
//	printf("请输入一个数")
//	scanf("%d", &a);
//	printf("Sum=%d\n", DigitSum(a));
//	system("pause");
//	return 0;
//}
//void reverse_string(char * string)
//{
//	if (*string == '\0')
//		printf("%c", *string);
//	else
//	{
//		reverse_string(++string);  //输出下一个字符
//		printf("%c", *(--string));  //因为string已经执行完++，所以若要输出当前字符得--
//
//	}
//}
//int main()
//{
//	char s[] = "abcdefgh";
//	reverse_string1(s);
//	return 0;
//}

//#include<stdio.h>
//int mystrlen(char* string)
//{
//	int count = 0;
//	while (*string != '\0')
//	{
//		count++;
//		string++;
//	}
//	return count;
//}
//int main()
//{
//	char string[] = "abcdefghijk";
//	int ret = mystrlen(string);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//
//#include<stdio.h>
//int mystrlen(char* string)
//{
//	if (*string != '\0')
//	{
//		return 1 + mystrlen(string + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	char string[] = "abcdefghijk";
//	int ret = mystrlen(string);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//int D_N(int n)//递归
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else
//		return n*D_N(n - 1);
//}
//int FD_N(int n) //非递归
//{
//	int sum = 1;
//	for (; n > 0; n--)
//	{
//		sum *= n;
//	}
//	return sum;
//}
//int main()
//{
//	int n = 5;
//	printf("请输入n:");
//	scanf_s("%d", &n);
//	int DS = 0;
//	int FDS = 0;
//	DS = D_N(n);
//	FDS = FD_N(n);
//	printf("递归结果：%d\n", DS);
//	printf("费递归结果：%d\n", FDS);
//
//	system("pause");
//	return 0;
//}
//void print(int n)
//{
//	if (n>9)
//	{
//		print(n / 10);
//	}
//	printf("%d  ", n % 10);
//}
//
//int main()
//{
//
//	int num = 1234;
//	print(num);
//	system("pause");
//	return 0;
//}
