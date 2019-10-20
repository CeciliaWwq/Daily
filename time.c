 once
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);
	Date& operator=(const Date& d);
	Date operator+(int days);
		Date operator-(int days);
	int operator-(const Date& d);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
	int GetMonthDay(int year, int month);
	Date& operator+=(int days);
	Date& operator-=(int days);
	int JudgeYearDay(Date &d);
private:
	int _year;
	int _month;
	int _day;
};
#include<iostream>
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator =(const Date& d){   
		if (this != &d) {
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}
	~Date()
	{}
	int GetMonthDay(int year, int month) {
		int montharray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && year % 4 == 0 && year % 100 != 0 || year % 400 == 0) { montharray[2] = 29; }
		return montharray[month];
	}
	Date operator+(int days) {
		int ret = this->_day + days;
		if (ret > GetMonthDay(this->_year, this->_month)) {
			while (ret > GetMonthDay(this->_year, this->_month)) {
				ret -= GetMonthDay(this->_year, this->_month);
				this->_month++;
				if (this->_month > 12) {
					this->_month = 1;
					this->_year++;
				}
			}
		}
	}
	Date operator-(int days) {
		int ret = this->_day - days;
		if (ret <0) {
			while (ret <0) {
				this->_month--;
				ret += GetMonthDay(this->_year, this->_month);
				if (this->_month == 0) {
					this->_month = 12;
					this->_year--;
			}
			}
		}
	}
	Date& operator-=(int days) {
		Date ret = operator-(days);
		return ret;
	}

	Date& operator+=(int days) {
		Date ret=  operator+(days);
		return ret;
	}
	Date& operator++() {
		*this += 1;
		return *this;//后置++返回的是加之后的值
	}
	Date operator++(int)
	{
		Date tmp = *this;
		*this += 1;
		return tmp;//前置++返回的是加之前的值
	}
	Date& operator--() {
		*this -= 1;
		return *this;//后置++返回的是加之后的值
	}
	Date operator--(int)
	{
		Date tmp = *this;
		*this -= 1;
		return tmp;//前置++返回的是加之前的值
	}
	int JudgeYearDay(const Date& d) {
		int count = 0;
		int month = 1;
		while (month <d._month) {
			count += GetMonthDay(d._year, d._month);
			month++;
		}
		count += d._day;
		return count;
		
	}
	int operator-(const Date& d) {
		int count1 = 0;
		int count2 = 0;
		int year2 = this->_year - 1;
		int year1 = d._year-1;
		while (year1>= 1900) {
			if( year1 % 4 == 0 && year1 % 100 != 0 || year1 % 400 == 0)
			{
				count1++;
			}
			year1--;
		}
		while (year1 >= 1900) {
			if (year2 % 4 == 0 && year2 % 100 != 0 || year2 % 400 == 0)
			{
				count2++;
			}
			year1--;
		}
		int spdays1 = JudgeYearDay(d);
		int spdays2 = JudgeYearDay(*this);
		count1 += spdays1;
		count2 += spdays2;
		int ret = 0;
		if (count1 > count2) { ret = count1 - count2; }
		else { ret = count2 - count1; }
		return ret;
	}
	bool operator>(const Date& d)const {
		if (d._year != this->_year) {
			if (d._year > this->_year) { return false; }
		}
		if (d._year == this->_year) {
			if (d._month >this->_month) { return false; }
		}
		if (d._year == this->_year && d._month == this->_month) {
			if (d._day > this->_day) { return false; }
		}
		if (d._year == this->_year && d._month == this->_month && d._day == this->_day) { return false; }
		else { return true; }
	}
	bool operator<(const Date& d)const {
		if (d._year != this->_year) {
			if (d._year > this->_year) { return true; }
		}
		if (d._year == this->_year) {
			if (d._month > this->_month) { return true; }
		}
		if (d._year == this->_year && d._month == this->_month) {
			if (d._day > this->_day) { return true; }
		}
		if (d._year == this->_year && d._month == this->_month && d._day == this->_day) { return false; }
		else { return false; }
	}
	bool operator>=(const Date& d)const {
		if (d._year != this->_year) {
			if (d._year > this->_year) { return false; }
		}
		if (d._year == this->_year) {
			if (d._month > this->_month) { return false; }
		}
		if (d._year == this->_year && d._month == this->_month) {
			if (d._day > this->_day) { return false; }
		}
		else { return true; }
	}
	bool operator<=(const Date& d)const {
		if (!operator>(d)) { return true; }
		return false;
	}
private:
	int _year;
	int _month;
	int _day;
};

