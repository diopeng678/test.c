#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

void testSelect()
{
	int a[] = { 33,24,52,63,63,654,645,4675,4756,8654,7654,3456 };
	int n = sizeof(a) / sizeof(a[0]);
	SelectSort(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void testInsert()
{
	int a[] = { 33,24,52,63,63,654,645,4675,4756,8654,7654,3456 };
	int n = sizeof(a) / sizeof(a[0]);
	InsertSort(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void testQuick1()
{
	int a[] = { 33,24,52,63,53,654,645,4675,4756,654,7654,3456 };
	int n = sizeof(a) / sizeof(a[0]);
	QuickSort1(a, 0,11);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void testQuick2()
{
	int a[] = { 33,24,52,63,53,654,645,4675,4756,654,7654,3456 };
	int n = sizeof(a) / sizeof(a[0]);
	QuickSort2(a, 0, 11);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//²âÊÔ·ÇµÝ¹é¿ìÅÅ
void testQuick3()
{
	int a[] = { 33,24,52,63,53,654,645,4675,4756,654,7654,3456 };
	int n = sizeof(a) / sizeof(a[0]);
	QuickSortNonR(a,0,n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void testmerge()
{
	int a[] = { 33,24,52,63,53,654,645,4675,4756,654,7654,3456 };
	int n = sizeof(a) / sizeof(a[0]);
	MergeSort(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void testmergeNonr()
{
	int a[] = { 33,24,52,63,53,654,645,4675,4756,654,7654,3456 };
	int n = sizeof(a) / sizeof(a[0]);
	MergeSortNonR(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	testmergeNonr();
	return 0;
}