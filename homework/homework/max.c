#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    int n = 0;
//    printf("请输入N的值：");
//    scanf("%d", &n);
//
//	int* arr = (int*)malloc(n * sizeof(int));
//
//    if(arr == NULL) {
//        printf("内存分配失败！\n");
//        return 1;
//	}
//
//    printf("请输入%d个整数：\n", n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    int max = arr[0];
//    for (int i = 1; i < n; i++) {
//        if (arr[i] > max) {
//            max = arr[i];
//        }
//    }
//
//    printf("最大值为：%d\n", max);
//    free(arr);
//    arr = NULL;
//    return 0;
//}

#include <stdio.h>

#define A 4
#define B 3
#define C 7

struct Dxs {  // 定义多项式项的结构体
    int xs;  // 系数
    int zs;  // 指数
};

int main()
{
    struct Dxs a[A];
    struct Dxs b[B];
    struct Dxs c[C];

    // 输入多项式a的系数和指数
    printf("输入多项式a的系数与指数：\n");
    for (int i = 0; i < A; i++)
        scanf("%d %d", &a[i].xs, &a[i].zs);

    // 输出多项式a的系数和指数
    printf("多项式a的系数：");
    for (int i = 0; i < A; i++)
        printf("%d\t", a[i].xs);
    printf("\n多项式a的指数：");
    for (int i = 0; i < A; i++)
        printf("%d\t", a[i].zs);

    // 输入多项式b的系数和指数
    printf("\n输入多项式b的系数与指数：\n");
    for (int i = 0; i < B; i++)
        scanf("%d %d", &b[i].xs, &b[i].zs);

    // 输出多项式b的系数和指数
    printf("多项式b的系数：");
    for (int i = 0; i < B; i++)
        printf("%d\t", b[i].xs);
    printf("\n多项式b的指数：");
    for (int i = 0; i < B; i++)
        printf("%d\t", b[i].zs);

    // 多项式加法核心逻辑
    int i = 0, j = 0, k = 0;
    while (i < A && j < B)
    {
        if (a[i].zs == b[j].zs)
        {
            if ((a[i].xs + b[j].xs) != 0)
            {
                c[k].xs = a[i].xs + b[j].xs;
                c[k].zs = a[i].zs;
                k++;
            }
            i++;
            j++;
        }
        else if (a[i].zs < b[j].zs)
        {
            c[k].xs = a[i].xs;
            c[k].zs = a[i].zs;
            k++;
            i++;
        }
        else
        {
            c[k].xs = b[j].xs;
            c[k].zs = b[j].zs;
            k++;
            j++;
        }
    }

    // 处理多项式a的剩余项
    while (i < A)
    {
        c[k].xs = a[i].xs;
        c[k].zs = a[i].zs;
        k++;
        i++;
    }

    // 处理多项式b的剩余项
    while (j < B)
    {
        c[k].xs = b[j].xs;
        c[k].zs = b[j].zs;
        k++;
        j++;
    }

    // 输出结果多项式a+b的系数和指数
    printf("\n多项式a+b的系数：");
    for (i = 0; i < k; i++)
        printf("%d\t", c[i].xs);
    printf("\n多项式a+b的指数：");
    for (i = 0; i < k; i++)
        printf("%d\t", c[i].zs);

    return 0;
}
//王仕鹏 41班