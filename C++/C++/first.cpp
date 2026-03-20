#define _CRT_SECURE_NO_WARNINGS_1
#include <iostream>
using namespace std;

int a = 10; //全局变量

namespace peng 
{
	int a = 20; //命名空间变量
}

class C {	
	public:
	void man() {
		std::cout << "类函数" << std::endl;
	}
	
};

void A() {
	cout << "全局函数" << std::endl;
}

//运算符重载
bool operator == (const C& c1, const C& c2) {
	return true; //简单返回true，表示两个对象相等
}


//空类的大小为1字节
class man
{
public:
	man()
	{
		cout << "这是一个空类" << endl;
	}
	~man()
	{
		cout << "这是空类的析构函数" << endl;
	}
};

inline void inlineFunction() {
	cout << "这是一个内联函数" << endl;
}

int main() {
	int z = sizeof(man); //类对象占用的内存空间
	int& b = a; //引用
	int a = 30; //局部变量
	int h = 40; //局部变量	
	const int& c = h;
	cout << " 局部变量: " << "  " << &b << endl; //局部变量  30
	cout << " 命名空间: " <<"  "<< peng::a << endl; //命名空间  30
	cout <<" 这是全局变量 "<< ::a << endl; //全局变量  10
	cout << "常量引用: " << &c <<"  "<< & h << endl; //常量引用  40
	//引用的两个数是一样的，说明引用就是一个别名

	man m;
	int q = sizeof(m); //对象占用的内存空间
	cout << "对象占用的内存空间: " << q << " 字节" << endl; //对象占用的内存空间: 4 字节
	//空类的大小为1字节

	inlineFunction();
	return 0;
}