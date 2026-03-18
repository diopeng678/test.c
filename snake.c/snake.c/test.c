
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <locale.h>
//#include "snake.h"
//    
////完成的是游戏的测试逻辑
//void test()
//{
//	int ch = 0;
//	do
//	{
//		system("cls");
//		//创建贪吃蛇
//		Snake snake = { 0 };
//		//初始化游戏
//		//1. 打印环境界面
//		//2. 功能介绍
//		//3. 绘制地图
//		//4. 创建蛇
//		//5. 创建食物
//		//6. 设置游戏的相关信息
//
//		//运行游戏
//		GameRun(&snake);
//		//结束游戏 - 善后工作
//		GameEnd(&snake);
//		SetPos(20, 15);
//		printf("再来一局吗?(Y/N):");
//		ch = getchar();
//		while (getchar() != '\n');
//
//	} while (ch == 'Y' || ch == 'y');
//	SetPos(0, 27);
//}
//
//int main()
//{
//	//设置适配本地环境
//	setlocale(LC_ALL, "");
//	srand((unsigned int)time(NULL));
//	test();
//
//	return 0;
//}
//
//
#define _CRT_SECURE_NO_WARNINGS 1
#include <locale.h>
#include "snake.h"

// 游戏测试逻辑（核心修复：调整GameStart和GameRun的调用顺序）
void test()
{
	int ch = 0;
	do
	{
		system("cls");
		// 初始化贪吃蛇结构体
		Snake snake = { 0 };
		// 核心修复：先执行游戏初始化（创建地图/蛇/食物）
		GameStart(&snake);
		// 再运行游戏逻辑
		GameRun(&snake);
		// 游戏结束，释放资源
		GameEnd(&snake);

		// 再来一局提示
		SetPos(20, 15);
		printf("再来一局吗?(Y/N):");
		ch = getchar();
		while (getchar() != '\n'); // 清空输入缓冲区，避免多次读取

	} while (ch == 'Y' || ch == 'y');

	SetPos(0, 27); // 光标移到地图下方
}

int main()
{
	// 设置本地环境，适配宽字符中文打印（避免乱码）
	setlocale(LC_ALL, "");
	// 初始化随机数种子，让食物坐标随机
	srand((unsigned int)time(NULL));
	// 运行游戏
	test();
	return 0;
}