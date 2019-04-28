#define _CRT_SECURE_N0_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int fun()
//{
//	static int count = 1;
//	return ++count;
//}
//int main()
//{
//	int answer;
//	answer = fun() - fun()*fun();
//	printf("%d\n", answer);
//	system("pause");//2-3*4= -10
//	return 0;
//}
//静态局部变量使用static修饰符定义，
//即使在声明时未赋初值，编译器也会把它初始化为0。
//且静态局部变量存储于进程的全局数据区，即使函数返回，它的值也会保持不变。
//变量在全局数据区分配内存空间；编译器自动对其初始化 
//其作用域为局部作用域，当定义它的函数结束时，其作用域随之结束

//int main()
//{
//	int a = 1;
//	int ret = (++a) + (++a) + (++a); //用VC编译运算的结果 b=12，而用gcc编译则 b=10
//	printf("%d\n", ret);//ret=9
//	system("pause");
//	return 0;
//}

//int main()
//{
	/*int a = 1;
	int* p = &a;
	printf("%d\n", *p);
	system("pause");
	return 0;*/
	//char a = 10;
	////int* pa = &a;
	//char* pc = &a;
	////printf("%p\n", pa);
	////printf("%p\n", pa + 1);
	//
	//printf("%p\n", pc);
	//printf("%p\n", pc + 1);
	//system("pause");
	//return 0;
//}
//int main()
//{
//	char arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	char* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = 0;
//
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n",arr[i]);
//	}
//	system("pause");
//	return 0;
//}
//int main()
{
	/*int arr[10] = {1,2,3,4,5,6,7,8,9,10}
	int* p = arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = 0;
	}*/
	//char a = 0x11223344;
	////int* pa = &a;
	////*pa = 0;
	//char *pc = &a;
	//*pc = 0;
	//printf("%d\n", a);
	//system("pause");
	//return 0;
	

	//double d[10] = { 0 };
	//double *pd = d;
	////printf("%p\n", pd);
	////printf("%p\n", pd + 4);//double所占字节8；4*8=32
	//printf("%d\n", *pd);
	//printf("%d\n", *pd + 4);

	//int arr[10] = { 0 };
	////char ch[10] = { 0 };
	////printf("%d\n", &arr[9] - &arr[0]);
	////printf("%d\n", &arr[8] - &ch[0]);
	//printf("%d\n", sizeof(arr));
	//system("pause");
	//return 0;

	//复习至114行
}