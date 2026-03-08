#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0;
    printf("请输入N的值：");
    scanf("%d", &n);

	int* arr = (int*)malloc(n * sizeof(int));

    if(arr == NULL) {
        printf("内存分配失败！\n");
        return 1;
	}

    printf("请输入%d个整数：\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("最大值为：%d\n", max);
    free(arr);
    arr = NULL;
    return 0;
}
