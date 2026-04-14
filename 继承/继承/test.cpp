#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class peng
{
public:		peng()
			{
				age = 18;
			}
			void eat()
			{
				cout << age << endl;
			}
			int print()	
			{
				cout << "peng ";
				return age;
			}
private:
	int age;
	string name;
};

class man:public peng
{
	public:
		void eat()
		{
			cout<< "man eat" << endl;
		}
		int print (int i)
		{
			cout << "man" << endl;
			return i;
		}

};

//下面是初始化列表
class kobe
{
public:
	kobe()
	{
		cout << "kobe" << endl;
	}

	kobe(int a , int b)
		: _age(a)
		, sex(b)
	{ }
	void print()
	{
		cout << "age: " << _age << " sex: " << sex << endl;
	}
	kobe(const kobe& k)
		: _age(k._age)
		, sex(k.sex)
	{ }
private:
	int _age = 18;
	int sex = 9;
};

class person
{
public:
	person(int a = 19, string n = "jiege", string s = "nan")
		: year(a)
		, name(n)
		, sex(s)
	{ }
	person(const person& p)
		: year(p.year)
		, name(p.name)
		, sex(p.sex)
	{ }
	void print()
	{
		cout << "year: " << year << " name: " << name << " sex: " << sex << endl;
	}

private:
	int year = 18;
	string name = "niao";
	string sex = "nan";
};

class student :public person
{
public:
	student(int a = 666, string n ="matou", string s = "jige", int num = 99, string add = "beijing")
		: person(a, n, s)
		, _num(num)
		, _add(add)
	{

	}
	
	student(const student& s)
		: person(s)
		, _num(s._num)
		, _add(s._add)
	{

	}
	void print()
	{
		person::print();
		cout << " num: " << _num << " add: " << _add << endl;
	}
private:
	int _num;
	string _add;
};

//下面是多继承 和 final关键字 final关键字用来防止类被继承 还有一种方式是用private修饰符来继承 但是final更直接一些 直接在类定义后面加上final就可以了
class ren //final
{
	public:
	ren()
	{
		cout << "ren" << endl;
	}
	void print()
	{
		cout << "ren age: " << age << " ren name: " << name << endl;
	}
private:
	int age = 77;
	string name = "周玉霞";
};

class ouo
{
	public:
	ouo()
	{
		cout << "ouo" << endl;
	}
private:
	int _age = 88;
	string _name = "位佳乐";
};

class diopeng :public ren, public ouo
{
	public:
	diopeng()
	{
		cout << "diopeng" << endl;
	}
	void print()	
	{
		cout << "diopeng age: " << _age<< " diopeng name: " << _name << endl;
	}
private:	
	int _age = 99;
	string _name = "王仕鹏";
};


int main() 
{
//		man m;
//		m.print(10);
//		m.peng::print();
//		m.peng::eat();
//		kobe k;
//		k.print();
//		kobe k1(20, 1);
//		k1.print();
//		kobe k2(999,777);
//		k2.print();
//		/*person p1(20, "shipeng", "nv");
//		person p2;
//		p2.print();*/
//
//		student s1(666, "matou", "mmmmmmm", 99, "beijing");
//		s1.print();

		diopeng d;
		d.print ();	
		d.ren::print();
		//在使用时要尽量避免二义性问题 
		//虽然可以设计出菱形继承的结构 但是在使用时会有二义性问题 需要通过作用域来解决 但是如果设计不合理 就会很麻烦 所以在设计时要尽量避免二义性问题
		return 0;
		
}
