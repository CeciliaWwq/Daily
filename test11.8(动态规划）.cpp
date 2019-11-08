#define _CRT_SECURE_NO WARNINGS1
#include<iostream>
using namespace std;
//Ñ¡£ºmeet[i].value+OPT(prev[i])
//²»Ñ¡£ºOPT(i-1)
#define NUM 9
struct meet {
	int start;
	int end;
	int value;
};
int max(int a, int b)
{
	return a > b ? a : b;
}
void Solution(meet* meet, int n) {
	int pre[NUM] = { 0 };
	if (n == 1) { pre[0]= meet[1].value; }
	int i = 0;
	int j = 0;
	int opt[NUM] = { 0 };
	for (i = 2; i <=NUM; i++) {
		for (j = i-1; j >= 1; j--) {
			if (meet[j].end == meet[i].start) {
				pre[i] = j;
			}
		}
		if (pre[i] == 0) { opt[i] = max(meet[i].value, opt[i - 1]); }
		else { opt[i] = max(meet[i].value + opt[pre[i]], opt[i - 1]); }
	}
	for (auto c : opt) {
		cout << c << endl;
	}
}