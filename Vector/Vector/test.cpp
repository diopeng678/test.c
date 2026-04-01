#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector <int> man(4,100);
	for (vector<int>::iterator it = man.begin();it != man.end() ; it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	man.push_back(1999);
	for (vector<int>::iterator it = man.begin();it != man.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	man.pop_back();
	for (vector<int>::iterator it = man.begin();it != man.end(); it++)
	{
		cout << *it << " ";
	}
	vector <int> men(4, 666);
	cout << endl;
	/*swap(man, men);*/
	for (vector<int>::iterator it = men.begin();it != men.end(); it++)
	{
		cout << *it << " ";
	}
	//erase可以传入的参数   •	可用的重载功能仍与erase(const_iterator pos)和erase(const_iterator first, const_iterator last)相同。
	/*  •	单个元素：iterator erase(const_iterator pos) —— 擦除 pos 指向的元素。
		•	范围：iterator erase(const_iterator first, const_iterator last) —— 擦除区间[first, last)。
		•	参数类型
		•	必须是同一 vector 的（const_)iterator，不能直接传下标（不能写 v.erase(2)，要用 v.begin() + 2）。
		•	返回值
		•	返回指向被擦除位置之后元素的迭代器（等价于传入的 last；若到末尾则返回 end()）。
		•	复杂度与迭代器失效
		•	需要移动后续元素以填补空位，时间复杂度为 O(n)（n 为被移动元素数）。
		•	擦除点之后的所有迭代器和引用会失效（包括 end()）；擦除前的迭代器在被移走的元素之前的部分仍然有效，但通常不要依赖。*/
	men.erase(men.begin());
	men.erase(men.begin() + 1);
	cout << endl;
	for (vector<int>::iterator it = men.begin();it != men.end(); it++)
	{
		cout << *it << " ";
	}
	return 0;

}