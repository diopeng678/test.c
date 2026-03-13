#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

//交换函数
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//冒泡排序
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		// 单趟
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

//插入排序
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

//选择排序
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;

	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;

		for (int i = begin + 1 ;i <= end ; ++i)
		{
			if (a[maxi] < a[i])
			{
				maxi = i;
			}
			if (a[mini] > a[i])
			{
				mini = i;
			}

		}

		swap(&a[begin], &a[mini]);
		if (begin == maxi)
			maxi = mini;

		swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
	
}

//hoare法
void QuickSort1(int* a,int left, int right)
{
	if (left >= right)
		return;

	int keyi = left;
	int begin = left, end = right;
	while (begin < end)
	{
		// 右边找小
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}

		// 左边找大
		while (begin < end && a[begin] <= a[keyi])
		{
			++begin;
		}

		swap(&a[begin], &a[end]);
	}

	swap(&a[keyi], &a[begin]);
	keyi = begin;
	// [left, keyi-1] keyi [keyi+1, right]
	QuickSort1(a, left, keyi - 1);
	QuickSort1(a, keyi + 1, right);
}

//前后指针法
void QuickSort2(int* a, int left, int right)
{
	if (left >= right)
		return;

	int keyi = left;
	int prev =left;
	int cur = left + 1;

	while (cur <= right)
	{
		while (a[cur] <=a[keyi] && ++prev!=cur)
		{
			swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	swap(&a[keyi], &a[prev]);
	keyi = prev;

	QuickSort2(a, left, keyi - 1);
	QuickSort2(a, keyi + 1, right);
}

#include "Stack.h"

int QuickSort3(int* a, int left, int right)
{
	
	int keyi = left;
	int prev = left;
	int cur = left + 1;

	if (left >= right)
		return prev;

	while (cur <= right)
	{
		while (a[cur] <= a[keyi] && ++prev != cur)
		{
			swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	swap(&a[keyi], &a[prev]);
	keyi = prev;

	QuickSort2(a, left, keyi - 1);
	QuickSort2(a, keyi + 1, right);

	return prev;
}

//非递归快排
void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	STInit(&st);
	STPush(&st, right);
	STPush(&st, left);
	while (!STEmpty(&st))
	{
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);

		int keyi = QuickSort3(a, begin, begin);
		if(keyi-1 > begin)
		{
			STPush(&st, keyi - 1);
			STPush(&st, begin);
		}
		if (keyi + 1 < end)
		{
			STPush(&st, end);
			STPush(&st, keyi + 1);
		}
	
	}
	STDestroy(&st);
}

//归并排序
void _Mergesort(int* a, int* tmp, int begin, int end)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	_Mergesort(a, tmp, begin, mid);
	_Mergesort(a, tmp, mid + 1, end);
	//这里的区间不能取减一的，因为mid是向下取整的，所以mid+1才是右边的开始位置
	//如果取减一的可能会栈溢出

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while(begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while(begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	_Mergesort(a, tmp, 0, n - 1);

	free(tmp);
	tmp = NULL;
}

//归并排序(非递归)
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	// gap每组归并数据的数据个数
	int gap = 1;
	while (gap < n) 
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			// [begin1, end1][begin2, end2]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			// 第二组都越界不存在，这一组就不需要归并
			if (begin2 >= n)
				break;

			// 第二的组begin2没越界，end2越界了，需要修正一下，继续归并
			if (end2 >= n)
				end2 = n - 1;

			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}

		printf("\n");

		gap *= 2;
	}

	free(tmp);
	tmp = NULL;
}
