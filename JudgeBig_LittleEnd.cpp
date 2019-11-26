//定义变量int i=1;将 i 的地址拿到，强转成char*型，
//这时候就取到了 i 的低地址，这时候如果是1就是小端存储，如果是0就是大端存储 int i=1   0x0001(0x00高  0x01低）
/*
#include<stdio.h>
int main()
{
	int i = 1;
	char c = (*(char*)& i);

	if (c)
		printf("小端\n");
	else
		printf("大端\n");
}
*/