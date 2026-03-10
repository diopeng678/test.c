#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

//Ωªªª∫Ø ˝
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//√∞≈›≈≈–Ú
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		// µ•ÃÀ
		int flag = 0;
		for (int i = 1; i < n - j; i++)
		{
			if (a[i - 1] > a[i])
			{
				swap(&a[i - 1], &a[i]);
				flag = 1;
			}
		}

		if (flag == 0)
		{
			break;
		}
	}
}

//≤Â»Î≈≈–Ú
void InsertSort(int* a, int n)
{
	for (int i = 0;i < n - 1;i++)
	{
		int tmp = a[i + 1];
		int end = i;
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

