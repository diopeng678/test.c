#define _CRT_SECURE_NO_WARNINGS
#include"sqlist.h"

void SLTest01()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 21);
	SLPushBack(&sl, 18);
	SLPushBack(&sl, 30);
	SLPushBack(&sl, 44);
	SLPrint(sl);
	SLPopBack(&sl);
	SLPrint(sl);
	SLPopBack(&sl);
	SLPrint(sl);
	SLPopBack(&sl);
	SLPrint(sl);
	SLPopBack(&sl);
	SLPrint(sl);
	SLPopFront(&sl);
	SLPrint(sl);
	//...........
	SLDestroy(&sl);
}

void SLTest02()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(sl);//1 2 3 4
	
	int find = SLFind(&sl, 3);
	if (find < 0)
	{
		printf("没有找到！\n");
	}
	else
	{
		printf("找到了！下标为%d\n",find);
	}
	SLDestroy(&sl);
}

int main()
{
	SLTest02();
	return 0;
}
