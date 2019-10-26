#define _CRT_SECURE_NO WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
//有序顺序表的指定元素的保序插入
//设一顺序表中元素值递增有序,写一算法,将元素X插到表中适当位置,并保持顺序表的有序性。
typedef int DataType;
class Seqlist {
public:
	Seqlist(DataType* array1, size_t size):
	array(new DataType[size])
		,_size(size)
		,_capacity(size)
	{
		for (size_t i=0; i < size; ++i) {
			array[i] = array1[i];
		}
	}



	void SeqlistSort()
	{
		assert(this);
		size_t temp, j;
		for (size_t i = _size; i>=1; i--)
		{
			for (j = 0; j <_size-1; j++)
			{
				if (array[j] >array[j+1])
				{
					temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
				}
			}
		}
		
	}
	void reserve(size_t capacity) {
		if (capacity > _capacity) {
			DataType* newarray = new DataType[capacity * 2];
			for (size_t i = 0; i < _size; ++i) {
				newarray[i]=array[i];
			}
			delete[] array;
			array = newarray;
			_capacity = capacity;
		}
	}
	void SeqlistInsert(int x) {
		size_t temp = 0;
		if (_capacity == _size) { reserve(_capacity + 1); }
		for (size_t i = 0; i < _size; ++i) {
				if (x < array[i])
				{
					temp = i;
				}
		}
		for (size_t m = _size-1; m >=temp-1; --m) {
			array[m + 1] = array[m];
		}
	array[temp-1] = x;
	_size++;
	 array[_size] = '/0';
	}
	void SeqlistDestory(Seqlist* ps) {
		assert(ps->array);
		{
			free(ps->array);
			ps->array = NULL;
			ps->_size = ps->_capacity = 0;
		}
	}
	void Print()//打印顺序表
	{
		if (_size > 0)
		{
			for (size_t i = 0; i < _size; ++i)
				cout << array[i] << " ";
			cout << endl;
		}
		else
			cout << "顺序表为空" << endl;
	}

private:
	DataType* array;
	size_t _size;
	size_t _capacity;

};
int main()
{
	int array[5] = {1,2,6,3,5};
	Seqlist s1(array, sizeof(array) / sizeof(array[0]));
	s1.SeqlistSort();
	s1.Print();
	s1.SeqlistInsert(4);
	s1.Print();
}