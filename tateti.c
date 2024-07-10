#include <stdio.h>
#include <stdbool.h>

char board[3][3];

// Write all the cells of the board with ' '
void initializeBoard();
void printBoard();
bool isCellAvailable(int row, int col);
int countAvailableCells();

int main()
{
    initializeBoard();
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

bool isCellAvailable(int row, int col)
{
    if (board[row][col] == ' ')
    {
        return true;
    }
    return false;
}

int countAvailableCells()
{
    int availableCells = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (isCellAvailable(i, j))
            {
                availableCells++;
            }
        }
    }
    return availableCells;
}
