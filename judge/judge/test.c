#include<stdio.h>
//int main() {
//	int a = 1;
//	if(*(char*)&a== 1) {
//		printf("是小端\n");
//	} else {
//		printf("是大端\n");
//	}
//}
// 
// 
//用联合体实现大端小端判断
int check_sys() {
	union Un{
		int a;
		char b;
	} c;
	c.a = 1;
	return c.b;       
int main() {
	if(check_sys() == 1) {
		printf("是小端\n");
	} else {
		printf("是大端\n");
	}
}