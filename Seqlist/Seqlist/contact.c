#include"contact.h"
#include"seqlist.h"

//通讯录初始化
void ContactInit(Contact* pc)
{
	SLInit(pc);//直接用顺序表的初始化函数
}

//销毁通讯录
void ContactDesTory(Contact* pc)
{
	SLDestory(pc);//直接用顺序表的销毁函数
}

//增加联系人信息
void ContactAdd(Contact* pc)
{
	peoInfo info ;
	printf("请输入姓名:>");
	scanf("%s", info.name);

	printf("请输入性别:>");
	scanf("%s", info.gerder);

	printf("请输入年龄:>");
	scanf("%d", &info.age);

	printf("请输入电话:>");
	scanf("%s", info.tel);

	printf("请输入地址:>");
	scanf("%s", info.addr);

	SLPushBack(pc, info);//用顺序表的尾插法插入联系人信息
}

int FindByName(Contact* con,  char name[])
{
	for (size_t i = 0; i < con->size; i++)
	{
		if (0==strcmp( con->arr[i].name,name))
		{
			//找到了返回下标
			return i;
		}
	}
	return -1;
}

//通讯录删除数据
void ContactDel(Contact* pc)
{
	char name[NAME_MAX];
	printf("请输入要删除的联系人:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的联系人不存在!\n");
	}
	else
	{
		//删除数据
		for (size_t i = pos; i < pc->size - 1; i++)
		{
			pc->arr[i] = pc->arr[i + 1];
		}
		pc->size--;
		printf("删除成功!\n");
	}
}

//展示联系人信息
void ContactShow(Contact* pc)
{
	printf("%-20s %-10s %-5s %-12s %-30s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (size_t i = 0; i < pc->size; i++)
	{
		printf("%-20s %-10s %-5d %-12s %-30s\n",
			pc->arr[i].name,
			pc->arr[i].gerder,
			pc->arr[i].age,
			pc->arr[i].tel,
			pc->arr[i].addr);
	}
}

//修改联系人信息
void ContactModify(Contact* pc)
{
	char name[NAME_MAX];
	printf("请输入要修改的联系人:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的联系人不存在!\n");
		return;
	}
	else
	{
		//找到了可以修改
		printf("请输入姓名:>");
		scanf("%s", pc->arr[pos].name);
		printf("请输入性别:>");
		scanf("%s", pc->arr[pos].gerder);
		printf("请输入年龄:>");
		scanf("%d", &pc->arr[pos].age);
		printf("请输入电话:>");
		scanf("%s", pc->arr[pos].tel);
		printf("请输入地址:>");
		scanf("%s", pc->arr[pos].addr);
		printf("修改成功!\n");
	}
}

//查找联系人信息
void ContactFind(Contact* pc)
{
	char name[NAME_MAX];
	printf("请输入要查找的联系人:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要查找的联系人不存在!\n");
		return;
	}
	else
	{
		//找到了可以显示
		printf("%-20s %-10s %-5s %-12s %-30s\n", "姓名", "性别", "年龄", "电话", "地址");
		printf("%-20s %-10s %-5d %-12s %-30s\n",
			pc->arr[pos].name,
			pc->arr[pos].gerder,
			pc->arr[pos].age,
			pc->arr[pos].tel,
			pc->arr[pos].addr);
	}
}
