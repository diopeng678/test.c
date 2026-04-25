#define _CRT_SECURE_NO_WARNINGS

#include"SList.h"

void SListTest01()
{
	//链表是由一个一个的节点组成
	//创建几个节点
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	node1->data = 1;

	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	node2->data = 2;

	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	node3->data = 3;

	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
	node4->data = 4;

	//将四个节点连接起来
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	//调用链表的打印
	SLTNode* plist = node1;
	SLTPrint(plist);
}

void SListTest02()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist); // 1->2->3->4->NULL

	SListDesTroy(&plist);
	SLTPrint(plist);

	//测试查找
	//SLTNode* find = SLTFind(plist, 1);
	//SLTInsert(&plist, find, 11);
	//SLTInsertAfter(find, 11);
	//删除pos节点
	//SLTErase(&plist, find);
	//SLTEraseAfter(find);
	//SLTPrint(plist);
	//if (find == NULL)
	//{
	//	printf("没有找到！\n");
	//}
	//else {
	//	printf("找到了！\n");
	//}


	//SLTPushBack(NULL, 5);
	//
	//测试头插
	//SLTPushFront(&plist, 6);
	//SLTPrint(plist);
	//SLTPushFront(&plist, 7);
	//SLTPrint(plist);
	//SLTPushFront(&plist, 8);
	//SLTPrint(plist);

	//测试头删
	//SLTPopFront(&plist);
	//SLTPrint(plist);// 2->3->4->NULL
	//SLTPopFront(&plist);
	//SLTPrint(plist);
	//SLTPopFront(&plist);
	//SLTPrint(plist);
	//SLTPopFront(&plist);
	//SLTPrint(plist);
	//SLTPopFront(&plist);
	//SLTPrint(plist);

}

int main()
{
	//SListTest01();
	SListTest02();
	return 0;
}