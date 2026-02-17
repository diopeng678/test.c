#define _CRT_SECURE_NO_WARNINGS_1

#include <windows.h>
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define PADDLE_WIDTH 120
#define PADDLE_HEIGHT 15
#define BALL_RADIUS 8
#define BRICK_ROWS 5
#define BRICK_COLS 8
#define BRICK_WIDTH 80
#define BRICK_HEIGHT 30
#define BRICK_GAP 10
#define BRICK_START_X 50
#define BRICK_START_Y 80

typedef struct {
    int x, y;
    int width, height;
    int active;
} Brick;

typedef struct {
    float x, y;
    float dx, dy;
    int radius;
} Ball;

typedef struct {
    int x, y;
    int width, height;
} Paddle;

HWND hwnd;
HFONT hFont;
HBRUSH hBrushPaddle;
HBRUSH hBrushBall;
HBRUSH hBrushes[7];
HPEN hPenBorder;
Ball ball;
Paddle paddle;
Brick bricks[BRICK_ROWS][BRICK_COLS];
int gameOver = 0;
int score = 0;
int gameStarted = 0;

void initGame() {
    int i, j;
    for (i = 0; i < BRICK_ROWS; i++) {
        for (j = 0; j < BRICK_COLS; j++) {
            bricks[i][j].x = BRICK_START_X + j * (BRICK_WIDTH + BRICK_GAP);
            bricks[i][j].y = BRICK_START_Y + i * (BRICK_HEIGHT + BRICK_GAP);
            bricks[i][j].width = BRICK_WIDTH;
            bricks[i][j].height = BRICK_HEIGHT;
            bricks[i][j].active = 1;
        }
    }

    paddle.x = WINDOW_WIDTH / 2 - PADDLE_WIDTH / 2;
    paddle.y = WINDOW_HEIGHT - 60;
    paddle.width = PADDLE_WIDTH;
    paddle.height = PADDLE_HEIGHT;

    ball.x = paddle.x + paddle.width / 2;
    ball.y = paddle.y - BALL_RADIUS - 5;
    ball.dx = 4.0f;
    ball.dy = -4.0f;
    ball.radius = BALL_RADIUS;

    gameOver = 0;
    gameStarted = 0;
}

