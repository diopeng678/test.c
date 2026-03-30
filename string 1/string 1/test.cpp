#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 ;
	cout << s1 << endl;
	string s2 = "Hello wangshipeng";
	cout << s2 << endl;
	string s3(s2);
	cout << s3 << endl;
	for(auto c : s3)
	{
		cout << c << " ";
	}
	cout << endl;
	string::iterator p = s2.begin();
	cout << *p << endl;
	string::reverse_iterator m = s2.rbegin();
	cout << *m << endl;	
	// µü´úÆ÷µÄÊ¹ÓÃ µ¹ÖÃ±éÀú×Ö·û´®
	for (auto it = s2 .rbegin(); it != s2.rend(); it++)
	{
			cout << *it << " ";
	}
	return 0;
}