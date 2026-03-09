#define _CRT_SECURE_NO_WARNINGS
#include "heap.h"

int main() {
    Heap* heap = createHeap(100);

    insert(heap, 10);
    insert(heap, 19);
    insert(heap, 7);
    insert(heap, 25);
    insert(heap, 3);

	printf("¶ÑÖĞÔªËØ£º");
	printHeap(heap);

    while (!isEmpty(heap)) {
        printf("µ¯³ö£º%d\n", pop(heap));
    }

    destroyHeap(heap);
    return 0;
}