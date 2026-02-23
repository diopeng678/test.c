#define _CRT_SECURE_NO_WARNINGS_1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int n = 1000;
	srand(time(NULL));
	const char* file = "rand.txt";
	FILE* fp = fopen(file, "w");
	if (fp == NULL)
	{
		printf("Error opening file %s\n", file);
		return;
	}
	for(int i=0; i<n; i++)
	{
		int r = rand();
		fprintf(fp, "%d\n", r);
	}
	fclose(fp);


	return 0;
}