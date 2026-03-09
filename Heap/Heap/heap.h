#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int* arr;      
    int capacity;  
    int count;    
} Heap;

// 创建堆
Heap* createHeap(int capacity);

// 插入元素（向上调整）
void insert(Heap* heap, int value);

// 获取堆顶元素
int top(Heap* heap);

// 删除堆顶（向下调整）
int pop(Heap* heap);

// 判断堆是否为空
int isEmpty(Heap* heap);

// 获取堆的大小
int size(Heap* heap);

// 销毁堆，释放内存
void destroyHeap(Heap* heap);

// 遍历输出堆里所有元素
void printHeap(Heap* heap);