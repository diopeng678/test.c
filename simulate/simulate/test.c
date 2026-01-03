#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strcat(char* dest, const char* src) {

	char* ret = dest;
	assert(dest && src);
	//找到目标空间的\0位置
	while (*dest!='\0') {
		dest++;
	}
	//数据的拷贝
	while (*dest++=*src++)
	{
		;
	}
	return ret;
}



int main() {
	char str1[20] = "Hello, ";
	char str2[] = "World!";
	
	my_strcat(str1, str2);
	
	// Print the concatenated string
	printf("%s\n", str1);
	
	return 0;
}