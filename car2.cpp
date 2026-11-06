
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int W = 80;
const int H = 25;

const int ROAD_LEFT = 4;
const int ROAD_RIGHT = 55;
const int CAR_Y = 19;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

CHAR_INFO frame[H][W];

int carX = 29;
int score = 0;

struct Enemy {
    int x, y;
    bool active;
};

Enemy enemies[2];

// Colors
const WORD WHITE = 15;
const WORD YELLOW = 14;
const WORD RED = 12;
const WORD GREEN = 10;
const WORD CYAN = 11;

// --------------------------------
// Screen drawing
// --------------------------------

void put(int x, int y, char c, WORD color = WHITE) {
    if (x < 0 || x >= W || y < 0 || y >= H)
        return;

    frame[y][x].Char.AsciiChar = c;
    frame[y][x].Attributes = color;
}

void writeText(int x, int y, const char* str,
               WORD color = WHITE) {
    while (*str) {
        put(x++, y, *str++, color);
    }
}

void clearFrame() {
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            put(x, y, ' ');
        }
    }
}

void showFrame() {
    COORD size = {W, H};
    COORD origin = {0, 0};

    SMALL_RECT area = {0, 0, W - 1, H - 1};

    WriteConsoleOutputA(
        hConsole,
        &frame[0][0],
        size,
        origin,
        &area
    );
}

// --------------------------------
// Road
// --------------------------------

void drawRoad() {

    for (int y = 0; y < H; y++) {

        put(ROAD_LEFT, y, '|', WHITE);
        put(ROAD_LEFT + 1, y, '|', WHITE);

        put(ROAD_RIGHT - 1, y, '|', WHITE);
        put(ROAD_RIGHT, y, '|', WHITE);

        // Lane markings
        if ((y % 6) < 3) {
            put(20, y, '|', YELLOW);
            put(36, y, '|', YELLOW);
        }
    }

    // Side panel separator
    for (int y = 0; y < H; y++)
        put(59, y, '|', CYAN);
}

// --------------------------------
// Player car
// --------------------------------

void drawPlayer() {

    const char* car[] = {
        " [] ",
        "####",
        "####",
        " [] "
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            if (car[i][j] != ' ')
                put(carX + j, CAR_Y + i,
                    car[i][j], GREEN);
        }
    }
}

// --------------------------------
// Enemy cars
// --------------------------------

void drawEnemy(int i) {

    if (!enemies[i].active)
        return;

    const char* car[] = {
        " [] ",
        "####",
        "####",
        " [] "
    };

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {

            if (car[y][x] != ' ')
                put(enemies[i].x + x,
                    enemies[i].y + y,
                    car[y][x], RED);
        }
    }
}

void spawnEnemy(int i) {

    int lanes[] = {10, 26, 42};

    enemies[i].x = lanes[rand() % 3];
    enemies[i].y = -4;
    enemies[i].active = true;
}

// --------------------------------
// Collision
// --------------------------------

bool collision(int i) {

    if (!enemies[i].active)
        return false;

    int ex = enemies[i].x;
    int ey = enemies[i].y;

    return (
        carX < ex + 4 &&
        carX + 4 > ex &&
        CAR_Y < ey + 4 &&
        CAR_Y + 4 > ey
    );
}

// --------------------------------
// Game information
// --------------------------------

void drawInformation() {

    writeText(63, 2, "CAR GAME", CYAN);
    writeText(63, 3, "--------", WHITE);

    char buffer[30];

    sprintf(buffer, "Score: %d", score);

    writeText(63, 6, buffer, YELLOW);

    writeText(63, 10, "CONTROLS", CYAN);
    writeText(63, 12, "A / LEFT", WHITE);
    writeText(63, 13, "D / RIGHT", WHITE);

    writeText(63, 16, "ESC: EXIT", RED);

    writeText(63, 21, "GOOD LUCK!", GREEN);
}

// --------------------------------
// Game over
// --------------------------------

