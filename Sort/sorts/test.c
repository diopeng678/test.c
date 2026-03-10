#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

int main()
{
	int a[] = { 33,24,52,63,63,654,645,4675,4756,8654,7654,3456 };
	int n = sizeof(a) / sizeof(a[0]);
	//BubbleSort(a, n);
	InsertSort(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}