//

#define _CRT_SECURE_NO_WARNINGS 1  // 修复：去掉多余下划线
#pragma once
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <wchar.h>  // 补充：适配宽字符wprintf

// 游戏常量定义
#define POS_X 24
#define POS_Y 5
#define WALL L'□'
#define BODY L'●'
#define FOOD L'★'

// 蛇的方向（取消手动赋值1，避免冲突，直接用枚举名）
enum DIRECTION
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

// 游戏状态
enum GAME_STATUS
{
	OK, // 正常
	KILL_BY_WALL, // 撞墙
	KILL_BY_SELF, // 撞到自己
	END_NORMAL // 正常退出
};

// 蛇身节点类型
typedef struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode* next;
}SnakeNode, * pSnakeNode;

// 贪吃蛇核心结构体
typedef struct Snake
{
	pSnakeNode _pSnake;    // 蛇头指针
	pSnakeNode _pFood;     // 食物指针
	enum DIRECTION _dir;   // 移动方向
	enum GAME_STATUS _status; // 游戏状态
	int _food_weight;      // 单个食物分值
	int _score;            // 总分
	int _sleep_time;       // 移动间隔（毫秒）
}Snake, * pSnake;

// 函数声明（补充PrintHelpInfo/Pause，与snake.c一一对应）
void SetPos(short x, short y);
void WelcomeToGame();
void CreateMap();
void InitSnake(pSnake ps);
void CreateFood(pSnake ps);
void GameStart(pSnake ps);
void PrintHelpInfo();
void Pause();
int NextIsFood(pSnakeNode pn, pSnake ps);
void EatFood(pSnakeNode pn, pSnake ps);
void NoFood(pSnakeNode pn, pSnake ps);
void KillByWall(pSnake ps);
void KillBySelf(pSnake ps);
void SnakeMove(pSnake ps);
void GameRun(pSnake ps);
void GameEnd(pSnake ps);