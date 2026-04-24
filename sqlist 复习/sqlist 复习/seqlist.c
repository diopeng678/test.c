#define _CRT_SECURE_NO_WARNINGS
#include"Seqlist.h"


void SLInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SLDestory(SL* ps)
{
	if (ps->a != NULL)
	{
		free(ps->a);
	}
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void CheckCapacity(SL* ps)
{
	if (ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDatatype* tmp = (SLDatatype*)realloc(ps->a, newcapacity * sizeof(SLDatatype));
		if (tmp == NULL)
		{
			perror("fail");
			exit(1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}
//  打印操作
void SLPrint(SL ps)
{
	for(int i = 0; i < ps.size; i++)
	{
		printf("%d ", ps.a[i]);
	}
}

//尾插
void SLPushback(SL* ps, SLDatatype x)
{
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SLPushfornt(SL* ps, SLDatatype x)
{	
	assert(ps);
	CheckCapacity(ps);
	for(int i = ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}

void SLpopback(SL* ps)
{
	assert(ps);
	if (ps->size > 0)
	{
		ps->size--;
	}
}

void SLpopfornt(SL* ps)
{
	assert(ps);
	for(int i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;	
}

//指定位置插入或删除数据
void SLinsert(SL* ps, int pos, SLDatatype X)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	CheckCapacity(ps);
	for (int i = ps->size - 1; i >= pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = X;
	ps->size++;
}

void SLerase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	for(int i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

int SLFind(SL* ps, SLDatatype X)
{
	for(int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == X)
		{
			
			printf("找到了");
			return i;
		}
	}	
	return -1;
}
