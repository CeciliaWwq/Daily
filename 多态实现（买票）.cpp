#include<iostream>
using namespace std;
class Person {
public:
	virtual void BuyTickets() { //virtual Person* BuyTicket() 协变
		cout << "全价票" << endl;
	}
	/*
	~Person()
	{
		cout << "I am Person" << endl;//普通调用
	}
	*/
	virtual ~Person()
	{
		cout << "I am Person" << endl;//多态调用
	}
};

class Student :public Person
{
public:
	void BuyTickets() {   //virtual Student* BuyTickets() 协变是虚函数构成重写的例外，即使返回值不相同
		cout << "半价票" << endl;
	}
	~Student()
	{
		cout << "I am Student" << endl;
	}
};

void SellTicWin(Person& p)//这里为什么要串指针或者引用？基类指针为什么可以去调用子类函数？
{
	p.BuyTickets();
}
int main()
{
	/*Student s;
	SellTicWin(s);
	Person p;
	SellTicWin(p);
	*/

    Person* p = new Person;
	p->BuyTickets();
	delete p;

	p = new Student;
	p->BuyTickets();
	delete p;//在不加virtual的情况下果然默认是调用的person的析构函数，原因是普通调用只跟返回值类型有关系
	return 0;

}