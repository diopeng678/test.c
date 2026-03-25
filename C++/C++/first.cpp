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

//模板函数 适用于不同类型的数据 但是同一个函数
template<class T>
void swwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
} 
//在实例化时 分为显式和隐式的方式
// 隐式就是直接写swap(a, b); 显式就是写swap<int>(a, b),相当于就是告诉编译器这个函数的类型是int类型的
//当同名函数与模板函数同时存在时，编译器会优先选择非模板函数进行调用
int swwap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
	return 0;
}

int main() {
	//int z = sizeof(man); //类对象占用的内存空间
	//int& b = a; //引用
	//int a = 30; //局部变量
	//int h = 40; //局部变量	
	//const int& c = h;
	//cout << " 局部变量: " << "  " << &b << endl; //局部变量  30
	//cout << " 命名空间: " <<"  "<< peng::a << endl; //命名空间  30
	//cout <<" 这是全局变量 "<< ::a << endl; //全局变量  10
	//cout << "常量引用: " << &c <<"  "<< & h << endl; //常量引用  40
	//引用的两个数是一样的，说明引用就是一个别名

	//man m;
	//int q = sizeof(m); //对象占用的内存空间
	//cout << "对象占用的内存空间: " << q << " 字节" << endl; //对象占用的内存空间: 4 字节
	//空类的大小为1字节
	//inlineFunction();
	int x = 5, y = 10;
	float lll = 1.5, b = 2.5;
	swwap(lll, b);
	return 0;
}