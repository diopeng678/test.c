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

//#include <stdio.h>
//
//#define A 4
//#define B 3
//#define C 7
//
//struct Dxs {  // 定义多项式项的结构体
//    int xs;  // 系数
//    int zs;  // 指数
//};
//
//int main()
//{
//    struct Dxs a[A];
//    struct Dxs b[B];
//    struct Dxs c[C];
//
//    // 输入多项式a的系数和指数
//    printf("输入多项式a的系数与指数：\n");
//    for (int i = 0; i < A; i++)
//        scanf("%d %d", &a[i].xs, &a[i].zs);
//
//    // 输出多项式a的系数和指数
//    printf("多项式a的系数：");
//    for (int i = 0; i < A; i++)
//        printf("%d\t", a[i].xs);
//    printf("\n多项式a的指数：");
//    for (int i = 0; i < A; i++)
//        printf("%d\t", a[i].zs);
//
//    // 输入多项式b的系数和指数
//    printf("\n输入多项式b的系数与指数：\n");
//    for (int i = 0; i < B; i++)
//        scanf("%d %d", &b[i].xs, &b[i].zs);
//
//    // 输出多项式b的系数和指数
//    printf("多项式b的系数：");
//    for (int i = 0; i < B; i++)
//        printf("%d\t", b[i].xs);
//    printf("\n多项式b的指数：");
//    for (int i = 0; i < B; i++)
//        printf("%d\t", b[i].zs);
//
//    // 多项式加法核心逻辑
//    int i = 0, j = 0, k = 0;
//    while (i < A && j < B)
//    {
//        if (a[i].zs == b[j].zs)
//        {
//            if ((a[i].xs + b[j].xs) != 0)
//            {
//                c[k].xs = a[i].xs + b[j].xs;
//                c[k].zs = a[i].zs;
//                k++;
//            }
//            i++;
//            j++;
//        }
//        else if (a[i].zs < b[j].zs)
//        {
//            c[k].xs = a[i].xs;
//            c[k].zs = a[i].zs;
//            k++;
//            i++;
//        }
//        else
//        {
//            c[k].xs = b[j].xs;
//            c[k].zs = b[j].zs;
//            k++;
//            j++;
//        }
//    }
//
//    // 处理多项式a的剩余项
//    while (i < A)
//    {
//        c[k].xs = a[i].xs;
//        c[k].zs = a[i].zs;
//        k++;
//        i++;
//    }
//
//    // 处理多项式b的剩余项
//    while (j < B)
//    {
//        c[k].xs = b[j].xs;
//        c[k].zs = b[j].zs;
//        k++;
//        j++;
//    }
//
//    // 输出结果多项式a+b的系数和指数
//    printf("\n多项式a+b的系数：");
//    for (i = 0; i < k; i++)
//        printf("%d\t", c[i].xs);
//    printf("\n多项式a+b的指数：");
//    for (i = 0; i < k; i++)
//        printf("%d\t", c[i].zs);
//
//    return 0;
//}
////王仕鹏 41班

//#include <iostream>
//#include <cmath>
//using namespace std;
//
//const double PI = 3.1415926;
//
//// 计算圆形面积
//double area(double r) {
//    return PI * r * r;
//}
//
//// 计算长方形面积
//double area(double l, double w) {
//    return l * w;
//}
//
//// 计算正方形面积
//double area_square(double s) {
//    return s * s;
//}
//
//int main() {
//    int choice;
//    do {
//        cout << "\n===== 图形面积计算 =====\n";
//        cout << "1. 圆形\n";
//        cout << "2. 长方形\n";
//        cout << "3. 正方形\n";
//        cout << "0. 退出程序\n";
//        cout << "请选择图形类型(0-3): ";
//        cin >> choice;
//
//        if (choice == 1) {
//            double r;
//            cout << "请输入圆的半径: ";
//            cin >> r;
//            if (r < 0) {
//                cout << "半径不能为负数！\n";
//                continue;
//            }
//            cout << "圆的面积 = " << area(r) << endl;
//        }
//        else if (choice == 2) {
//            double l, w;
//            cout << "请输入长方形的长和宽: ";
//            cin >> l >> w;
//            if (l < 0 || w < 0) {
//                cout << "长和宽不能为负数！\n";
//                continue;
//            }
//            cout << "长方形的面积 = " << area(l, w) << endl;
//        }
//        else if (choice == 3) {
//            double s;
//            cout << "请输入正方形的边长: ";
//            cin >> s;
//            if (s < 0) {
//                cout << "边长不能为负数 \n";
//                continue;
//            }
//            cout << "正方形的面积 = " << area_square(s) << endl;
//        }
//        else if (choice == 0) {
//            cout << "程序结束 \n";
//        }
//        else {
//            cout << "输入错误，请重新选择\n";
//        }
//    } while (choice != 0);
//
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//// 两个整数的最小值
//int Min(int a, int b) {
//    return (a < b) ? a : b;
//}
//
//// 三个整数的最小值
//int Min(int a, int b, int c) {
//    return Min(Min(a, b), c);
//}
//
//// 两个双精度的最小值
//double Min(double a, double b) {
//    return (a < b) ? a : b;
//}
//
//// 三个双精度的最小值
//double Min(double a, double b, double c) {
//    return Min(Min(a, b), c);
//}
//
//int main() {
//    cout << "Min(5, 3) = " << Min(5, 3) << endl;
//    cout << "Min(5, 3, 9) = " << Min(5, 3, 9) << endl;
//    cout << "Min(5.2, 3.1) = " << Min(5.2, 3.1) << endl;
//    cout << "Min(5.2, 3.1, 9.8) = " << Min(5.2, 3.1, 9.8) << endl;
//    return 0;
//}

#include <iostream>
#include <string>
using namespace std;

int main() {
    // 定义字符串变量并初始化
    string str = "Hello, C++";
    // 建立字符串的引用
    string& man = str;

    cout << "原始字符串: " << str << endl;
    cout << "引用的值: " << man << endl;

    // 修改引用，观察原字符串变化
    man = "Hello, World!";
    cout << "\n修改引用后：\n";
    cout << "原始字符串: " << str << endl;
    cout << "引用的值: " << man << endl;

    return 0;
}