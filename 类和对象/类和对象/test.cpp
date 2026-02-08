#define _CRT_SECURE_NO_WARNINGS_1

#include <iostream>
using namespace std;

class Data
{	public:
	void init(char a, char b,int c)
	{	x = a;
		y = b;
		v = c;
	}
	void show()
	{	cout << x << " " << y << endl;
	}

private:
	char x, y;
	int v;

};


int main()
{	
	//这是根据内存对齐原则
	//最后取最大对齐数的整数倍

	cout << "sizeof(Data) = " << sizeof(Data) << endl;
	return 0;
}
