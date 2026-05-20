#include<iostream>

using namespace std;

int main() {
	int a = 1, b = 2, c = 3;

	// 值捕捉：不能修改
	auto f1 = [a, b] { return a + b; };

	// 引用捕捉：可以修改
	auto f2 = [&a, &b] { a++; b++; };

	// 隐式值捕捉
	auto f3 = [=] { return a + b + c; };

	// 隐式引用捕捉
	auto f4 = [&] { a++; b++; c++; };

	// 混合：其他值捕捉，a 引用捕捉
	auto f5 = [=, &a] { a++; return b + c; };
	//捕捉方式	语法	说明
	//	值捕捉[x, y]	拷贝，不可修改
	//	引用捕捉[&x, &y]	引用，可修改
	//	隐式值捕捉[=]	自动值捕捉用到的变量
	//	隐式引用捕捉[&]	自动引用捕捉用到的变量
	//	混合捕捉[=, &x]	除 x 外都值捕捉
	//	混合捕捉[&, x]	除 x 外都引用捕捉

	int j = f3();

	cout << "f3" << " = " << j << endl;

	
		// 最简单的 lambda
		auto func1 = [] { cout << "hello" << endl; };
		func1();

		// 带参数和返回值
		auto add = [](int x, int y) -> int { return x + y; };
		cout << add(1, 2) << endl;

		// 自动推导返回值
		auto mul = [](int x, int y) { return x * y; };

		// 交换两个数
		int m = 1, d = 2;
		auto swap1 = [](int& x, int& y) {
		int tmp = x;
		x = y;
		y = tmp;
		};

		swap1(m, d);
		cout << m << "  " << d;
		


	return 0;
}	