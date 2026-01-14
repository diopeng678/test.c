#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main() {
	FILE *fp;
	char str[100];
	// 打开文件以读取
	fp = fopen("6666", "w");
	if (fp == NULL) {
		perror("无法打开文件");
		return -1;
	}
		char mmo = 0;
		for (mmo = 'a';mmo <= 'z'; mmo++)
		{
			fputc(mmo, fp);
			
		}
		fputc(97, fp);
		//以ASCII码形式写入字符的形式进行计入的

		// 关闭文件
	fclose(fp);
	return 0;
}