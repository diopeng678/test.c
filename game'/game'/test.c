#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


void menu()
{
	printf("**********************\n");
	printf("***** 1. play    *****\n");
	printf("***** 0. exit    *****\n");
	printf("**********************\n");
}

void game()
{
	//完成扫雷游戏
	//mine数组中存放布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };//数组全部初始化为'0'

	//show数组中存放排查出的雷的信息
	char show[ROWS][COLS] = { 0 };//数组全部初始化为'*'

	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//布置雷
	//就9*9的棋盘上随机布置10个雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//打印棋盘
	DisplayBoard(show, ROW, COL);

	//排查雷
	FindMine(mine, show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);//1 0 x
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束，退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}

	} while (input);
}

int main()
{
	test();
	return 0;
}
