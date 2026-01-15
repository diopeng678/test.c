#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


//int main() {
//	FILE *fp;
//	char str[100];
//	// 打开文件以读取
//	fp = fopen("6666", "w");
//	if (fp == NULL) {
//		perror("无法打开文件");
//		return -1;
//	}
//		char mmo = 0;
//		for (mmo = 'a';mmo <= 'z'; mmo++)
//		{
//			fputc(mmo, fp);
//			
//		}
//		fputc(97, fp);
//		//以ASCII码形式写入字符的形式进行计入的
//
//		// 关闭文件
//	fclose(fp);
//	return 0;
//}

//int main() {
//	FILE* fp;
//	char str[100];
//	 打开文件以读取
//	fp = fopen("6666", "r");
//	if (fp == NULL) {
//		perror("无法打开文件");
//		return -1;
//	}
//		int ch = fgetc(fp);
//		printf("%c\n", ch);
//
//		 ch = fgetc(fp);
//		printf("%c\n", ch);
//
//		 ch = fgetc(fp);
//		printf("%c\n",ch );
//
//		进行读取的时候会将光标向后移动
//
//	fclose(fp);
//	return 0;
//}

//int main() {
//	FILE* fp;
//	
//	// 打开文件以读取,用循环的方式去读取文件中的内容,就是一下子读取完
//	fp = fopen("6666", "r");
//	if (fp == NULL) {
//		perror("无法打开文件");
//		return -1;
//	}
//	int ch=0;
//	while(( ch = fgetc(fp)) != EOF)
//	{
//		printf("%c", ch);
//	}	
//	fclose(fp);
//	return 0;
//}
//fputs函数的使用
//"a"为追加

int main() {
	FILE* fp;
	fp = fopen("6666", "a");
	if (fp == NULL) {
		perror("无法打开文件");
		return -1;
	}
	int ch=0;
	fputs("hello world\n", fp);	
	fclose(fp);
	return 0;
}