int checkCollision(int ax, int ay, int aw, int ah, int bx, int by, int bw, int bw2) {
    return ax < bx + bw && ax + aw > bx && ay < by + bw2 && ay + ah > by;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE: {
        hFont = CreateFontA(24, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Arial");
        hBrushPaddle = CreateSolidBrush(RGB(100, 200, 255));
        hBrushBall = CreateSolidBrush(RGB(255, 200, 100));
        hBrushes[0] = CreateSolidBrush(RGB(255, 100, 100));
        hBrushes[1] = CreateSolidBrush(RGB(255, 150, 100));
        hBrushes[2] = CreateSolidBrush(RGB(255, 255, 100));
        hBrushes[3] = CreateSolidBrush(RGB(100, 255, 100));
        hBrushes[4] = CreateSolidBrush(RGB(100, 200, 255));
        hBrushes[5] = CreateSolidBrush(RGB(200, 100, 255));
        hBrushes[6] = CreateSolidBrush(RGB(255, 150, 200));
        hPenBorder = CreatePen(PS_SOLID, 2, RGB(50, 50, 50));
        initGame();
        SetTimer(hwnd, 1, 16, NULL);
        break;
    }
    case WM_TIMER: {
        if (!gameOver) {
            if (!gameStarted) {
                ball.x = paddle.x + paddle.width / 2;
                ball.y = paddle.y - BALL_RADIUS - 5;
            }
            else {
                ball.x += ball.dx;
                ball.y += ball.dy;

                if (ball.x - ball.radius <= 0 || ball.x + ball.radius >= WINDOW_WIDTH) {
                    ball.dx = -ball.dx;
                }
                if (ball.y - ball.radius <= 0) {
                    ball.dy = -ball.dy;
                }
                if (ball.y + ball.radius >= WINDOW_HEIGHT) {
                    gameOver = 1;
                }

                if (checkCollision((int)(ball.x - ball.radius), (int)(ball.y - ball.radius),
                    ball.radius * 2, ball.radius * 2,
                    paddle.x, paddle.y, paddle.width, paddle.height)) {
                    ball.dy = -ball.dy;
                    ball.y = paddle.y - ball.radius - 1;

                    float hitPos = (ball.x - paddle.x) / (float)paddle.width;
                    ball.dx = (hitPos - 0.5f) * 10.0f;
                    if (ball.dx > 6.0f) ball.dx = 6.0f;
                    if (ball.dx < -6.0f) ball.dx = -6.0f;
                }

                int i, j;
                for (i = 0; i < BRICK_ROWS; i++) {
                    for (j = 0; j < BRICK_COLS; j++) {
                        if (bricks[i][j].active && checkCollision((int)(ball.x - ball.radius), (int)(ball.y - ball.radius),
                            ball.radius * 2, ball.radius * 2,
                            bricks[i][j].x, bricks[i][j].y, bricks[i][j].width, bricks[i][j].height)) {
                            bricks[i][j].active = 0;
                            ball.dy = -ball.dy;
                            score += 10;
                        }
                    }
                }
            }
        }
        InvalidateRect(hwnd, NULL, FALSE);
        break;
    }
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        RECT rect;
        GetClientRect(hwnd, &rect);
        FillRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));

        SelectObject(hdc, hPenBorder);
        SelectObject(hdc, hBrushPaddle);
        Rectangle(hdc, paddle.x, paddle.y, paddle.x + paddle.width, paddle.y + paddle.height);

        SelectObject(hdc, hBrushBall);
        Ellipse(hdc, (int)(ball.x - ball.radius), (int)(ball.y - ball.radius),
            (int)(ball.x + ball.radius), (int)(ball.y + ball.radius));

        int i, j;
        for (i = 0; i < BRICK_ROWS; i++) {
            for (j = 0; j < BRICK_COLS; j++) {
                if (bricks[i][j].active) {
                    SelectObject(hdc, hBrushes[i % 7]);
                    Rectangle(hdc, bricks[i][j].x, bricks[i][j].y,
                        bricks[i][j].x + bricks[i][j].width,
                        bricks[i][j].y + bricks[i][j].height);
                }
            }
        }

        char scoreText[50];
        sprintf(scoreText, "Score: %d", score);
        SelectObject(hdc, hFont);
        SetTextColor(hdc, RGB(255, 255, 255));
        SetBkMode(hdc, TRANSPARENT);
        TextOutA(hdc, 20, 20, scoreText, strlen(scoreText));

        if (!gameStarted && !gameOver) {
            TextOutA(hdc, WINDOW_WIDTH / 2 - 120, WINDOW_HEIGHT / 2 - 50, "Press SPACE to start", 17));
        }

        if (gameOver) {
            SetTextColor(hdc, RGB(255, 100, 100));
            TextOutA(hdc, WINDOW_WIDTH / 2 - 80, WINDOW_HEIGHT / 2 - 30, "Game Over!", 10));
            TextOutA(hdc, WINDOW_WIDTH / 2 - 120, WINDOW_HEIGHT / 2 + 10, "Press R to restart", 18));
        }

        EndPaint(hwnd, &ps);
        break;
    }
    case WM_KEYDOWN: {
        switch (wParam) {
        case VK_LEFT:
            if (paddle.x > 0) paddle.x -= 15;
            break;
        case VK_RIGHT:
            if (paddle.x + paddle.width < WINDOW_WIDTH) paddle.x += 15;
            break;
        case VK_SPACE:
            if (!gameStarted) {
                gameStarted = 1;
            }
            break;
        case 'R':
        case 'r':
            if (gameOver) {
                initGame();
            }
            break;
        }
        break;
    }
    case WM_DESTROY: {
        DeleteObject(hFont);
        DeleteObject(hBrushPaddle);
        DeleteObject(hBrushBall);
        int i;
        for (i = 0; i < 7; i++) {
            DeleteObject(hBrushes[i]);
        }
        DeleteObject(hPenBorder);
        KillTimer(hwnd, 1);
        PostQuitMessage(0);
        break;
    }
    default: {
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "BreakoutGame";

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    RegisterClass(&wc);

    hwnd = CreateWindowExA(
        0,
        CLASS_NAME,
        "Breakout Game - Classic Arcade",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
        CW_USEDEFAULT, CW_USEDEFAULT,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
