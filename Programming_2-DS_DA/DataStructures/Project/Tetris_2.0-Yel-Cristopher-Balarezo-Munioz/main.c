#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

void gotoxy(int x,int y);
void buildField(void);
void printField(void);
void play(void);
void setStone(void);
void updateField(bool p);
void goHorizontaly(char r);
void dropStone(void);
bool stepDown(bool free);
void controlRows(void);
void rotate(void);
int leerPuntajeAlto(void);
void escribirScore(int score);
void askForName();
void newLevel();
void openFullScreen();
void GameOver();

_Bool field[38-20][30-10];
bool alive;
int status;
int stage;
int xStone[4];
int yStone[4];
bool stone;
int score;
int level;
int highScore;
char name[15];
char bestHighScoreNickname[15];

// Time Variables //
int minutes = 0, seconds = 0;
time_t start_time;


int stones[7][4][2] =
{
    {{3, 1}, {4, 1}, {5, 1}, {6, 1}}, // straight stone
    {{3, 1}, {3, 2}, {4, 2}, {5, 2}}, // LL
    {{3, 2}, {4, 2}, {5, 2}, {5, 1}}, // RL
    {{4, 1}, {5, 1}, {4, 2}, {5, 2}}, // square
    {{3, 1}, {4, 1}, {4, 2}, {5, 2}}, // LZ
    {{3, 2}, {4, 2}, {4, 1}, {5, 1}}, // RZ
    {{3, 2}, {4, 2}, {5, 2}, {4, 1}}  // car stone
};
int rotation[7][4][4][2] =
{
    {
        // straight stone
        {{1, -1}, {0, 0}, {-1, 1}, {-2, 2}},
        {{-1, 1}, {0, 0}, {1, -1}, {2, -2}},
        {{1, -1}, {0, 0}, {-1, 1}, {-2, 2}},
        {{-1, 1}, {0, 0}, {1, -1}, {2, -2}}
    },
    {
        // LL
        {{2, 0}, {1, -1}, {0, 0}, {-1, 1}},
        {{0, 2}, {1, 1}, {0, 0}, {-1, -1}},
        {{-2, 0}, {-1, 1}, {0, 0}, {1, -1}},
        {{0, -2}, {-1, -1}, {0, 0}, {1, 1}}
    },
    {
        // RL
        {{1, -1}, {0, 0}, {-1, 1}, {0, 2}},
        {{1, 1}, {0, 0}, {-1, -1}, {-2, 0}},
        {{-1, 1}, {0, 0}, {1, -1}, {0, -2}},
        {{-1, -1}, {0, 0}, {1, 1}, {2, 0}}
    },
    {
        // square
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}}
    },
    {
        // LZ
        {{2, 0}, {1, 1}, {0, 0}, {-1, 1}},
        {{-2, 0}, {-1, -1}, {0, 0}, {1, -1}},
        {{2, 0}, {1, 1}, {0, 0}, {-1, 1}},
        {{-2, 0}, {-1, -1}, {0, 0}, {1, -1}}
    },
    {
        // RZ
        {{1, -1}, {0, 0}, {1, 1}, {0, 2}},
        {{-1, 1}, {0, 0}, {-1, -1}, {0, -2}},
        {{1, -1}, {0, 0}, {1, 1}, {0, 2}},
        {{-1, 1}, {0, 0}, {-1, -1}, {0, -2}}
    },
    {
        // car stone
        {{1, -1}, {0, 0}, {-1, 1}, {1, 1}},
        {{1, 1}, {0, 0}, {-1, -1}, {-1, 1}},
        {{-1, 1}, {0, 0}, {1, -1}, {-1, -1}},
        {{-1, -1}, {0, 0}, {1, 1}, {1, -1}}
    }
};

void openFullScreen() {
    // Obtener un handle a la consola actual
    HWND hwnd = GetConsoleWindow();

    // Maximizar la ventana
    ShowWindow(hwnd, SW_MAXIMIZE);
}

void askForName() {
    system("cls");
    gotoxy(15, 10);
    printf("\t%c  Ingrese su nombre:  ", 219);
    fflush(stdin);
    scanf("%s", &name);
}


int main(void)
{
    // abre la ventana a pantalla completa
    openFullScreen();

    // obtener el tiempo actual
    start_time = time(NULL);

    highScore = leerPuntajeAlto();
    score = 0;
    stone = false;
    askForName();

    buildField();
    setStone();
    play();
    escribirScore(score);

    return 0;
}

void play(void)
{
    alive = true;
    char r = ' ';
    while(alive)
    {
        stepDown(true);
        Sleep(200);

        // Actualiza el tablero
        updateField(true);

        while(_kbhit())   // Comprobar si hay entrada de teclado
        {
            r = getch(); // Leer la entrada de teclado

            switch(r)
            {
            case 'w':
                rotate();
                break;
            case 's':
                dropStone();
                break;
            case 'a':
                goHorizontaly(r);
                break;
            case 'd':
                goHorizontaly(r);
                break;
            case 'q':
                alive = false;
                break;
            /*
            default:
                printField();
                break;
            */
            }
        }
    }

    GameOver();
}