void gameOver() {

    clearFrame();

    writeText(25, 7, "==========================", RED);
    writeText(25, 9, "        GAME OVER         ", RED);
    writeText(25, 11, "==========================", RED);

    char buffer[40];

    sprintf(buffer, "YOUR SCORE: %d", score);

    writeText(32, 14, buffer, YELLOW);

    writeText(23, 18, "Press any key to return to menu", WHITE);

    showFrame();

    getch();
}

// --------------------------------
// Instructions
// --------------------------------

void instructions() {

    clearFrame();

    writeText(30, 4, "INSTRUCTIONS", CYAN);

    writeText(15, 8, "Avoid the incoming enemy cars.", WHITE);
    writeText(15, 10, "A / LEFT  - Move left", GREEN);
    writeText(15, 12, "D / RIGHT - Move right", GREEN);
    writeText(15, 14, "ESC       - Exit game", RED);

    writeText(15, 19, "Press any key to return", YELLOW);

    showFrame();

    getch();
}

// --------------------------------
// Main gameplay
// --------------------------------

void play() {

    carX = 29;
    score = 0;

    enemies[0].active = true;
    enemies[0].x = 10;
    enemies[0].y = -4;

    enemies[1].active = true;
    enemies[1].x = 42;
    enemies[1].y = -17;

    clearFrame();

    writeText(15, 10, "PRESS ANY KEY TO START", YELLOW);

    showFrame();

    getch();

    bool running = true;

    while (running) {

        // Continuous keyboard movement

        if (GetAsyncKeyState('A') & 0x8000 ||
            GetAsyncKeyState(VK_LEFT) & 0x8000) {

            if (carX > ROAD_LEFT + 3)
                carX--;
        }

        if (GetAsyncKeyState('D') & 0x8000 ||
            GetAsyncKeyState(VK_RIGHT) & 0x8000) {

            if (carX < ROAD_RIGHT - 5)
                carX++;
        }

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
            break;

        // Check collisions

        for (int i = 0; i < 2; i++) {

            if (collision(i)) {
                running = false;
                break;
            }
        }

        if (!running)
            break;

        // Draw complete frame

        clearFrame();

        drawRoad();
        drawInformation();
        drawPlayer();

        for (int i = 0; i < 2; i++)
            drawEnemy(i);

        showFrame();

        // Update enemy positions

        for (int i = 0; i < 2; i++) {

            enemies[i].y++;

            if (enemies[i].y > H) {

                spawnEnemy(i);
                score++;
            }
        }

        Sleep(45);
    }

    if (!running)
        gameOver();
}

// --------------------------------
// Main menu
// --------------------------------

int main() {

    srand((unsigned)time(NULL));

    // Hide cursor

    CONSOLE_CURSOR_INFO cursor;

    cursor.bVisible = FALSE;
    cursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &cursor);

    // Set console dimensions

    SMALL_RECT window = {0, 0, W - 1, H - 1};

    SetConsoleWindowInfo(hConsole, TRUE, &window);

    COORD bufferSize = {W, H};

    SetConsoleScreenBufferSize(hConsole, bufferSize);

    SetConsoleWindowInfo(hConsole, TRUE, &window);

    SetConsoleTitleA("C++ Car Racing Game");

    while (true) {

        clearFrame();

        writeText(25, 4, "==========================", CYAN);
        writeText(25, 6, "        CAR GAME          ", GREEN);
        writeText(25, 8, "==========================", CYAN);

        writeText(28, 12, "1. START GAME", WHITE);
        writeText(28, 14, "2. INSTRUCTIONS", WHITE);
        writeText(28, 16, "3. QUIT", RED);

        writeText(28, 20, "Select option: ", YELLOW);

        showFrame();

        char option = getch();

        if (option == '1') {
            play();
        }

        else if (option == '2') {
            instructions();
        }

        else if (option == '3') {
            break;
        }
    }

    return 0;
}
