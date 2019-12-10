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



//��ϣ���������绰����ÿһλ��� 

int GetHashKey(char ar[])

{

	int len = strlen(ar);

	int key = 0;

	for (int i = 0; i < len; i++) {

		key += ar[i] - '0';

	}

	return key%MAXSIZE;

}



//��ͻ��������̽����ɢ�� 

int HandleCollision(HashTable table, int key)

{

	Czy = 1; //��2,3,4,5,....... 

	while (1) {

		Czy++; //��2,3,4,5,....... 

		if (Czy % 2 == 0) {

			if (table->data[(key + (Czy / 2) * (Czy / 2))% MAXSIZE].Name[0] == 0)

				return (key + (Czy / 2) * (Czy / 2)) % MAXSIZE;

		}

		else if (Czy % 2 != 0) {

			if ((key - (Czy / 2) * (Czy / 2)) < 0) continue;//�����Ǽ�����Ҫע�⸺������ȡģ 

			if (table->data[(key - (Czy / 2) * (Czy / 2))%MAXSIZE].Name[0] == 0)

				return (key - (Czy / 2) * (Czy / 2)) % MAXSIZE;

		}

	}

	//return -1;

}



//������ϣ�� 

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



//���յ绰����Ѱ�� 

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

				if ((key - (Czy / 2) * (Czy / 2)) < 0) continue;//�����Ǽ�����Ҫע�⸺������ȡģ 

				if (!strcmp(PhoneNumber, table->data[(key - (Czy / 2) * (Czy / 2)) % MAXSIZE].Number)) {

					key = (key - (Czy / 2) * (Czy / 2)) % MAXSIZE;

					break;

				}

			}

		}
		return key;
	}

	//if(flag) cout<<"δ�ҵ������������룡"<<endl;

	cout << table->data[key].Name << " " << table->data[key].Number << " " << table->data[key].Address << endl;

}



//����ϣ������ļ��� 

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

	//���弰��ʼ�� 

	Record record[50];

	HashElem table;

	HashTable numbertable;

	numbertable = &table;

	numbertable->data = (Record*)malloc(sizeof(record[0]) * MAXSIZE);

	memset(numbertable->data, 0, sizeof(record[0]) * MAXSIZE);

	numbertable->size = MAXSIZE;

	numbertable->cnt = 0;

	int k;

	//�������� ������ �������� 

	//freopen("Data.txt","r",stdin);

	cin >> k;

	for (int i = 0; i < k; i++)

		cin >> record[i].Number >> record[i].Name >> record[i].Address;

	//������ϣ�� 

	CreateHashTable(numbertable, record, k);

	//�����ļ��� 

	GoToFile(numbertable);

	//���벢Ѱ��PhoneNumber��������ڱ��У� 

	char PhoneNumber[20];

	cin >> PhoneNumber;

	cout << "�����绰����Ϊ��" << endl << PhoneNumber << endl << "�������ĺ�������Ϊ��" << endl;

	SerchKey(numbertable, PhoneNumber);

	return 0;

}