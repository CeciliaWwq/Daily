#define _CRT_SECURE_NO WARNINGS 1
#include<iostream>
template<typename T>
class Seqlist {
public:
	Seqlist()://调用构造函数，开辟空间
		array(new T[10]),
		capacity(10),
		size(0)
	{}
	Seqlist(T* array1, size_t size) :
		array(new T[size]),
		capacity(size),
		_size(size)
	{
		//memcpy(array, array1, sizeof(T)*_size);？？
		for (int i = 0; i < size; ++i) {
			array[i] = array1[i];
		}
	}
	Seqlist(const Seqlist& s) ://拷贝一条顺序表
		array(new T(s._size)),
		capacity(s._capacity),
		size(s._size) {
		for (int i; i < size; ++i) {
			array[i] = s.array[i];
		}
	}
	void CheckCapacity(T* array1) {
		if (array1._size < array1.capacity) { return; }
		else {
			T* array2 = new[]array1 * 2;//找到新家
			for (int i = 0; i < array1.size; ++i) {
				array2[i] = array1[i];//搬家
			}
			delete[]array1;
			array1 = array2;
		}
	}
	//顺序表头插
	void PushFront(T* array1,int data) {
		CheckCapacity();
		for (int i = 0; i < array1._size; ++i) {
			array[i + 1]=array1[i];
		}
		array1[0] = data;
	}
	//顺序表尾插
	void PushBack(T* array, int data) {
		CheckCapacity();
		array[++size] = data;
	}
	//顺序表头删
	void PopFront(T* array1) {
		delete array1[0];
		for (int i = array[size]; i > 0; --i) {
			array[i - 1] = array[i];
		}
	}
	//顺序表尾删
	T PopBack(T*array){
		delete array[size];
		return array[size--];
	}
	//任意位置删除
	void SeqListErase(T* array1, int pos)
	{
		delete array1[pos];
		for (int i =array1.size; i >pos+1; --i) {
			a[pos] = a[pos + 1];
		}
		delete array[size];
		array1.size--;
	}
	// 移除顺序表中第一个值为data的元素 
	void SeqListRemove(T* array, int data) {
		int j = 0;
		for (int i = 0; i < array.size; i++) {
			if (array[i] == data) {
				j = i;
				delete array[i];
				break;
			}
		}
		for (int i = array.size; i > j; i--) {
			array[i - 1] = array[i];
		}
		delete  array[size--];
	}
	// 移除顺序表中所有值为data的元素 
	void SeqListRemoveAll(T* array, DataType data) {
		for (int i = 0; i < array.size; i++) {
			if (array[i] == data) {
				delete array[i];
				array.size--;
			}
		}
	}
	// 获取顺序表有效元素个数 
	int SeqListSize(T*array) {
		return array.size;
	}
	// 获取顺序表的容量 
	int SeqListCapacity(T* array) {
		return array.capacity;
	}
	// 检测顺序表是否为空 
	int SeqListEmpty(T*array) {
		if (array == NULL) {
			return 1;
		}
		return 0;
	}
	// 获取顺序表中第一个元素 
	DataType SeqListFront(T*array) {
		if (array == NULL) { return NULL; }
		else {
			return array[0];
		}
	}
	// 获取顺序表中最后一个元素 
	DataType SeqListBack(T* array) {
		assert(array != NULL);
		return array[size];
		
	}

	~Seqlist() {
		if (array) {
			delete[] array;
			array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	T*array;
	size_t _capacity;
	size_t _size;
};
//在顺序表为index位置插入data
template<class T>
 Seqlist<T> PushSqlist(T*array1,int index,int data) {
	 if (array1._size >= array1.capacity) {
		 T* array2 = new []array1 * 2;//找到新家
		 for (int i = 0; i < array1.size; ++i) {
			 array2[i] = array1[i];//搬家
		 }
		 delete []array1;
		 array1 = array2;
	 }
	 for (int i = index; i < array1.size; ++i) {
		 array1[i + 1] = array1[i];
	 }
	 array1[index] = data;
	 return array1;
}
 //1. 什么是时间复杂度？
	// 2. 时间复杂度为什么看的是最差情况？
	 //3. 为什么时间复杂度看的是运行次数而不是运行时间？
	 //4. 一般算法的时间复杂度怎么求？
	 //5. 特殊算法：比如二分、递归等的时间复杂度度怎么求
	 //6. 什么是空间复杂度？空间复杂度度怎么求？
	 //7. 综合分析斐波那契算法的时间复杂度，并优化成最佳的方式
