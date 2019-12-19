
#include<iostream>
#include<vector>
using namespace std;
#if 0
//vector��������ʹ��
void PrintVector(const vector<int>& v) {
	//ʹ��const���������б�����ӡ��const������ָ��Ķ����ǲ��ܱ��ı��
	vector<int>::const_iterator it = v.begin();
	while (it != v.end()) {
		cout << *it<<' ';
		++it;
	}
	cout << endl;
}
int main()
{
	/*
	vector<int>first();
	vector<int>second(4, 100);
	vector<int>third(second.begin(), second.end());
	vector<int>fourth(third);//�������캯��
	int array[] = { 5,2,0 };
	vector<int>fifth;
	for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	{
		cout << ' ' << *it;
		cout << '\n' << endl;
	}
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//���õ��������б�����ӡ
	vector<int>::iterator it= v.begin();
	while (it != v.end()) {
		cout << *it;
		it++;
	}
	cout << endl;
	//�õ����������޸�
	while (it != v.end()) {
		*it *= 2;
		++it;
	}
	//ʹ�÷��������������ӡ
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend()) {
		cout << *rit;
		rit++;
	}
	cout << endl;
	int a[] = { 1,3,9,1,1,9 };
	vector<int>v2(a, a+sizeof(a) / sizeof(int));
	while (it != v2.end()) {
		cout << *it;
		it++;
	}
	cout << endl;
	v2.pop_back();
	v2.pop_back();
	while (it != v2.end()) {
		cout << *it;
		++it;
	}
	*/
	/*
	int b[] = { 1,2,3,4 };
	vector<int>vb(b, b + sizeof(int));
	vector<int>::iterator pos = find(vb.begin(), vb.end(), 3);
	vb.insert(pos, 30);
	vector<int>::iterator it = vb.begin();
	while (it != vb.end()) {
		cout << *it<<" ";
		++it;
	}
	cout << endl;
	
	pos = find(vb.begin(), vb.end(), 3);
	vb.erase(pos);
	it = vb.begin();
   while (it != vb.end()) {
	   cout << *it<<" ";
	   ++it;
		}
   cout << endl;
   //reference operator[]��size_type n)֧�ֿɶ���д
   */

   int c[]= { 5,2,0 };
   vector<int>vc(c, c + sizeof(c) / sizeof(int));
	   for(auto x : vc) {
		   cout << x << " ";
   }
   cout << endl;
}
#endif

//����oj
//���ֻ����һ�ε�����i

#if 0
	int findOnceNum(vector<int>&v){
		int result = 0;
		for (size_t i = 0; i < v.size(); ++i) {
			result ^= v[i];
		}
		return result;
	}

int main()
{
	 vector<int>v1{1, 2, 3, 2, 1};
	cout<<findOnceNum(v1)<<endl;
}
#endif
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>>vv;
		vv.resize(numRows);
		for (size_t i = 1; i <= numRows; ++i)
		{
			vv[i - 1].resize(i, 0);
			vv[i - 1][0] = 1;
			vv[i - 1][vv[i].size() - 1] = 1;
		}
		for (int i = 0; i < vv.size(); ++i) {
			for (int j = 0; j < vv[i].size(); ++j) {
				if (vv[i][j] == 0) {
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}
			}
		}
		return vv;

	}
};
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) { return nums.size(); }
		int j = 0;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[j] != nums[i]) {
				nums[++j] = nums[i];
			}
		}
		return ++j;
	}
};
//����ֻ����һ�ν��ף����Σ�
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int a = 0, b = 0;
		for (auto x : nums) {
			b = (b ^ x) & ~a;
			a = (a ^ x) & ~b;
		}
		return b;
	}
};
//��ֻ����һ�Σ��������һ�ε�����
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int temp = 0;
		for (int i = 0; i < nums.size(); ++i) {
			temp ^= nums[i];
		}
		int TheNum = temp & (~temp + 1);//ȡ���λΪ1���������������ȻΪ1��֤����������������λ����ͬ
		int a = 0, b = 0;
		for (int c : nums) { //����������ֳ�����
			if (c & TheNum)
				a ^= c;
			else
				b ^= c;
		}
		return { a,b };
	}

};
//�����г���һ�����
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty()) {
			return 0;
		}
		int size = numbers.size();
		int temp = numbers[0];
		int times = 1;
		// �ҳ��ظ�������������, �����ֲ���һ�����Ǵ�������һ��
		for (int i = 1; i < size; i++) {
			if (numbers[i] == temp) {
				times++;
			}
			else {
				times--;
			}

			if (0 == times) {
				temp = numbers[i];
				times = 1;
			}
		}
		// ȷ���ظ����ٴ�
		times = 0;
		for (int i = 0; i < size; i++) {
			if (numbers[i] == temp) {
				times++;
			}
		}
		// �ж��ظ������Ƿ���������һ��
		if (times > (size / 2)) {
			return temp;
		}
		else {
			return 0;
		}
	}
};