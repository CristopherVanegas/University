#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

// Estructura para la pieza actual
typedef struct
{
    int x, y;  // Coordenadas de la esquina superior izquierda de la pieza
    int type;  // Tipo de pieza
    int rotation;  // Rotación de la pieza
} Piece;

// Tablero de juego
int board[BOARD_HEIGHT][BOARD_WIDTH];

// Piezas posibles
int pieces[7][4][4] =
{
    // I
    {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    // J
    {
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    // L
    {
        {0, 0, 1, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    // O
    {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    // S
    {
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    // T
    {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    // Z
    {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    }
};

// Colores posibles
int colors[7] = {1, 2, 3, 4, 5, 6, 7};

// Función para imprimir el tablero
void print_board()
{
    int i, j;
    for (i = 0; i < BOARD_HEIGHT; i++)
    {
        for (j = 0; j < BOARD_WIDTH; j++)
        {
            if (board[i][j] != 0)
            {
                printf("%d ", board[i][j]);
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");



// Dibujar la pieza en el tablero
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (pieces[piece.type][piece.rotation][i][j] != 0)
            {
                board[piece.y + i][piece.x + j] = colors[piece.type];
            }
        }
    }
}

// Función para borrar la pieza actual del tablero
void erase_piece(Piece piece)
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (pieces[piece.type][piece.rotation][i][j] != 0)
            {
                board[piece.y + i][piece.x + j] = 0;
            }
        }
    }
}

// Función para comprobar si la pieza puede moverse hacia la izquierda
int can_move_left(Piece piece)
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (pieces[piece.type][piece.rotation][i][j] != 0)
            {
                if (piece.x + j == 0)
                {
                    return 0;
                }
                if (board[piece.y + i][piece.x + j - 1] != 0)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

// Función para mover la pieza hacia la izquierda
void move_left(Piece *piece)
{
    erase_piece(*piece);
    piece->x--;
    draw_piece(*piece);
}

// Función para comprobar si la pieza puede moverse hacia la derecha
int can_move_right(Piece piece)
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (pieces[piece.type][piece.rotation][i][j] != 0)
            {
                if (piece.x + j == BOARD_WIDTH - 1)
                {
                    return 0;
                }
                if (board[piece.y + i][piece.x + j + 1] != 0)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

// Función para mover la pieza hacia la derecha
void move_right(Piece *piece)
{
    erase_piece(*piece);
    piece->x++;
    draw_piece(*piece);
}

// Función para comprobar si la pieza puede caer más abajo
int can_move_down(Piece piece)
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (pieces[piece.type][piece.rotation][i][j] != 0)
            {
                if (piece.y + i == BOARD_HEIGHT - 1)
                {
                    return 0;
                }
                if (board[piece.y + i + 1][piece.x + j] != 0)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

// Función para mover la pieza hacia abajo
void move_down(Piece *piece)
{
    erase_piece(*piece);
    piece->y++;
    draw_piece(*piece);
}

// Función para rotar la pieza en el sentido de las agujas del reloj
void rotate_clockwise(Piece *piece)
{
    erase_piece(*piece);
    piece->rotation = (piece->rotation + 1) % 4;
    draw_piece(*piece);
}

// Función para rotar la pieza en sentido antihorario
void rotate_counterclockwise(Piece *piece)
{
    erase_piece(*piece);
    piece->rotation = (piece->rotation + 3) % 4;
    draw_piece(*piece);
}

// Función para fijar la pieza actual en su posición actual en el tablero
void fix_piece(Piece piece)
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (pieces[piece.type][piece.rotation][i][j] != 0)
            {
                board[piece.y + i][piece.x + j] = colors[piece.type];
            }
        }
    }
}

// Función para eliminar las filas completas del tablero y sumar puntos al marcador
void clear_rows()
{
    int i, j;
    int rows_cleared = 0;
    for (i = BOARD_HEIGHT - 1; i >= 0; i--)
    {
        int row_full = 1;
        for (j = 0; j < BOARD_WIDTH; j++)
        {
            if (board[i][j] == 0)
            {
                row_full = 0;
                break;
            }
        }
        if (row_full)
        {
            int k, l;
            for (k = i; k > 0; k--)
            {
                for (l = 0; l < BOARD_WIDTH; l++)
                {
                    board[k][l] = board[k - 1][l];
                }
            }
            for (l = 0; l < BOARD_WIDTH; l++)
            {
                board[0][l] = 0;
            }
            rows_cleared++;
            i++;
        }
    }
    switch (rows_cleared)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 250;
        break;
    case 3:
        score += 500;
        break;
    case 4:
        score += 1000;
        break;
    default:
        break;
    }
}

// Función principal del juego
int main()
{
    srand(time(NULL));

    scss
    Copy code
    init_board();

    while (1)
    {
        Piece piece;
        new_piece(&piece);

        while (1)
        {
            draw_board();
            draw_piece(piece);

            if (!can_move_down(piece))
            {
                fix_piece(piece);
                clear_rows();
                break;
            }

            int key = getkey();
            if (key == 'q')
            {
                return 0;
            }
            else if (key == KEY_LEFT && can_move_left(piece))
            {
                move_left(&piece);
            }
            else if (key == KEY_RIGHT && can_move_right(piece))
            {
                move_right(&piece);
            }
            else if (key == KEY_DOWN && can_move_down(piece))
            {
                move_down(&piece);
            }
            else if (key == KEY_UP)
            {
                rotate_clockwise(&piece);
            }
            else if (key == ' ')
            {
                while (can_move_down(piece))
                {
                    move_down(&piece);
                }
                fix_piece(piece);
                clear_rows();
                break;
            }

            usleep(DELAY);
        }
    }

    return 0;
}
