#include<iostream>
// 可变参数模板
using namespace std;

//template <class ...Args>
//void Print(Args&&... args) {
//    cout << sizeof...(args) << endl;   // 输出参数个数
//}

// 终止函数
void ShowList() {
    cout << endl;
}

// 递归展开 本质像是一个循环，每次处理一个参数，直到没有参数为止 不过是通过递归实现的 原因是for循环无法处理可变参数模板
template <class T, class ...Args>
void ShowList(T x, Args... args) {
    cout << x << " ";
    ShowList(args...);   // 递归调用，每次减少一个参数
}

template <class ...Args>
void Print(Args... args) {
    ShowList(args...);
}


int main() {
    //Print();                    // 0
    //Print(1);                   // 1
    //// 对于 Print(1, string("xxx"), 2.2);
    //// 编译器会生成类似：
    ////void Print(int&& arg1, string && arg2, double&& arg3);
    //Print(1, string("xxx"));    // 2
    //Print(1.1, "xxx", 2);       // 3

    Print(1, string("hello"), 2.2);
    // 输出：1 hello 2.2
    return 0;
}