#include<stdio.h>
#include<string.h>
char *my_strstr(const char *str1,const char *str2) {
	const char* s1 = NULL;
	const char* s2 = NULL;
	const char* cur = str1;
	if (*str2 == '\0')
		return (char*)str1;
	while(*cur)
	{
		s1 = cur;
		s2 = str2;
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char*)cur;
			cur++;
	}
	}

	return NULL;
}

int main() {
	char arr1[] = "qazwsxedcrfv";
	char arr2[] = "wsx";
	char* ret = my_strstr(arr1, arr2);
	printf("%s", ret);

	return 0;
}