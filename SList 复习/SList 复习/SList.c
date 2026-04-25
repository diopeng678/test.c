#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"


void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("NULL \n");
}

SLTNode* SLTBuyNode(SLTDataType x)
{
		SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
		if(node == NULL)
		{
			perror("malloc fail");
			exit(-1);
		}
		node->data = x;
		node->next = NULL;
		return node;	
}

//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* node = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = node;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = node;
	}
}

//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(*pphead);
	SLTNode* node = SLTBuyNode(x);
	node->next = *pphead;
	*pphead = node;
}

//尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(*pphead);
	if(*pphead == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* ptail = *pphead;
		SLTNode* prev = *pphead;
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		free(ptail);
		ptail = NULL;
		prev->next = NULL;
	}	
}

//头删
void SLTPopFront(SLTNode** pphead)
{
	assert(*pphead);
	SLTNode* pcur =(*pphead)->next;
	free(*pphead);
	*pphead = pcur;
}


//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* pcur = phead;
	while (pcur)//等价于pcur != NULL
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	//pcur == NULL
	return NULL;
}

//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);
	SLTNode* node = SLTBuyNode(x);
	//相当于是头插
	if(pos == *pphead)
	{

		SLTPushFront(pphead, x);
	}

	else
	{
		SLTNode* prev = *pphead;
		while(prev->next != pos)
		{
			prev = prev->next;
		}
		node->next = pos;
		prev->next = node;
	}



}
//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);

	SLTNode* newnode = SLTBuyNode(x);
	//pos -> newnode -> pos->next
	newnode->next = pos->next;
	pos->next = newnode;
}

//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead);
	assert(pos);

	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}
//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos && pos->next);
	SLTNode* del = pos->next;
	
	pos->next = del->next;
	free(del);
	del = NULL;
	
}

//销毁链表
void SListDesTroy(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}