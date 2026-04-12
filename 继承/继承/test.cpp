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

int main() 
{
		man m;
		m.print(10);
		m.peng::print();
		m.peng::eat();
		kobe k;
		k.print();
		kobe k1(20, 1);
		k1.print();
		kobe k2(999,777);
		k2.print();
		return 0;
		
}
