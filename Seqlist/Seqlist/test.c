#include"seqlist.h"

void menu()
{
	printf("***************************\n");
	printf("***** 1.添加联系人 ********\n");
	printf("***** 2.删除联系人 ********\n");
	printf("***** 3.查找联系人 ********\n");
	printf("***** 4.修改联系人 ********\n");
	printf("***** 5.显示联系人 ********\n");
	printf("***** 0.退出通讯录 ********\n");
	printf("***************************\n");
}	

int main() {
		Contact con;
	ContactInit(&con);//初始化通讯录
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			ContactAdd(&con);
			break;
		case 2:
			ContactDel(&con);
			break;
		case 3:
			ContactFind(&con);
			break;
		case 4:
			ContactModify(&con);
			break;
		case 5:
			ContactShow(&con);
			break;
		case 0:
			printf("欢迎下次使用!\n");
			break;
		default:
			printf("选择错误请重新选择!\n");
			break;
		}
	} while (input);
	ContactDesTory(&con);//销毁通讯录
	return 0;
}