void rotate(void)
{
    int xTemp[4];
    int yTemp[4];
    bool free = true;
    for(int i = 0; i < sizeof(xStone) / sizeof(int); i++)
    {
        xTemp[i] = xStone[i];
        yTemp[i] = yStone[i];
    }
    for(int i2 = 0; i2 < sizeof(xStone) / sizeof(int); i2++)
    {
        if(xStone[i2] + rotation[status][stage][i2][0] < 0 ||
                xStone[i2] + rotation[status][stage][i2][0] >= sizeof(field) / sizeof(field[0]) ||
                yStone[i2] + rotation[status][stage][i2][1] < 0 ||
                yStone[i2] + rotation[status][stage][i2][1] >= sizeof(field[0]))
        {
            free = false;
        }
        if(free)
        {
            for(int i = 0; i < sizeof(xStone) / sizeof(int); i++)
            {
                field[xTemp[i]][yTemp[i]] = 0;
            }
        }
        if(free &&
                field[xStone[i2] + rotation[status][stage][i2][0]][yStone[i2] + rotation[status][stage][i2][1]] != 1)
        {
            xStone[i2] += rotation[status][stage][i2][0];
            yStone[i2] += rotation[status][stage][i2][1];
        }
        else
        {
            free = false;
        }
    }
    if(!free)
    {
        for(int i = 0; i < sizeof(xStone) / sizeof(int); i++)
        {
            xStone[i] = xTemp[i];
            yStone[i] = yTemp[i];
            field[xTemp[i]][yTemp[i]] = 1;
        }
    }
    else
    {
        stage = stage == 3 ? 0 : stage + 1;
    }
    updateField(true);
}

void controlRows(void)
{
    int rows = 0;
    for(int y = 0; y < sizeof(field[0]); y++)
    {
        bool ful = true;
        for(int x = 0; x < sizeof(field) / sizeof(field[0]); x++)
        {
            if(field[x][y] == 0)
            {
                ful = false;
            }
        }
        if(ful)
        {
            rows++;
            for(int x = 0; x < sizeof(field) / sizeof(field[0]); x++)
            {
                field[x][y] = 0;
            }
            for(int y2 = y; y2 > 0; y2--)
            {
                for(int x = 0; x < sizeof(field) / sizeof(field[0]); x++)
                {
                    field[x][y2] = field[x][y2 - 1];
                }
            }
        }
    }
    switch(rows)
    {
    case 1:
        score += 10;
        break;
    case 2:
        score += 25;
        break;
    case 3:
        score += 55;
        break;
    case 4:
        score += 80;
        break;
    }
    if(rows > 0)
    {
        printField();
    }
}

void dropStone()
{
    bool free = true;
    while(free)
    {
        free = stepDown(free);
    }
}

bool stepDown(bool free)
{
    for(int i = 0; i < sizeof(xStone) / sizeof(int); i++)
    {
        if(yStone[i] + 1 >= sizeof(field[0]))
        {
            free = false;
        }
        if(field[xStone[i]][yStone[i] + 1] == 1 && free)
        {
            bool other = true;
            for(int i2 = 0; i2 < sizeof(xStone) / sizeof(int); i2++)
            {
                if(xStone[i] == xStone[i2] && yStone[i] + 1 == yStone[i2])
                {
                    other = false;
                }
            }
            if(other)
            {
                free = false;
            }
        }
    }
    if(free)
    {
        for(int i = 0; i < sizeof(xStone) / sizeof(int); i++)
        {
            field[xStone[i]][yStone[i]] = 0;
            yStone[i] += 1;
        }
    }
    else
    {
        stone = false;
        updateField(false);
        controlRows();
        setStone();
    }
    return free;
}

void goHorizontaly(char r)
{
    int d = r == 'a' ? -1 : 1;
    bool allowed = true;
    bool new = false;
    for(int i = 0; i < sizeof(xStone) / sizeof(int); i++)
    {
        if(xStone[i] + d >= sizeof(field) / sizeof(field[0]) || xStone[i] + d < 0)
        {
            allowed = false;
        }
        if(field[xStone[i] + d][yStone[i]] == 1 && allowed)
        {
            bool other = true;
            for(int i2 = 0; i2 < sizeof(xStone) / sizeof(int); i2++)
            {
                if(xStone[i] + d == xStone[i2] && yStone[i] == yStone[i2])
                {
                    other = false;
                }
            }
            if(other)
            {
                allowed = false;
                new = true;
            }
        }
    }
    if(allowed)
    {
        for(int i = 0; i < sizeof(xStone) / sizeof(int); i++)
        {
            field[xStone[i]][yStone[i]] = 0;
            xStone[i] += d;
        }
    }
    else if(new)
    {
        stone = false;
    }
    updateField(true);
}

