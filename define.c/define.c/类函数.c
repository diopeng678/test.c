#include<stdio.h>

#define cal_max(type)\
type type##_max(type x, type y){\
	return x>y?x:y;\
}
//定义函数
cal_max(int)//生成int_max函数
cal_max(float)//生成float_max函数
//对于类似函数有奇效


int main() {
	int a = 10, b = 20;
	int r1 = int_max(a, b);
	printf("max(%d, %d) = %d\n", a, b, r1);
	float c = 5.5f, d = 3.3f;
	float r2 = float_max(c, d);
	printf("max(%.2f, %.2f) = %.2f\n", c, d, r2);

	return 0;
}
