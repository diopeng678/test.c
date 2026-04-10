#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm> // sort所在头文件

// 1. 仿函数：降序排序
struct DescendCompare {
    bool operator()(int a, int b) const {
        return a > b; // 降序：a比b大则返回true，a排在前面
    }
};

// 2. 仿函数：按结构体的age字段升序排序
struct Person {
    std::string name;
    int age;
};

struct SortByAgeAsc {
    bool operator()(const Person& p1, const Person& p2) const {
        return p1.age < p2.age; // 按age升序
    }
};

int main() {
    // 测试1：int数组降序排序
    std::vector<int> nums = { 3, 1, 4, 1, 5, 9 };
    sort(nums.begin(), nums.end(), DescendCompare()); // 传入仿函数对象
    std::cout << "降序排序结果：";
    for (int num : nums) std::cout << num << " "; // 输出：9 5 4 3 1 1
    std::cout << std::endl;

    // 测试2：结构体数组按age升序排序
    std::vector<Person> people = { {"Alice", 25}, {"Bob", 20}, {"Charlie", 30} };
    sort(people.begin(), people.end(), SortByAgeAsc());
    std::cout << "按age升序排序结果：" << std::endl;
    for (const auto& p : people) {
        std::cout << "姓名：" << p.name << "，年龄：" << p.age << std::endl;
    }
    return 0;
}
