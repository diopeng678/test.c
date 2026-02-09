#define _CRT_SECURE_NO_WARNINGS_1
#include <iostream>	

class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // 重载+运算符，实现两个Point对象相加
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
};

// 使用
int main() {
    Point a(1, 2), b(3, 4);
    Point c = a + b;      // c.x=4, c.y=6


    return 0;
}