void setStone(void)
{
    srand(time(0));
    status = rand() % 7;
    bool free = true;
    for(int i = 0; i < sizeof(stones[0]) / (2*sizeof(int)); i++)
    {
        xStone[i] = stones[status][i][0];
        yStone[i] = stones[status][i][1];
        if(field[xStone[i]][yStone[i]] == 1)
        {
            free = false;
        }
    }
    stage = 0;
    stone = true;
    if(free)
    {
        updateField(true);
    }
    else
    {
        alive = false;
    }
}

void updateField(bool p)
{
    for(int i = 0; i < sizeof(xStone) / sizeof(int); i++)
    {
        field[xStone[i]][yStone[i]] = 1;
    }
    if(p)
    {
        printField();
    }
}

void buildField(void)
{
    for(int y = 0; y < sizeof(field[0]); y++)
    {
        for(int x = 0; x < sizeof(field) / sizeof(field[0]); x++)
        {
            field[x][y] = 0;
        }
    }
}

int leerPuntajeAlto(void) {
    FILE *f = fopen("score.dat", "rb");
    int hScore;
    if (f != NULL) {
        fread(&hScore, sizeof(int), 1, f);
        fread(&bestHighScoreNickname, sizeof(char), 15, f);
    }
    fclose(f);

    return hScore;
}

void escribirScore(int score) {
    FILE *f = fopen("score.dat", "wb");
    if (f != NULL && score > highScore) {
        highScore = score;
        strcpy(bestHighScoreNickname, name);

        fwrite(&highScore, sizeof(int), 1, f);
        fwrite(&bestHighScoreNickname, sizeof(int), 1, f);
    }

    fclose(f);
}

void newLevel() {
    system("cls");
    gotoxy(30, 10);
    printf("LEVEL %d", level);
    sleep(2);
}

int tiempo = 0;

void printField(void)
{
    if (score%100 == 0 && score != 0) {
        level++;
        newLevel();
    }

    system("cls");
    for(int i = 0; i < (sizeof(field) / sizeof(field[0])) * 2 + 2; i++)
    {
        //  Marco Arriba  //
        printf("%c", 219);
    }
    printf("\n");
    for(int y = 0; y < sizeof(field[0]); y++)
    {
        //  Marco lado Izquierdo //
        printf("%c", 219);
        for(int x = 0; x < sizeof(field) / sizeof(field[0]); x++)
        {
            printf("%s", field[x][y] == 0 ? "  " : "[]");
        }
        if(y != 4)
        {
            //  Marco lado Derecho  //
            printf("%c\n", 219);
        }
        else
        {
            // obtener el tiempo actual
            time_t current_time = time(NULL);

            // calcular la cantidad de segundos que han pasado
            int elapsed_time = difftime(current_time, start_time);

            // actualizar los minutos y segundos
            minutes = elapsed_time / 60;
            seconds = elapsed_time % 60;

            // mostrar el tiempo en pantalla
            // printf("Tiempo transcurrido: %02d:%02d\n", minutes, seconds);

            //gotoxy(35, 1);
            printf("%c\t%c  %s Score: %d\t\t%c %s Best Score: %d\t%c Nivel: %d\t%c Time: %02d:%02d\n", 219, 219, name, score, 219, bestHighScoreNickname, highScore, 219, level, 219, minutes, seconds);
        }

    }
    for(int i = 0; i < (sizeof(field) / sizeof(field[0])) * 2 + 2; i++)
    {
        //  Marco Abajo  //
        printf("%c", 219);
    }
    printf("\n\n      [] Press W to change position, A to left, S to drop, D to right");
}

void GameOver() {
    system("cls");

    for(int i = 0; i < (sizeof(field) / sizeof(field[0])) * 2 + 2; i++)
    {
        //  Marco Arriba  //
        printf("%c", 219);
    }
    printf("\n");

    for(int y = 0; y < sizeof(field[0]); y++)
    {
        //  Marco lado Izquierdo //
        printf("%c", 219);
        for(int x = 0; x < sizeof(field) / sizeof(field[0]); x++)
        {
            printf("%s", field[x][y] == 0 ? "  " : "  ");
        }
        if(y != 4)
        {
            //  Marco lado Derecho  //
            printf("%c\n", 219);
        }
    }
    for(int i = 0; i < (sizeof(field) / sizeof(field[0])) * 2 + 2; i++)
    {
        //  Marco Abajo  //
        printf("%c", 219);
    }
    printf("\n\n      [] Press W to change position, A to left, S to drop, D to right");

    // Frecuencia y duración del sonido (en este caso, 500 Hz durante 500 ms)
    Beep(500, 350+200);
    Beep(300, 400+200);
    Beep(150, 500+200);

    char text[] = "GAME OVER!";

    for(int i = 0; i < (sizeof(text)/sizeof(text[0])); i++) {
        gotoxy(25+i, 10);
        printf("%c", text[i]);
        Sleep(25);
    }

    gotoxy(25, 12);
    printf("SCORE: %d", score);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
