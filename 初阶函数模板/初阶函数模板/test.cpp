#define _CRT_SECURE_NO_WARNINGS
#include <iostream>	

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}


//用类模板实现stack
template<typename T>
class Stack
{
public:
	Stack(int n = 4)
		:_array(new T[n])
		,_size(0)
		,_capacity(n)
	{}

	~Stack()
	{
		delete[] _array;
		_array = nullptr;
		_size = _capacity = 0;
	}

	void Push(const T& x)
	{

		if (_size == _capacity)
		{
			T* tmp = new T[_capacity * 2];
			memcpy(tmp, _array, sizeof(T) * _size);
			delete[] _array;

			_array = tmp;
			_capacity *= 2;
		}

		_array[_size++] = x;
	}
	void Print()
	{
		for (size_t i = 0; i < _size; ++i)
		{
			std::cout << _array[i] << " ";
		}
		std::cout << std::endl;
	}

private:
	T* _array;
	size_t _capacity;
	size_t _size;
};


int main()
{
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	Add(a1, a2);
	Add(d1, d2);
	Add((int)d1, a2); //不同类型需要进行强转

	// 类模板都是显示实例化
	Stack<int> st1; 
	st1.Push(1);
	st1.Push(2);
	st1.Push(3);
	st1.Print();


	Stack<double> st2;//显式调用
	st2.Push(1.39);
	st2.Push(1.47);
	st2.Push(1.89);
	st2.Print();

	Stack<double>* pst = new Stack<double>;
	delete pst;

	/*
	该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
	通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有
	一个T，
	编译器无法确定此处到底该将T确定为int 或者 double类型而报错
	Add(a1, d1);
	*/
	/*注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅*/
		// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化

	return 0;
}
