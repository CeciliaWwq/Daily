#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//用静态成员函数计算由1到n的值
//计算创建了几个对象
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
		return Count;//因为Count设置的是私有成员所以用一个静态成员函数接受一下Count
	}
	
private:
static int Count;//定义静态成员变量，为了使多个成员变量公用一个成员变量
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
	Date d2 = d1;//Q:为什么只调用了一次构造函数？？
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
	calculate::reset();//这里就可以直接调用
	int n = 100;
	calculate* s = new calculate[n];
	delete[] s;//这里是释放s的空间，同时调用temp的析构函数
			  //析构100个temp对象
	s = NULL;//避免悬垂指针
	//但是静态变量存储在静态存储区，属于类，不属于任何对象，所以还可用

	int a[100];
	int temp = calculate::GetTemp();
	cout << temp << endl;
}
#endif
class A
{
public:
	//这里用explicit关键词来修饰类构造函数.
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
	//这样直接赋值,会被提示错误,因为explicit抑制隐式转换的进行
	//s = 10;//这样会报错!!!
	//当然显示转换还是可以的.
	s = A(20);

	system("pause");
	return 0;
}
