#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
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


_Bool field[10][20];
bool alive;
int status;
int stage;
int xStone[4];
int yStone[4];
int level = 1;
const int ROWS_PER_LEVEL = 10;
time_t startTime;
bool stone;
int score;
int highScore;
char name[15];
char bestHighScoreNickname[15];
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
double difftime(time_t time1, time_t time0);


void askForName() {
    system("cls");
    gotoxy(15, 10);
    printf("\t%c  Ingrese su nombre:  ", 219);
    fflush(stdin);
    scanf("%s", &name);
}


int main(void)
{
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
    time(&startTime);
    alive = true;
    char r = ' ';
    while(alive)
    {
        // Informar al jugador cuál es el nivel actual
        //system("cls");
        //Sleep(1000);
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
            /*
            case 'f':
                stepDown(true);
                updateField(true);
                break;
            */
            case 'a':
                goHorizontaly(r);
                break;
            case 'd':
                goHorizontaly(r);
                break;
            case 'q':
                alive = false;
                break;
            default:
                printField();
            }
        }
    }
    printf("\nGame Over!\nScore: %d\n", score);
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
 int currentLevel = score / ROWS_PER_LEVEL + 1;
    if (currentLevel > level) {
        level = currentLevel;
        // Aumentar la velocidad del juego
        Sleep(500 - 50 * level);
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

void printField(void)
{
    system("cls");
    for(int i = 0; i < (sizeof(field) / sizeof(field[0])) * 2 + 2; i++)
    {
        printf("#");
    }
    printf("\n");
    for(int y = 0; y < sizeof(field[0]); y++)
    {
        printf("#");
        for(int x = 0; x < sizeof(field) / sizeof(field[0]); x++)
        {
            printf("%s", field[x][y] == 0 ? "  " : "[]");
        }
        if(y != 4)
        {
            printf("#\n");
        }
        else
        {
            gotoxy(35, 1);
            printf("%c  %s Score: %d", 219, name, score);
            printf("\t%c %s Best Score: %d\t%c Nivel: %d", 219, bestHighScoreNickname, highScore, 219, level);
            time_t currentTime;
            time(&currentTime);
            int elapsedSeconds = difftime(currentTime, startTime);
            int minutes = elapsedSeconds / 60;
            int seconds = elapsedSeconds % 60;
            printf("\t%c Time: %02d:%02d\n", 219, minutes, seconds);
        }

    }
    for(int i = 0; i < (sizeof(field) / sizeof(field[0])) * 2 + 2; i++)
    {
        printf("#");
    }
    printf("\n>");
}

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
