#define _CRT_SECURE_NO_WARNINGS
#include"date.h"

bool Date::Checkdate() const
{
	if(_month < 1 || _month > 12 || _day < 1 || _day > GetMonthDay(_year ,_month ))
	{
		return false;
	}
	else
	{
		return true;
	}
}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
	if(! Checkdate())
	{
		cout << "日期错误 !" << endl;
		Print();
	}
}

//Date::Date(int year, int month, int day)
//{
//	_year = year;
//	_month = month;
//	_day = day;
//}

void Date::Print() const
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

bool Date::operator < (const Date& d) const
{
	if(_year < d._year)
	{
		return true;
	}
	else if(_year == d._year && _month < d._month)
	{
		return true;
	}
	else if(_year == d._year && _month == d._month && _day < d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator <= (const Date& d) const
{
	return *this < d || *this == d;
}

bool Date::operator > (const Date& d) const
{
	return !(*this <= d);
}

bool Date::operator >= (const Date& d) const
{
	return !(*this < d);
}

bool Date::operator == (const Date& d) const
{
	return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator != (const Date& d) const
{
	return !(*this == d);
}

Date& Date::operator+=(int day) 
{
	if(day < 0)
	{
		return *this -= (-day);
	}

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}

	return *this;
}

// d1 + 100
//Date Date::operator+(int day) const
//{
//	Date tmp = *this;
//
//	tmp += day;
//	/*tmp._day += day;
//	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//	{
//		tmp._day -= GetMonthDay(tmp._year, tmp._month);
//		++tmp._month;
//		if (tmp._month == 13)
//		{
//			tmp._year++;
//			tmp._month = 1;
//		}
//	}*/
//
//	return tmp;
//}


Date Date::operator+(int day) const
{
	Date tmp = *this;
	tmp += day;
	return tmp;
}

Date Date::operator-(int day) const
{
	Date tmp = *this;
	tmp += (-day);
	return tmp;
}

Date & Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if(_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}


Date Date::operator++ (int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}

Date Date::operator++ ()
{
	*this += 1;
	return *this;
}

int Date ::operator- (const Date& d) const
{
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (*this < d)
	{
		max = d;
		flag = -1;
		min = *this;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return flag * n;
}

//<< 是从左到右匹配的 
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	while (1)
	{
		cout<< "请输入日期 (年 月 日): ";
		in >> d._year >> d._month >> d._day;
		if(!d.Checkdate())
		{
			cout << "日期错误，请重新输入!" << endl;
		}
		else
		{
			break;
		}
	}
	in >> d._year >> d._month >> d._day;

	return in;
}