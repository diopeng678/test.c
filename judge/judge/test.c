#include<stdio.h>
int main() {
	int a = 1;
	if(*(char*)&a== 1) {
		printf("是小端\n");
	} else {
		printf("是大端\n");
	}
}