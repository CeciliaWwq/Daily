#define _CRT_SECURE_NO WARNINGS 1
#include<iostream>
template<typename T>
class Seqlist {
public:
	Seqlist()://���ù��캯�������ٿռ�
		array(new T[10]),
		capacity(10),
		size(0)
	{}
	Seqlist(T* array1, size_t size) :
		array(new T[size]),
		capacity(size),
		_size(size)
	{
		//memcpy(array, array1, sizeof(T)*_size);����
		for (int i = 0; i < size; ++i) {
			array[i] = array1[i];
		}
	}
	Seqlist(const Seqlist& s) ://����һ��˳���
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
			T* array2 = new[]array1 * 2;//�ҵ��¼�
			for (int i = 0; i < array1.size; ++i) {
				array2[i] = array1[i];//���
			}
			delete[]array1;
			array1 = array2;
		}
	}
	//˳���ͷ��
	void PushFront(T* array1,int data) {
		CheckCapacity();
		for (int i = 0; i < array1._size; ++i) {
			array[i + 1]=array1[i];
		}
		array1[0] = data;
	}
	//˳���β��
	void PushBack(T* array, int data) {
		CheckCapacity();
		array[++size] = data;
	}
	//˳���ͷɾ
	void PopFront(T* array1) {
		delete array1[0];
		for (int i = array[size]; i > 0; --i) {
			array[i - 1] = array[i];
		}
	}
	//˳���βɾ
	T PopBack(T*array){
		delete array[size];
		return array[size--];
	}
	//����λ��ɾ��
	void SeqListErase(T* array1, int pos)
	{
		delete array1[pos];
		for (int i =array1.size; i >pos+1; --i) {
			a[pos] = a[pos + 1];
		}
		delete array[size];
		array1.size--;
	}
	// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
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
	// �Ƴ�˳���������ֵΪdata��Ԫ�� 
	void SeqListRemoveAll(T* array, DataType data) {
		for (int i = 0; i < array.size; i++) {
			if (array[i] == data) {
				delete array[i];
				array.size--;
			}
		}
	}
	// ��ȡ˳�����ЧԪ�ظ��� 
	int SeqListSize(T*array) {
		return array.size;
	}
	// ��ȡ˳�������� 
	int SeqListCapacity(T* array) {
		return array.capacity;
	}
	// ���˳����Ƿ�Ϊ�� 
	int SeqListEmpty(T*array) {
		if (array == NULL) {
			return 1;
		}
		return 0;
	}
	// ��ȡ˳����е�һ��Ԫ�� 
	DataType SeqListFront(T*array) {
		if (array == NULL) { return NULL; }
		else {
			return array[0];
		}
	}
	// ��ȡ˳��������һ��Ԫ�� 
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
//��˳���Ϊindexλ�ò���data
template<class T>
 Seqlist<T> PushSqlist(T*array1,int index,int data) {
	 if (array1._size >= array1.capacity) {
		 T* array2 = new []array1 * 2;//�ҵ��¼�
		 for (int i = 0; i < array1.size; ++i) {
			 array2[i] = array1[i];//���
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
 //1. ʲô��ʱ�临�Ӷȣ�
	// 2. ʱ�临�Ӷ�Ϊʲô��������������
	 //3. Ϊʲôʱ�临�Ӷȿ��������д�������������ʱ�䣿
	 //4. һ���㷨��ʱ�临�Ӷ���ô��
	 //5. �����㷨��������֡��ݹ�ȵ�ʱ�临�Ӷȶ���ô��
	 //6. ʲô�ǿռ临�Ӷȣ��ռ临�Ӷȶ���ô��
	 //7. �ۺϷ���쳲������㷨��ʱ�临�Ӷȣ����Ż�����ѵķ�ʽ
