#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class A
{
public:
	A(int a1 = 0, int a2 = 0)
		:_a1(a1)
		, _a2(a2)
	{
		cout << "A(int a1 = 0, int a2 = 0)" << endl;
	}

	A(const A& aa)
		:_a1(aa._a1)
	{
		cout << "A(const A& aa)" << endl;
	}

	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a1 = aa._a1;
		}
		return *this;
	}

	~A()
	{
		//delete _ptr;
		cout << "~A()" << endl;
	}

	void Print()
	{
		cout << "A::Print->" << _a1 << endl;
	}

	A& operator++()
	{
		_a1 += 100;

		return *this;
	}
private:
	int _a1 = 1;
	int _a2 = 1;
};

//int main()
//{
//	A aa1 = 1;
//	const A& aa2 = 1;
//
//	return 0;
//}

//void f1(A aa)
//{}
//
//int main()
//{
//	A aa1(1);
//	f1(aa1);
//	cout << endl;
//
//	// Ż
//	f1(A(1));
//	cout << endl;
//
//	// Ż
//	f1(1);
//	cout << endl;
// 
//	return 0;
//}

//A f2()
//{
//	A aa(1);
//	++aa;
//
//	return aa;
//}
//
//int main()
//{
//	f2().Print();
//	cout <<"*********"<< endl << endl;
//
//	return 0;
//}

//A f2()
//{
//	A aa(1);
//	++aa;
//
//	return aa;
//}
//
//int main()
//{
//	A ret = f2();
//	ret.Print();
//	cout << "*********" << endl << endl;
//
//	return 0;
//}

//A f2()
//{
//	A aa(1);
//	++aa;
//	cout << "##########" << endl;
//	return aa;
//}
//
//int main()
//{
//	A ret;
//	ret = f2();
//	ret.Print();
//	cout << "*********" << endl << endl;
//
//	return 0;
//}

//int main()
//{
//	int* p1 = new int;
//	int* p2 = new int[10];
//
//	delete p1;
//	delete[] p2;
//
//	// +ʼ
//	int* p3 = new int(0);
//	int* p4 = new int[10]{ 0 };
//	int* p5 = new int[10]{1,2,3,4,5};
//
//	delete p3;
//	delete[] p4;
//	delete[] p5;
//
//	return 0;
//}

struct ListNode
{
	int val;
	ListNode* next;

	ListNode(int x)
		:val(x)
		, next(nullptr)
	{
	}
};

//int main()
//{
//	A* p1 = new A;
//	A* p2 = new A(1);
//
//	delete p1;
//	delete p2;
//
//	ListNode* n1 = new ListNode(1);
//	ListNode* n2 = new ListNode(1);
//	ListNode* n3 = new ListNode(1);
//	ListNode* n4 = new ListNode(1);
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//
//	return 0;
//}

//int main()
//{
//	A* p1 = new A(1);
//	A* p2 = new A(2,2);
//
//	A aa1(1, 1);
//	A aa2(2, 2);
//	A aa3(3, 3);
//	A* p3 = new A[3]{aa1, aa2, aa3};
//
//	A* p4 = new A[3]{ A(1,1), A(2,2), A(3,3)};
//
//	//A aa1 = { 1, 1 };
//	A* p5 = new A[3]{ {1,1}, {2,2}, {3,3} };
//
//	return 0;
//}

// 1M Լ 100wByte
// 1G Լ 10Byte
//int main()
//{
//	try
//	{
//		// throw try/catch 
//		void* p1 = new char[1024 * 1024 * 1024];
//		cout << p1 << endl;
//
//		void* p2 = new char[1024 * 1024 * 1024];
//		cout << p2 << endl;
//
//		void* p3 = new char[1024 * 1024 * 1024];
//		cout << p3 << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

// 1G = 1024MB = 1024*1024KB = 1024*1024*1024Byte

//void func()
//{
//	// throw try/catch 
//	int n = 1;
//	while (1)
//	{
//		void* p1 = new char[1024 * 1024];
//		cout << p1 << "->"<< n<<endl;
//		++n;
//	}
//}
//
//int main()
//{
//	try
//	{
//		func();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	A* p1 = new A(1);
//	delete p1;
//
//	A* p2 = new A[5];
//	delete[] p2;
//
//	return 0;
//}

int main()
{
	int* p1 = new int;
	free(p1);
	//delete p1;

	A* p2 = new A;
	//free(p2);
	delete p2;

	return 0;
}

class B
{
public:
	~B()
	{
		cout << "~B()" << endl;
	}
private:
	int _b1 = 2;
	int _b2 = 2;
};

//int main()
//{
//	int* p1 = new int[10]; // -> malloc
//	delete p1;             // -> free
//	free(p1);
//
//	B* p2 = new B[10];
//	delete p2;
//
//	A* p3 = new A[10];
//	delete[] p3;
//
//	return 0;
//}


//new在使用时必须与delete配对使用，new[]必须与delete[]配对使用，否则会导致内存泄漏或者程序崩溃等问题。
// 在使用new分配内存时，编译器会调用相应的构造函数来初始化对象，而delete会调用相应的析构函数来销毁对象。
// 如果使用了错误的delete操作符，可能会导致析构函数没有被正确调用，从而引发资源泄漏或者未定义行为。
//new在本质上是一个运算符，它会调用相应的内存分配函数（如malloc）来分配内存，并且会调用相应的构造函数来初始化对象。
// delete也是一个运算符，它会调用相应的析构函数来销毁对象，并且会调用相应的内存释放函数（如free）来释放内存。
// 因此，正确使用new和delete是非常重要的，以确保程序的稳定性和性能...


