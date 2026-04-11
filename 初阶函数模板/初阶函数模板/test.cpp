#define _CRT_SECURE_NO_WARNINGS
#include <iostream>	
#include <vector>

using namespace std;

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


//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//	Add((int)d1, a2); //不同类型需要进行强转
//
//	// 类模板都是显示实例化
//	Stack<int> st1; 
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(3);
//	st1.Print();
//
//
//	Stack<double> st2;//显式调用
//	st2.Push(1.39);
//	st2.Push(1.47);
//	st2.Push(1.89);
//	st2.Print();
//
//	Stack<double>* pst = new Stack<double>;
//	delete pst;
//
//	/*
//	该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
//	通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有
//	一个T，
//	编译器无法确定此处到底该将T确定为int 或者 double类型而报错
//	Add(a1, d1);
//	*/
//	/*注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅*/
//		// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
//
//	return 0;
//}

template<class T>
class Less
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};

// 特化
//template<>
//class Less<Date*>
//{
//public:
//	bool operator()(Date* const & x, Date* const& y)
//	{
//		return *x < *y;
//	}
//};

template<class T>
class Less<T*>
{
public:
	bool operator()(T* const& x, T* const& y)
	{
		return *x < *y;
	}
};

template<class T>
class Greater
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};

//函数模板的进阶
//1. 偏特化
namespace man
{
	// 默认是大堆
	template<class T, class Container = vector<T>, class Compare = Less<T>>
	class priority_queue
	{
	public:
		void AdjustUp(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[parent] < _con[child])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);

			AdjustUp(_con.size() - 1);
		}

		void AdjustDown(int parent)
		{
			// 先假设左孩子小
			size_t child = parent * 2 + 1;

			Compare com;
			while (child < _con.size())  // child >= n说明孩子不存在，调整到叶子了
			{
				// 找出小的那个孩子
				//if (child + 1 < _con.size() && _con[child] < _con[child + 1])
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					++child;
				}

				//if (_con[parent] < _con[child])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		const T& top()
		{
			return _con[0];
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}

	private:
		Container _con;
	};
}

int main()
{
	man::priority_queue<int, vector<int>, Less<int>> pq;
	pq.push(99);
	pq.push(666);
	pq.push(345);
	pq.push(123);
	pq.push(789);
	pq.push(456);
	pq.push(234);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	return 0;
}