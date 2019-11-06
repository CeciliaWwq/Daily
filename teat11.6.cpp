#include<iostream>
#include<string>
using namespace std;
string& Solution(string& s) {
	reverse(s.begin(), s.end());
	auto start = s.begin();
	while (start != s.end()) {
		auto end = start;
		while (end != s.end() && *end !=' ') {
			end++;
		}
		reverse(start, end);
		if (*end != ' ') {
			start = end++;
		}
		else {
			start = end;
		}
	}
}
int main()
{
	string s("I like beijing.");
	string s2 = Solution(s);
	for (auto ch : s2)
	{
		cout << ch;
	}
}

#include<iostream>
#include<vector>
using namespace std;
int Solution(int x, vector<int>v)
{
	int count = 0;
	int flag = 2;
	int i = 1;
	while (i != x)
	{
		while (v[i] >= v[i - 1]) {
			flag = 1;
			i++;
		}
		if (i != x) {
			flag = 0;
			count++;
		}
		while (v[i] <= v[i - 1]) {
			flag = 1;
			i++;
		}
		if (i != x)
		{
			flag = 0;
			count++;
		}
		i++;
	}
	return count;
}

int main()
{
	int array[6] = { 1,2,3,2,2,1 };
	vector<int> v(array, array + sizeof(array) / sizeof(array[0]));
	int b = Solution(6, v);
	cout << b << endl;
}