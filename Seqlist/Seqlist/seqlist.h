#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "contact.h"

typedef peoInfo SLDataType;

typedef struct SeqList
{
	SLDataType* arr;
	size_t size;
	size_t capacity;
}SL;
//顺序表的初始化
void SLInit(SL* ps);
//顺序表的销毁
void SLDestory(SL* ps);


//头插法
void SLPushFront(SL* ps, SLDataType  x);
//尾插法
void SLPushBack(SL* ps, SLDataType  x);

//打印顺序表
void SLPrint(SL ps);