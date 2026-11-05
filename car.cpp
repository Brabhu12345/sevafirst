#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>

using namespace std;

#define WIDTH 91
#define HEIGHT 26
#define WIN_WIDTH 70

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

CHAR_INFO screen[HEIGHT][WIDTH];

int enemyX[2], enemyY[2];
bool enemyFlag[2];
int carPos, score;

void put(int x, int y, char c) {
if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
return;

screen[y][x].Char.AsciiChar = c;
screen[y][x].Attributes = FOREGROUND_RED |
    FOREGROUND_GREEN | FOREGROUND_BLUE;

}

void text(int x, int y, const char* str) {
while (*str) {
put(x++, y, *str++);
}
}

void clearFrame() {
for (int y = 0; y < HEIGHT; y++) {
for (int x = 0; x < WIDTH; x++) {
put(x, y, ' ');
}
}
}

void drawBorder() {
for (int y = 0; y < HEIGHT; y++) {
for (int x = 0; x < 17; x++) {
put(x, y, '#');
put(WIN_WIDTH - x, y, '#');
}
put(90, y, '#');
}
}

void drawCar() {
const char* car[] = {
" ## ",
"####",
" ## ",
"####"
};

for (int i = 0; i < 4; i++)
    text(carPos, 22 + i, car[i]);

}

void drawEnemy(int i) {
if (!enemyFlag[i]) return;

const char* enemy[] = {
    "****",
    " ** ",
    "****",
    " ** "
};

for (int j = 0; j < 4; j++)
    text(enemyX[i], enemyY[i] + j, enemy[j]);

}

void genEnemy(int i) {
enemyX[i] = 19 + rand() % 32;
}

void resetEnemy(int i) {
enemyY[i] = 1;
genEnemy(i);
}

void displayFrame() {
COORD size = { WIDTH, HEIGHT };
COORD origin = { 0, 0 };

SMALL_RECT rect = { 0, 0, WIDTH - 1, HEIGHT - 1 };

WriteConsoleOutputA(
    console,
    (CHAR_INFO*)screen,
    size,
    origin,
    &rect
);

}

bool collision(int i) {
if (enemyFlag[i] && enemyY[i] + 4 >= 23) {
if (enemyX[i] + 4 > carPos &&
enemyX[i] < carPos + 4)
return true;
}

return false;

}

void gameover() {
clearFrame();

text(30, 8, "--------------------------");
text(30, 9, "        GAME OVER         ");
text(30, 10, "--------------------------");
text(25, 13, "Press any key to return to menu");

displayFrame();
getch();

}

void instructions() {
clearFrame();

text(10, 5, "INSTRUCTIONS");
text(10, 7, "Avoid enemy cars.");
text(10, 9, "A - Move Left");
text(10, 10, "D - Move Right");
text(10, 11, "ESC - Exit Game");
text(10, 14, "Press any key to return");

displayFrame();
getch();

}

void play() {
carPos = 34;
score = 0;

enemyFlag[0] = true;
enemyFlag[1] = false;

enemyY[0] = enemyY[1] = 1;

genEnemy(0);
genEnemy(1);

clearFrame();
drawBorder();

text(77, 2, "CAR GAME");
text(77, 4, "--------");
text(77, 6, "Score:");

text(77, 12, "CONTROL");
text(77, 14, "A - Left");
text(77, 15, "D - Right");

text(18, 5, "Press any key to start");

displayFrame();
getch();

bool running = true;

while (running) {

    if (_kbhit()) {
        char ch = _getch();

        if (ch == 'a' || ch == 'A') {
            if (carPos > 18)
                carPos -= 4;
        }

        if (ch == 'd' || ch == 'D') {
            if (carPos < 50)
                carPos += 4;
        }

        if (ch == 27)
            break;
    }

    for (int i = 0; i < 2; i++) {
        if (collision(i)) {
            running = false;
            break;
        }
    }

    if (!running)
        break;

    clearFrame();
    drawBorder();

    text(77, 2, "CAR GAME");
    text(77, 4, "--------");

    char scoreText[30];
    sprintf(scoreText, "Score: %d", score);
    text(77, 6, scoreText);

    text(77, 12, "CONTROL");
    text(77, 14, "A - Left");
    text(77, 15, "D - Right");

    drawCar();

    for (int i = 0; i < 2; i++)
        drawEnemy(i);

    displayFrame();

    Sleep(65);

    for (int i = 0; i < 2; i++) {
        if (enemyFlag[i])
            enemyY[i]++;
    }

    if (enemyY[0] == 10)
        enemyFlag[1] = true;

    for (int i = 0; i < 2; i++) {
        if (enemyY[i] > HEIGHT - 4) {
            resetEnemy(i);
            score++;
        }
    }
}

if (!running)
    gameover();

}

int main() {

srand((unsigned)time(NULL));

// Hide cursor
CONSOLE_CURSOR_INFO cursor;
cursor.bVisible = FALSE;
cursor.dwSize = 1;
SetConsoleCursorInfo(console, &cursor);

// Resize console
SMALL_RECT small = { 0, 0, 0, 0 };
SetConsoleWindowInfo(console, TRUE, &small);

COORD bufferSize = { WIDTH, HEIGHT };
SetConsoleScreenBufferSize(console, bufferSize);

SMALL_RECT window = { 0, 0, WIDTH - 1, HEIGHT - 1 };
SetConsoleWindowInfo(console, TRUE, &window);

while (true) {

    clearFrame();

    text(10, 5, "--------------------------");
    text(10, 6, "        CAR GAME          ");
    text(10, 7, "--------------------------");

    text(10, 9, "1. Start Game");
    text(10, 10, "2. Instructions");
    text(10, 11, "3. Quit");
    text(10, 13, "Select option:");

    displayFrame();

    char op = getch();

    if (op == '1')
        play();

    else if (op == '2')
        instructions();

    else if (op == '3')
        break;
}

return 0;

}