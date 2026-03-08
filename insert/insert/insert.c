#define _CRT_SECURE_NO_WARNINGS_1
#include<stdio.h>

void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		//end前的元素是组织好的,每次for循环都会在加入一个元素进行判断
		while (end >= 0)
		{
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}

int main()
{
	int arr[] = { 55,24,345,645,7654,4756,35,356};
	int n = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, n);
	for (int i = 0;i < n;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}