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

int main() {
	int a = 30; //局部变量
	cout << " 命名空间: " <<"  "<< peng::a << endl; //命名空间  30
	cout <<" 这是全局变量 "<< ::a << endl; //全局变量  10
	return 0;
}