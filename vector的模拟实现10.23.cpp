#define _CRT_SECURE_NO WARNINGS 1
#include<iostream>
namespace wwq
{
	template<class T>
	class Myvector {
		typedef T* Iterator;        
		typedef const T* ConstIterator;

		Iterator Begin() { return _start; }        
		Iterator End() { return _finish; }

		ConstIterator CBegin() const { return _start; }        
		ConstIterator CEnd() const { return _finish; }

		size_t Size() const { return _finish - _start; }        
		size_t Capacity() const { return _endOfStorage - _start; }

		Vector() :
			_start = nullptr;
		_finish = nullptr;
		_endOfStorage = nullptr;
		{}
		Vector(int n, const T& value = T()) :
			_start = nullptr;
		_finish = nullptr;
		_endOfStorage = nullptr;
		{
			Reserve(n);
			for (size_t i; i < n; ++i) {
				_start[i] = value;
			}
			
		}

		template<class InputIterator>        
		Vector(InputIterator first, InputIterator last) {
			Reserve(last - first);
			while (first != last) {
				PushBack(*first);
				++first;
			}
		}
		Vector(const Vector<T>& v) :
			_start(nullptr);
		_finish(nullptr);
		_endOfStorage(nullptr)
	    {
			Iterator it = begin();
			constiterator cit = v.cbegin();
			while (cit != v.cend()) {
				*it++ = *cit++;
			}
			_finsh = _start + v.Size();
			_endOfStorage = _start + v.Capacity();
		}
		Vector<T>& operator= (Vector<T> v) {
			swap(v);
			retuen* this;
		}
		~Vector() {
			delete[] _start;
			_start = _finsh = _endOfStorage = nullptr;
		}
		void Reserve(size_t n) {
			if (n > Capacity()) {
				size_t size = Size();
				T* tmp = new T[n];
				if (_start) {
					for (size_t i = 0; i < size; i++) {
						tmp[i] = _start[i];
					}
				}
			}
			_start = tmp;
			_finish = _start + size;
			_endOfStorage = _start + n;
		
		}
		void Resize(size_t n, const T& value = T()) {
			if (n > Size()) {
				if (n > Capacity()) {
					Reserved(n);
				}
				for (size_t i = _start + Size(); i < n; ++i) {
					_start[i] = value;
				}
			}
			if (n <= Size()) {
				_finish=_start + n;
				return;
			}
		}
		void Swap(Vector<T>& v) {
			swap(_start, v._start);
			swap(_end，v.end);
			swap(_endOfStorage, v.endOdStorage);

		}
		void PushBack(const T& x) {
			Insert(_finish,x);
		}
		void PopBack()
		{
			Erase(--End());
		}
		Iterator Insert(Iterator pos, const T& x) {
			size_t n = pos - begin();
			asssert(pos < _finsh);
			if (_finish==_endOfStorage) {
				size_t newcapacity = Capacity == 0 ? 1 : Capacity * 2;
				Reserve(newcapacity);
				pos = _start + n;
			}
			iterator end = _finish - 1;
			while (end>=pos)
			{
				*(end + 1) = *end;
			}
			*pos = x;
			_finish++;
			return pos;
		}
		Iterator Erase(Iterator pos) {
			iterator begin = pos+1;
			while (begin<_finish)
			{
				*(begin-1) = *begin;
			}
			_finish--;
			return pos;
		}
		T& operator[](size_t pos) {
			return _start + pos;
		}

	private:        
		Iterator _start;        // 指向数据块的开始        
					
		Iterator _finish;       // 指向有效数据的尾        
				
		Iterator _endOfStorage; // 指向存储容量的尾 
	

	};
}