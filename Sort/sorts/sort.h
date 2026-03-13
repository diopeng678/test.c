#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

//交换函数
void swap(int* a, int* b);

//冒泡排序
void BubbleSort(int* a, int n);

//插入排序
void InsertSort(int* a, int n);

//选择排序
void SelectSort(int* a, int n);

//快速排序hoare法
void QuickSort1(int* a,int left, int right);

//快速排序前后指针法
void QuickSort2(int* a, int left, int right);

//非递归快排
void QuickSortNonR(int* a, int left, int right);

//归并排序递归
void MergeSort(int* a, int n);

//归并排序非递归
void MergeSortNonR(int* a, int n);
