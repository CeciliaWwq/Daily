#include<iostream>
using namespace std;
class Person {
public:
	virtual void BuyTickets() { //virtual Person* BuyTicket() Э��
		cout << "ȫ��Ʊ" << endl;
	}
	/*
	~Person()
	{
		cout << "I am Person" << endl;//��ͨ����
	}
	*/
	virtual ~Person()
	{
		cout << "I am Person" << endl;//��̬����
	}
};

class Student :public Person
{
public:
	void BuyTickets() {   //virtual Student* BuyTickets() Э�����麯��������д�����⣬��ʹ����ֵ����ͬ
		cout << "���Ʊ" << endl;
	}
	~Student()
	{
		cout << "I am Student" << endl;
	}
};

void SellTicWin(Person& p)//����ΪʲôҪ��ָ��������ã�����ָ��Ϊʲô����ȥ�������ຯ����
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
	delete p;//�ڲ���virtual������¹�ȻĬ���ǵ��õ�person������������ԭ������ͨ����ֻ������ֵ�����й�ϵ
	return 0;

}