#define _CRT_SECURE_NO_WARNINGS_1


#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define MINES 10

#define UNREVEALED '#'
#define REVEALED ' '
#define MINE '*'
#define MARKED 'F'

char board[HEIGHT][WIDTH];
char revealed[HEIGHT][WIDTH];
int mineCount[HEIGHT][WIDTH];
int gameOver = 0;
int win = 0;
int minesLeft = MINES;

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

void clearScreen() {
    system("cls");
}

void initializeBoard() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            board[i][j] = ' ';
            revealed[i][j] = UNREVEALED;
            mineCount[i][j] = 0;
        }
    }
}

void placeMines(int startX, int startY) {
    int i, j, k;
    srand(time(0));

    for (k = 0; k < MINES;) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;

        if (board[y][x] != MINE && !(x == startX && y == startY)) {
            board[y][x] = MINE;
            k++;
        }
    }
}

void calculateMineCounts() {
    int i, j, dx, dy;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (board[i][j] == MINE) {
                for (dx = -1; dx <= 1; dx++) {
                    for (dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        int nx = j + dx;
                        int ny = i + dy;
                        if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
                            mineCount[ny][nx]++;
                        }
                    }
                }
            }
        }
    }
}

void drawBoard(int cursorX, int cursorY) {
    int i, j;
    gotoxy(0, 0);

    setColor(15);
    printf("    ");
    for (i = 0; i < WIDTH; i++) {
        printf("%2d ", i + 1);
    }
    printf("\n");

    printf("   ");
    for (i = 0; i < WIDTH * 3 + 1; i++) {
        printf("-");
    }
    printf("\n");

    for (i = 0; i < HEIGHT; i++) {
        setColor(15);
        printf("%2d |", i + 1);

        for (j = 0; j < WIDTH; j++) {
            if (i == cursorY && j == cursorX) {
                setColor(11);
                printf("[");
                setColor(14);
            }
            else {
                setColor(15);
                printf(" ");
            }

            if (revealed[i][j] == REVEALED) {
                if (board[i][j] == MINE) {
                    setColor(12);
                    printf("%c", MINE);
                }
                else if (mineCount[i][j] > 0) {
                    switch (mineCount[i][j]) {
                    case 1: setColor(11); break;
                    case 2: setColor(10); break;
                    case 3: setColor(12); break;
                    case 4: setColor(14); break;
                    case 5: setColor(13); break;
                    case 6: setColor(9); break;
                    case 7: setColor(8); break;
                    case 8: setColor(7); break;
                    }
                    printf("%d", mineCount[i][j]);
                }
                else {
                    setColor(15);
                    printf(" ");
                }
            }
            else {
                if (revealed[i][j] == MARKED) {
                    setColor(13);
                    printf("%c", MARKED);
                }
                else {
                    setColor(15);
                    printf("%c", UNREVEALED);
                }
            }

            if (i == cursorY && j == cursorX) {
                setColor(14);
                printf("]");
            }
            else {
                setColor(15);
                printf(" ");
            }
        }
        setColor(15);
        printf("|\n");
    }

    printf("   ");
    for (i = 0; i < WIDTH * 3 + 1; i++) {
        printf("-");
    }
    printf("\n");

    setColor(15);
    gotoxy(0, HEIGHT + 5);
    printf("地雷剩余: %d\n", minesLeft);
    printf("操作:\n");
    printf("WASD - 移动光标\n");
    printf("空格键 - 揭示格子\n");
    printf("F键 - 标记/取消标记地雷\n");
    printf("Q键 - 退出游戏\n");

    if (gameOver) {
        setColor(12);
        gotoxy(0, HEIGHT + 15);
        if (win) {
            printf("恭喜你赢了！\n");
        }
        else {
            printf("游戏结束！你踩中了地雷！\n");
        }
        printf("按任意键退出...\n");
    }
}

void reveal(int x, int y) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT || revealed[y][x] == REVEALED) {
        return;
    }

    if (revealed[y][x] == MARKED) {
        return;
    }

    revealed[y][x] = REVEALED;

    if (board[y][x] == MINE) {
        gameOver = 1;
        win = 0;
        return;
    }

    if (mineCount[y][x] == 0) {
        int dx, dy;
        for (dx = -1; dx <= 1; dx++) {
            for (dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;
                reveal(x + dx, y + dy);
            }
        }
    }
}

void toggleMark(int x, int y) {
    if (revealed[y][x] == REVEALED) {
        return;
    }

    if (revealed[y][x] == MARKED) {
        revealed[y][x] = UNREVEALED;
        minesLeft++;
    }
    else {
        revealed[y][x] = MARKED;
        minesLeft--;
    }
}

void checkWin() {
    int i, j, revealedCount = 0;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (revealed[i][j] == REVEALED) {
                revealedCount++;
            }
        }
    }

    if (revealedCount == WIDTH * HEIGHT - MINES) {
        gameOver = 1;
        win = 1;
    }
}

void revealAll() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            revealed[i][j] = REVEALED;
        }
    }
}

int main() {
    int cursorX = 0, cursorY = 0;
    char key;

    system("title 扫雷游戏");
    clearScreen();
    hideCursor();

    initializeBoard();

    while (1) {
        clearScreen();
        drawBoard(cursorX, cursorY);

        key = _getch();

        switch (key) {
        case 'w':
        case 'W':
            if (cursorY > 0) cursorY--;
            break;
        case 's':
        case 'S':
            if (cursorY < HEIGHT - 1) cursorY++;
            break;
        case 'a':
        case 'A':
            if (cursorX > 0) cursorX--;
            break;
        case 'd':
        case 'D':
            if (cursorX < WIDTH - 1) cursorX++;
            break;
        case ' ':
            if (!gameOver) {
                if (minesLeft == MINES) {
                    placeMines(cursorX, cursorY);
                    calculateMineCounts();
                }
                reveal(cursorX, cursorY);
                if (!gameOver) {
                    checkWin();
                }
                else if (!win) {
                    revealAll();
                }
            }
            break;
        case 'f':
        case 'F':
            if (!gameOver) {
                toggleMark(cursorX, cursorY);
            }
            break;
        case 'q':
        case 'Q':
            gameOver = 1;
            break;
        }

        if (gameOver) {
            clearScreen();
            drawBoard(cursorX, cursorY);
            showCursor();
            _getch();
            break;
        }
    }

    return 0;
}
