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

int main()
{
	TestDate4();
	return 0;
}	
//我真燃尽了  
//我真燃尽了