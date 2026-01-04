
//#include<stdio.h>
//#include<string.h>
//
//char* my_strstr(const char* str1, const char* str2) {
//	const char* s1 = NULL;
//	const char* s2 = NULL;
//	const char* cur = str1;
//	if (*str2 == '\0')
//		return (char*)str1;
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = str2;
//		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)cur;
//			cur++;
//		}
//	}
//
//	return NULL;
//}
//
//int main() {
//	char arr1[] = "qazwsxedcrfv";
//	char arr2[] = "wsx";
//	char* ret = my_strstr(arr1, arr2);
//	printf("%s", ret);
//
//	return 0;
//}
#include<stdio.h>
#include<string.h>

char* my_strstr(const char* str1, const char* str2) {
    const char* s1 = NULL;
    const char* s2 = NULL;
    const char* cur = str1;
    // 处理子串为空的情况
    if (*str2 == '\0')
        return (char*)str1;
    // 遍历主串
    while (*cur) {
        s1 = cur;
        s2 = str2;
        // 比较当前位置开始的字符（修正为字符内容比较）
        while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
            s1++;
            s2++;
        }
        // 子串匹配完成
        if (*s2 == '\0') {
            return (char*)cur;
        }
        cur++;
    }
    // 未找到子串
    return NULL;
}

int main() {
    // 修正数组长度（自动推导）
    char arr1[] = "qazwsxedcrfv";
    char arr2[] = "wsx";
    char* ret = my_strstr(arr1, arr2);
    if (ret != NULL) {
        printf("找到子串：%s\n", ret);
    }
    else {
        printf("未找到子串\n");
    }
    return 0;
}