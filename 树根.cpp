#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s))
	{
		int num = 0;
		for (auto c : s)
			num += c - '0';
		while (num / 10 != 0)
		{
			int cnt = 0;
			while (num)
			{
				cnt += num % 10;
				num = num / 10;
			}
			num = cnt;
		}
		printf("%d\n", num);
	}
	return 0;
}
