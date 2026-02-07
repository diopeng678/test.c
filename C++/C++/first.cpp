#define _CRT_SECURE_NO_WARNINGS_1

#include <iostream>
//C++的第一个代码
//命名空间
using namespace std;
namespace man {
	int a = 10;
	//这个是可以写成嵌套形式的
	namespace peng {
		int b = 20;
	}
}

int main() {
	////输入输出
	//cin >> man::a;
	//cout << "Hello, World!" << endl;
	//cout << man::a << endl;
	//cout << man::peng::b << endl;
	////c++中的是不需要写元素的类型的
	//return 0;

	//关于引用的使用
	int a = 10;
	int& b = a; //b是a的引用
	cout << a << endl; //10
	//还有一项规则：引用必须初始化，且一旦初始化后就不能再绑定到其他对象上了。
	//权限不能在使用时变大
	const int c = 20;
	const int& d = c; //d是c的引用
	//int& d = a; //错误  权限被放大了
	
	int j = 40;
	//int& v = j + c;这样写是错误的，因为j + c是一个临时对象具有常性

	const int& v = j + c; //这样写是正确的，因为v是一个常量引用，可以绑定到临时对象上
	cout << v << endl; //70
	                
	//
	   
}