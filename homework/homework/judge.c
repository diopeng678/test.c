#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int judge(int a, int b)
{
	if (a > b)
		return a;
	else if (a < b)
		return b;
	else
		return a;
}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("大的数为 %d\n", judge(a, b));
}