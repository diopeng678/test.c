#include<stdio.h>	
#include<assert.h>
char *my_strcat(char *dest, const char *src) {
	assert(dest && src);
	char* ret = dest;
	//找到目标空间
	while(*dest!='\0')
		dest++;
	//进行拷贝
	while(*dest++ = *src++){
		;
	
	
	}
	return ret;
}
int main() {
	char arr1[20] = "what can  ";
	char arr2[] = "i say";
	char *ret = my_strcat(arr1, arr2);
	printf("%s\n", ret);
	return 0;
}