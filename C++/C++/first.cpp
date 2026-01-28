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
	//输入输出
	cin >> man::a;
	cout << "Hello, World!" << endl;
	cout << man::a << endl;
	cout << man::peng::b << endl;
	//c++中的是不需要写元素的类型的
	return 0;

}