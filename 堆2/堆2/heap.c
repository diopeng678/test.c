
#define _CRT_SECURE_NO_WARNINGS_1
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 堆的结构体
typedef struct {
    int arr[MAX_SIZE];
    int size;
} Heap;

// 初始化堆
void initHeap(Heap* heap) {
    heap->size = 0;
}

// 交换两个元素
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 向上调整（用于插入操作）
void heapifyUp(Heap* heap, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && heap->arr[index] > heap->arr[parent]) {
        swap(&heap->arr[index], &heap->arr[parent]);
        heapifyUp(heap, parent);
    }
}

// 向下调整（用于删除操作）
void heapifyDown(Heap* heap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < heap->size && heap->arr[left] > heap->arr[largest]) {
        largest = left;
    }
    if (right < heap->size && heap->arr[right] > heap->arr[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(&heap->arr[index], &heap->arr[largest]);
        heapifyDown(heap, largest);
    }
}

// 插入元素
void insert(Heap* heap, int value) {
    if (heap->size >= MAX_SIZE) {
        printf("堆已满，无法插入新元素\n");
        return;
    }
    heap->arr[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

// 提取最大值
int extractMax(Heap* heap) {
    if (heap->size == 0) {
        printf("堆为空\n");
        return -1;
    }
    int max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return max;
}

// 获取最大值（不删除）
int getMax(Heap* heap) {
    if (heap->size == 0) {
        printf("堆为空\n");
        return -1;
    }
    return heap->arr[0];
}

// 打印堆
void printHeap(Heap* heap) {
    printf("堆中的元素: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

// 构建堆（从数组）
void buildHeap(Heap* heap, int arr[], int n) {
    initHeap(heap);
    for (int i = 0; i < n && i < MAX_SIZE; i++) {
        heap->arr[i] = arr[i];
        heap->size++;
    }
    // 从最后一个非叶子节点开始向下调整
    for (int i = (heap->size / 2) - 1; i >= 0; i--) {
        heapifyDown(heap, i);
    }
}

// 主函数示例
int main() {
    Heap heap;

    // 示例1：逐个插入元素
    printf("示例1：逐个插入元素\n");
    initHeap(&heap);

    insert(&heap, 5);
    insert(&heap, 78);
    insert(&heap, 69);
    insert(&heap, 58);
    insert(&heap, 49);

    printf("插入元素后：");
    printHeap(&heap);

    printf("最大值: %d\n", getMax(&heap));

    printf("提取最大值: %d\n", extractMax(&heap));
    printf("提取后堆: ");
    printHeap(&heap);

    printf("提取最大值: %d\n", extractMax(&heap));
    printf("提取后堆: ");
    printHeap(&heap);

    // 示例2：从数组构建堆
    printf("\n示例2：从数组构建堆\n");
    int arr[] = { 5, 3, 8, 4, 1, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原数组: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    buildHeap(&heap, arr, n);
    printf("构建后的堆: ");
    printHeap(&heap);

    // 示例3：堆排序
    printf("\n示例3：堆排序\n");
    printf("排序过程: ");
    while (heap.size > 0) {
        printf("%d ", extractMax(&heap));
    }
    printf("\n");

    return 0;
}
