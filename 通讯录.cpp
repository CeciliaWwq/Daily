#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<cstdio>

#include<cstdlib>

#include<cstring>

#define MAXSIZE 50

using namespace std;

int Czy = 1;

typedef struct record

{

	char Number[20];

	char Name[20];

	char Address[20];

}Record;



typedef struct Hash

{

	Record* data;

	int cnt;

	int size;

}*HashTable, HashElem;



//哈希函数，将电话号码每一位求和 

int GetHashKey(char ar[])

{

	int len = strlen(ar);

	int key = 0;

	for (int i = 0; i < len; i++) {

		key += ar[i] - '0';

	}

	return key%MAXSIZE;

}



//冲突处理，二次探测再散列 

int HandleCollision(HashTable table, int key)

{

	Czy = 1; //从2,3,4,5,....... 

	while (1) {

		Czy++; //从2,3,4,5,....... 

		if (Czy % 2 == 0) {

			if (table->data[(key + (Czy / 2) * (Czy / 2))% MAXSIZE].Name[0] == 0)

				return (key + (Czy / 2) * (Czy / 2)) % MAXSIZE;

		}

		else if (Czy % 2 != 0) {

			if ((key - (Czy / 2) * (Czy / 2)) < 0) continue;//由于是减法，要注意负数不能取模 

			if (table->data[(key - (Czy / 2) * (Czy / 2))%MAXSIZE].Name[0] == 0)

				return (key - (Czy / 2) * (Czy / 2)) % MAXSIZE;

		}

	}

	//return -1;

}



//构建哈希表 

void CreateHashTable(HashTable& table, Record* record, int n)

{

	int key;

	for (int i = 0; i < n; i++) {

		key = GetHashKey(record[i].Number);

		if (table->data[key].Name[0] != 0)

			key = HandleCollision(table, key);



		strcpy(table->data[key].Number, record[i].Number);

		strcpy(table->data[key].Name, record[i].Name);

		strcpy(table->data[key].Address, record[i].Address);

	}

}



//按照电话号码寻找 

int SerchKey(HashTable table, char PhoneNumber[])

{

	int key = GetHashKey(PhoneNumber);

	if (strcmp(table->data[key].Number, PhoneNumber)) {

		for (Czy = 1; Czy < MAXSIZE; Czy++) {

			if (Czy % 2 == 0) {

				if (!strcmp(PhoneNumber, table->data[(key + (Czy / 2) * (Czy / 2)) % MAXSIZE].Number)) {

					key = (key + (Czy / 2) * (Czy / 2)) % MAXSIZE;

					break;

				}

			}

			else if (Czy % 2 != 0) {

				if ((key - (Czy / 2) * (Czy / 2)) < 0) continue;//由于是减法，要注意负数不能取模 

				if (!strcmp(PhoneNumber, table->data[(key - (Czy / 2) * (Czy / 2)) % MAXSIZE].Number)) {

					key = (key - (Czy / 2) * (Czy / 2)) % MAXSIZE;

					break;

				}

			}

		}
		return key;
	}

	//if(flag) cout<<"未找到！请重新输入！"<<endl;

	cout << table->data[key].Name << " " << table->data[key].Number << " " << table->data[key].Address << endl;

}



//将哈希表存入文件中 

void GoToFile(HashTable table)

{

	FILE* fp = fopen("Output.txt", "w");

	for (int i = 0; i <= MAXSIZE; i++)

		if (table->data[i].Name[0] != 0)

			fprintf(fp, "%s %s %s\n", table->data[i].Name, table->data[i].Number, table->data[i].Address);

	//printf("%s %s %s\n",table->data[i].Name,table->data[i].Number,table->data[i].Address);	

	fclose(fp);

}



int main() {

	//定义及初始化 

	Record record[50];

	HashElem table;

	HashTable numbertable;

	numbertable = &table;

	numbertable->data = (Record*)malloc(sizeof(record[0]) * MAXSIZE);

	memset(numbertable->data, 0, sizeof(record[0]) * MAXSIZE);

	numbertable->size = MAXSIZE;

	numbertable->cnt = 0;

	int k;

	//输入数据 组数及 各个数据 

	//freopen("Data.txt","r",stdin);

	cin >> k;

	for (int i = 0; i < k; i++)

		cin >> record[i].Number >> record[i].Name >> record[i].Address;

	//创建哈希表 

	CreateHashTable(numbertable, record, k);

	//存入文件中 

	GoToFile(numbertable);

	//输入并寻找PhoneNumber（必须存在表中） 

	char PhoneNumber[20];

	cin >> PhoneNumber;

	cout << "给定电话号码为：" << endl << PhoneNumber << endl << "搜索到的号码数据为：" << endl;

	SerchKey(numbertable, PhoneNumber);

	return 0;

}