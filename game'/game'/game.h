#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10


//声明函数

//棋盘初始化的函数
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set);

//打印棋盘
void DisplayBoard(char arr[ROWS][COLS], int row, int col);


//布置雷
void SetMine(char arr[ROWS][COLS], int row, int col);

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);