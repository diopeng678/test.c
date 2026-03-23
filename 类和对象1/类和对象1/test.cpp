#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"date.h"

void TestDate4()
{
	Date d1(2034, 10, 1);
	Date d2(2034, 10 , 32);

	cout << d1 - d2 << endl;
}

void TestDate1()
{
	Date d1(2026,3,23);
	d1.Print();
	Date d2 (2026,11,27);
	d2.Print();
	cout << d2 - d1 << endl;
	Date d3;
	cin >> d3;
}

int main()
{
	//TestDate4();
	TestDate1();
	return 0;
}	
//我真燃尽了  
//我真燃尽了