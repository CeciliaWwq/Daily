#include<iostream>
#include<string>
#include<vector>
using namespace std;
//11.9
//�ַ������ҳ�������ַ���
//����������һ���ַ���str������ַ���str�е�����������ִ�
//���룺abcd12345ed125ss123456789
//�����123456789
#if 0
int main()
{
	string res, cur, s;
	cin >> s;
	for (int i = 0; i <=s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			cur += s[i];
		}
		else {
			if (res.size() <= cur.size())
			{
				res = cur;
			}
			else { cur.clear(); }
		}
	}
	cout << res;
	return 0;
}
#endif

#include<iostream> 
#include<string> 
using namespace std; 
int main() {
	string str, res, cur;
	cin >> str;
	for (int i = 0; i <= str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			cur += str[i];
		}
		else
		{
			if (res.size() < cur.size())
			{
				res = cur;
			}
			cur.clear();
		}
	}
	cout << res;
	return 0;
}
////}