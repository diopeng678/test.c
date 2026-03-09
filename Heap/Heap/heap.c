#define _CRT_SECURE_NO_WARNINGS
#include "heap.h"

// 创建堆
Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->arr = (int*)malloc(sizeof(int) * capacity);
    heap->capacity = capacity;
    heap->count = 0;
    return heap;
}

// 插入元素（向上调整）
void insert(Heap* heap, int value) {
    if (heap->count >= heap->capacity) {
        printf("堆满了，无法插入！\n");
        return;
    }
    int i = heap->count++;
    heap->arr[i] = value;
    // 上滤
    while (i > 0 && heap->arr[(i - 1) / 2] < heap->arr[i]) {
        int tmp = heap->arr[i];
        heap->arr[i] = heap->arr[(i - 1) / 2];
        heap->arr[(i - 1) / 2] = tmp;
        i = (i - 1) / 2;
    }
}

// 获取堆顶元素
int top(Heap* heap) {
    if (heap->count == 0) {
        printf("堆为空。\n");
        return -1;
    }
    return heap->arr[0];
}

// 删除堆顶（向下调整）
int pop(Heap* heap) {
    if (heap->count == 0) {
        printf("堆为空。\n");
        return -1;
    }
    int max = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->count];
    int i = 0;
    // 下滤
    while (1) {
        int largest = i;
        int l = 2 * i + 1, r = 2 * i + 2;
        if (l < heap->count && heap->arr[l] > heap->arr[largest]) largest = l;
        if (r < heap->count && heap->arr[r] > heap->arr[largest]) largest = r;
        if (largest == i) break;
        int tmp = heap->arr[i];
        heap->arr[i] = heap->arr[largest];
        heap->arr[largest] = tmp;
        i = largest;
    }
    return max;
}

// 判断堆是否为空
int isEmpty(Heap* heap) {
    return heap->count == 0;
}

// 获取堆的大小
int size(Heap* heap) {
    return heap->count;
}

// 销毁堆，释放内存
void destroyHeap(Heap* heap) {
    free(heap->arr);
    free(heap);
}

// 遍历输出堆里所有元素
void printHeap(Heap* heap) {
    printf("堆中的元素：");
    for (int i = 0; i < heap->count; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}