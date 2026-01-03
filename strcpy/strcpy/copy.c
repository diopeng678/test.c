#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main() {
	char arr1[20] = "Hello, World!"; 

	char arr2[20]="cccccccccccccccc";

	strcpy(arr2, arr1);

	printf("%s", arr2);
	return 0;

}