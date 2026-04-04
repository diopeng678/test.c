//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//using namespace std;

//int main()
//{
//	vector <int> man(4,100);
//	for (vector<int>::iterator it = man.begin();it != man.end() ; it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	man.push_back(1999);
//	for (vector<int>::iterator it = man.begin();it != man.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	man.pop_back();
//	for (vector<int>::iterator it = man.begin();it != man.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	vector <int> men(4, 666);
//	cout << endl;
//	/*swap(man, men);*/
//	for (vector<int>::iterator it = men.begin();it != men.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	erase可以传入的参数   •	可用的重载功能仍与erase(const_iterator pos)和erase(const_iterator first, const_iterator last)相同。
//	/*  •	单个元素：iterator erase(const_iterator pos) —— 擦除 pos 指向的元素。
//		•	范围：iterator erase(const_iterator first, const_iterator last) —— 擦除区间[first, last)。
//		•	参数类型
//		•	必须是同一 vector 的（const_)iterator，不能直接传下标（不能写 v.erase(2)，要用 v.begin() + 2）。
//		•	返回值
//		•	返回指向被擦除位置之后元素的迭代器（等价于传入的 last；若到末尾则返回 end()）。
//		•	复杂度与迭代器失效
//		•	需要移动后续元素以填补空位，时间复杂度为 O(n)（n 为被移动元素数）。
//		•	擦除点之后的所有迭代器和引用会失效（包括 end()）；擦除前的迭代器在被移走的元素之前的部分仍然有效，但通常不要依赖。*/
//	men.erase(men.begin());
//	men.erase(men.begin() + 1);
//	cout << endl;
//	for (vector<int>::iterator it = men.begin();it != men.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	return 0;
//
//}

#include <iostream>
using namespace std;
#include <vector>
//int main()
//{
//	vector<int> v{ 1, 2, 3, 4 };
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			v.erase(it);
//		++it;
//	}
//	return 0;
//}
//这一段代码的作用是删除v中所有偶数，并返回一个新的vector。
//但是，这段代码有个问题，就是删除元素后，迭代器it指向的元素已经被删除，所以下一次循环时，it会指向下一个元素，导致程序出错。
int main()
{
	vector<int> v{ 1, 2, 2, 3, 4,8 };
	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}
	for (auto x : v)
		cout << x << " ";
	return 0;
}
//这段代码的作用是删除v中所有偶数，并返回一个新的vector。
//这段代码的正确之处在于，在删除元素后，it被更新为 erase() 返回的迭代器，所以下一次循环时，it仍然指向下一个元素，不会出错。
