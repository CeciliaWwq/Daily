#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<assert.h>
using namespace std;
//传统版写法
namespace wwq {
	class Mystring {
	public:typedef char* iterator;
	public:
		Mystring(const char* str = "") {
			if (str == nullptr) {
				assert(false);
				return;
			}
			_size = strlen(str);
			_capacity = _size + 1;
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		Mystring(const Mystring& s) :
			_str(new char[s._capacity + 1]),
			_size(s._size),
			_capacity(s._capacity)
		{
			strcpy(_str, s._str);
		}
		Mystring& operator=(const Mystring& s) {
			if (_str != s._str) {
				char* pstr = new char[strlen(s._str) + 1];
				strcpy(pstr, s._str);
				delete[] _str;
				_str = pstr;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}
		iterator begin() {
			return _str;
		}
		iterator end() {
			return _str + _size;
		}

		//modify
		void pushback(char c) {
			if (_size == _capacity) {
				if (_capacity = 0) { _capacity = 1; }
				Reserve(_capacity * 2);
			}
			_str[_size++] = c;
			_str[_size] = '/0';
		}
		void Reserve(size_t capacity)
		{
			if (capacity > _capacity) {
				char* pstr = new char[capacity + 1];
				strcpy(pstr, _str);
				delete[]_str;
				_str = pstr;
				_capacity = capacity;
			}
		}
		void Append(size_t n, char c) {
			while (n > 0) {
				pushback(c);
				n--;
			}
		}
		Mystring& operator+=(char c) {
			pushback(c);
			return *this;
		}
		void Append(const char* str) {
			size_t newcapacity = _size + strlen(str);
			if (_capacity <= newcapacity) {
				Reserve(newcapacity);
			}
			str = begin();
			while (str != end())
			{
				pushback(*str);
				_size++;
				str++;
			}
			_str[_size] = '/0';
			_capacity = newcapacity;
		}
		void resize(size_t newsize, char c) {
			if (newsize > _size) {
				if (newsize > _capacity) {
					Reserve(newsize);
				}
				memset(_str + _size, c, newsize - _size);
			}
			_size = newsize;
			_str[_size] = '/0';
		}
		char operator[](int index) {
			if (index < _size) {
				return _str[index];
			}
			return 0;
		}
		char operator[](int index)const
		{
			if (index < _size) {
				return _str[index];
			}
			return 0;
		}
		Mystring& operator+=(const char* str) {
			Append(str);
			return *this;
		}
		size_t Size()const
		{
			return _size;
		}

		size_t Capacity()const
		{
			return _capacity;
		}
		bool empty()const
		{
			return 0 == _size;
		}
		~Mystring() {
			if (_str != nullptr) {
				delete[] _str;
				_str = nullptr;
			}
		}
		bool operator<(const Mystring& s) {
			if (s._str == nullptr) {
				return 0;
			}
			int ret1 = s._str[0] - '0';
			int ret2 = _str[0] - '0';
			if (ret1 < ret2) {
				return true;
			}
			return false;
		}
		bool operator<=(const Mystring& s) {
			if (s._str == nullptr) {
				return 0;
			}
			int ret1 = s._str[0] - '0';
			int ret2 = _str[0] - '0';
			if (ret1 <= ret2) {
				return true;
			}
			return false;
		}
		bool operator>(const Mystring& s) {
			if (!operator<=(s)) { return true; }
			return false;
		}
		bool operator>=(const Mystring& s) {
			if (!operator<(s)) { return true; }
			return false;
		}
		bool operator==(const Mystring& s) {
			if (s._str == nullptr) {
				return 0;
			}
			int ret1 = s._str[0] - '0';
			int ret2 = _str[0] - '0';
			if (ret1 == ret2) {
				return true;
			}
			return false;
		}
		bool operator!=(const Mystring& s) {
			if (!operator==(s)) { return true; }
			return false;
		}
		// 返回c在string中第一次出现的位置 
		size_t Find(char c, size_t pos = 0) const
		{
			for (pos = 0; pos < _size; pos++) {
				if (_str[pos] == c) {
					return pos;
					break;
				}
			}
		}
		// 返回子串s在string中第一次出现的位置         
		size_t Find(const char* s, size_t pos = 0) const {
			size_t flag = 0;
			size_t lenth = strlen(s);
			if (lenth > _size) { return 0; }
			while (pos != _size) {
				size_t i = 0;
				if (s[i] == _str[pos]) {
					flag = _str[pos];
					while (s[i] == _str[pos]) {
						i++;
						pos++;
					}
					if (s[i] == '/0') { return flag; break; }
				}
				pos++;
			}
			return 0;
		}

		// 截取string从pos位置开始的n个字符        
		Mystring SubStr(size_t pos, size_t n) {
			size_t i = 0;
			size_t j = 0;
			Mystring s;
			for (i = pos; i < pos + n; i++) {
				for (j = 0; j < n; j++) {
					s._str[j] = _str[i];
				}
			}
			return s;
		}

		// 在pos位置上插入字符c/字符串str，并返回该字符的位置        
		Mystring& Insert(size_t pos, char c) {
			if (_size == _capacity) {
				Reserve(_capacity + 1);
			}
			for (size_t i = _size; i > pos; --i) {
				_str[i + 1] = _str[i];
			}
			_str[pos] = c;
			_str[_size] = '/0';
		}
		Mystring& Insert(size_t pos, const char* str)
		{
			size_t lenth = strlen(str);
			size_t newcapacity = _size + lenth;
			if (_capacity < newcapacity) {
				Reserve(newcapacity);
			}
			for (size_t i = _size; i > pos; --i) {
				_str[i + lenth] = _str[i];
			}
			for (size_t j; j < lenth; ++j) {
				for (size_t x = pos; x < pos + lenth; ++x)
				{
					_str[x] = str[j];
				}
			}
			return *this;
		}
		 
		// 删除pos位置上的元素，并返回该元素的下一个位置        
		Mystring& Erase(size_t pos, size_t len) {
			assert(pos);
			if (pos + len >= _size) {
				_size = pos;
				_str[_size] = '\0';
			}
			else {
				for (size_t i = pos + len; i < _size; ++i) {
					_str[pos++] = _str[i];
				}
				_size -= len;
				_str[_size] = '\0';
			}
		}
	/*
		ostream& operatorm<<(ostream& out, const Mystring& s) {
			for (auto ch : s) {
				out << ch;
			}
			return out;
		}
		*/


	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

}

int main()
{
	wwq::Mystring s("hello");
	s.Insert(2, "e");

}
	
#if 0
//现代版写法
class NMystring {
	NMystring(const char*str="") {
		if (str == nullptr) {
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	/*
	NMystring(NMystring&s):
	_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}
	*/
	//现代写法比起传统写法更节省空间资源
	NMystring(NMystring& s):
	_str(nullptr)
	{
		NMystring tempstr(s._str);
	    std::swap(_str, tempstr._str);
	}
	NMystring& operator=(NMystring s) {
		
		std::swap(_str, s._str);
		return *this;
	}
	~NMystring()
	{
		if (_str != nullptr) {
			delete[] _str;
			_str = nullptr;
		}

	}
private:
	char* _str;
};
#endif
