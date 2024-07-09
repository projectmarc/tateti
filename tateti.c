#include <stdio.h>

char board[3][3];

// Write all the cells of the board with ' '
void initializeBoard();
void printBoard();

int main()
{
    initializeBoard();
    printBoard();
    return 0;
}

void initializeBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("[%c] ", board[i][j]);
        }
        printf("\n");
    }
}
