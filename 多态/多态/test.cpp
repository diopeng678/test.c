#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Animal 
{
public:
		virtual void speak() {
		cout << "Animal speaks" << endl;
	}
};

class Dog : public Animal 
{
public:
	void speak() {
		cout << "Dog speaks" << endl;
	}
};

class Cat : public Animal 
{
public:
	void speak() override//是对多态函数的重写，编译器会检查函数签名是否匹配，如果不匹配会报错
	{
		cout << "Cat speaks" << endl;
	}
};

void func(Animal* animal) 
{
	animal->speak();
}

class A
{
	public:
	virtual void func(int a = 1) {
		cout << "A->" <<a<< endl;
	}
	virtual void test() {
		func();
	}
};

class B : public A
{
	public:
	void func(int a = 0) {
		cout << "B->" << a << endl;
	}
};

//析构函数的重写
class C
{
	public:
	virtual ~C() {
		cout << "C的析构函数" << endl;
	}
};

class D : public C
{
	public:
	~ D() {
		cout << "D的析构函数" << endl;//如果不定义D的析构函数 ,就只会调用C的析构函数,而不会调用D的析构函数,可能会导致资源泄漏等问题
	}
private:
	int a[99];
};

int main() {
	D* d = new D();
	delete d;
	return 0;
}	
//P->test()调用的是A类中的test()（因为B没有重写test()）。
//test()内部调用func()时，由于func是虚函数，会根据对象的实际类型（B）调用B::func。
//但默认参数的绑定是在编译阶段确定的，test()在A类中定义，所以默认参数使用A::func的a = 1。
//所以最终输出：B->1

//int main() {
//	Animal* animal1 = new Dog();
//	Animal * animal2 = new Cat();
//
//	animal1->speak();
//	animal2->speak();
//
//	delete animal1;
//	delete animal2;
//
//	Cat cat;
//	func(&cat);
//
//	return 0;
//}