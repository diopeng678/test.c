#define _CRT_SECURE_NO_WARNINGS_1

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 15

int snakeX[100], snakeY[100];
int snakeLength = 3;
int foodX, foodY;
int direction = 1;
int gameOver = 0;
int score = 0;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void showCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void drawBorder() {
    int i;
    setColor(15);
    for (i = 0; i <= WIDTH; i++) {
        gotoxy(i, 0);
        printf("*");
        gotoxy(i, HEIGHT);
        printf("*");
    }
    for (i = 0; i <= HEIGHT; i++) {
        gotoxy(0, i);
        printf("*");
        gotoxy(WIDTH, i);
        printf("*");
    }
}

void generateFood() {
    srand(time(0));
    foodX = rand() % (WIDTH - 2) + 1;
    foodY = rand() % (HEIGHT - 2) + 1;
}

void drawFood() {
    setColor(12);
    gotoxy(foodX, foodY);
    printf("@");
}

void drawSnake() {
    int i;
    setColor(10);
    for (i = 0; i < snakeLength; i++) {
        gotoxy(snakeX[i], snakeY[i]);
        if (i == 0)
            printf("O");
        else
            printf("o");
    }
}

void setup() {
    snakeX[0] = WIDTH / 2;
    snakeY[0] = HEIGHT / 2;
    snakeX[1] = WIDTH / 2 - 1;
    snakeY[1] = HEIGHT / 2;
    snakeX[2] = WIDTH / 2 - 2;
    snakeY[2] = HEIGHT / 2;
    generateFood();
}

void moveSnake() {
    int i;
    for (i = snakeLength - 1; i > 0; i--) {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }

    switch (direction) {
    case 1: snakeX[0]++; break;
    case 2: snakeX[0]--; break;
    case 3: snakeY[0]--; break;
    case 4: snakeY[0]++; break;
    }
}

void checkCollision() {
    int i;
    if (snakeX[0] <= 0 || snakeX[0] >= WIDTH || snakeY[0] <= 0 || snakeY[0] >= HEIGHT) {
        gameOver = 1;
    }

    for (i = 1; i < snakeLength; i++) {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
            gameOver = 1;
        }
    }
}

void checkFood() {
    if (snakeX[0] == foodX && snakeY[0] == foodY) {
        score += 10;
        snakeLength++;
        generateFood();
    }
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'd': if (direction != 2) direction = 1; break;
        case 'a': if (direction != 1) direction = 2; break;
        case 'w': if (direction != 4) direction = 3; break;
        case 's': if (direction != 3) direction = 4; break;
        case 'q': gameOver = 1; break;
        }
    }
}

void drawScore() {
    setColor(15);
    gotoxy(WIDTH + 5, 5);
    printf("分数: %d", score);
    gotoxy(WIDTH + 5, 7);
    printf("操作:");
    gotoxy(WIDTH + 5, 8);
    printf("W - 上");
    gotoxy(WIDTH + 5, 9);
    printf("S - 下");
    gotoxy(WIDTH + 5, 10);
    printf("A - 左");
    gotoxy(WIDTH + 5, 11);
    printf("D - 右");
    gotoxy(WIDTH + 5, 13);
    printf("Q - 退出");
}

void clearScreen() {
    system("cls");
}

void gameOverScreen() {
    showCursor();
    clearScreen();
    setColor(12);
    gotoxy(10, 5);
    printf("游戏结束！");
    setColor(15);
    gotoxy(10, 7);
    printf("最终分数: %d", score);
    gotoxy(10, 9);
    printf("按任意键退出...");
    _getch();
}

int main() {
    system("title 贪吃蛇游戏");
    hideCursor();
    clearScreen();
    setup();

    while (!gameOver) {
        gotoxy(0, 0);
        drawBorder();
        drawSnake();
        drawFood();
        drawScore();
        input();
        moveSnake();
        checkCollision();
        checkFood();
        Sleep(200);
        clearScreen();
    }

    gameOverScreen();
    return 0;
}
