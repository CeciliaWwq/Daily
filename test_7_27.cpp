#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//�þ�̬��Ա����������1��n��ֵ
//���㴴���˼�������
/*
class Date {
public:
	Date()
	//Date(int _a=10, int _b=20):
		//a(_a),
		//b(_b)
		//Count(_Count)
	{
		//a = _a;
		//b = _b;
		Count++;
		cout << Count << endl;
	}
	~Date() {
		Count--;
		cout << Count << endl;
	}
	static int ReCount() {
		return Count;//��ΪCount���õ���˽�г�Ա������һ����̬��Ա��������һ��Count
	}
	
private:
static int Count;//���徲̬��Ա������Ϊ��ʹ�����Ա��������һ����Ա����
	int a;
	int b;
};
int Date::Count = 0;
//void Test() {
//	Date d1;
//	Date d2(d1);
//	
//}
int main() {
	Date d1;
	Date d2 = d1;//Q:Ϊʲôֻ������һ�ι��캯������
	//cout << Date::ReCount << endl;
	//Test();
}
*/

# if 0
class calculate {
public:
	calculate() {
		Count++;
		temp += Count;
	}
	static void reset() {
		temp = 0;
		Count = 0;
	}
	/*static int count(int temp,int Count){
		temp += Count;
	}
	*/
	static int GetTemp() {
		return temp;
	}
private:
	static int temp;
	static int Count;
};
int calculate::temp = 0;
int calculate::Count = 0;
int main()
{
	calculate::reset();//����Ϳ���ֱ�ӵ���
	int n = 100;
	calculate* s = new calculate[n];
	delete[] s;//�������ͷ�s�Ŀռ䣬ͬʱ����temp����������
			  //����100��temp����
	s = NULL;//��������ָ��
	//���Ǿ�̬�����洢�ھ�̬�洢���������࣬�������κζ������Ի�����

	int a[100];
	int temp = calculate::GetTemp();
	cout << temp << endl;
}
#endif
class A
{
public:
	//������explicit�ؼ����������๹�캯��.
	explicit A(int i = 5, int j = 10)
	{
		m_a = i;
		m_b = j;
	}
private:
	int m_a;
	int m_b;
};

int main()
{
	A s;
	//����ֱ�Ӹ�ֵ,�ᱻ��ʾ����,��Ϊexplicit������ʽת���Ľ���
	//s = 10;//�����ᱨ��!!!
	//��Ȼ��ʾת�����ǿ��Ե�.
	s = A(20);

	system("pause");
	return 0;
}
