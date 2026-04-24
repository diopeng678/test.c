#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDatatype;

typedef struct seqlist
{
	SLDatatype *a;
	int size;
	int capacity;
}SL;

//初始化 
void SLInit(SL*ps);
//销毁
void SLDestory(SL* ps);
//打印
void SLPrint(SL ps);

//头插删和尾插删
void SLPushback(SL* ps,SLDatatype x);
void SLPushfornt(SL* ps,SLDatatype x);
void SLpopback(SL* ps);
void SLpopfornt(SL* ps);

//指定位置插入或删除数据
void SLinsert(SL *ps,int pos, SLDatatype X);
void SLerase(SL* ps, int pos);
int SLFind(SL* ps, SLDatatype X);
void CheckCapacity(SL* ps);






