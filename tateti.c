#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char board[3][3];

// Write all the cells of the board with ' '
void initializeBoard();
void printBoard();
bool isCellAvailable(int row, int col);
int countAvailableCells();
void computerMovement();
void userMovement();

int main()
{
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

void computerMovement()
{
    int randomRow, randomCol;
    bool isMovementAssigned = false;
    while (!isMovementAssigned)
    {
        randomCol = rand() % 3;
        randomRow = rand() % 3;
        if (isCellAvailable(randomRow, randomCol))
        {
            board[randomRow][randomCol] = 'o';
            isMovementAssigned = true;
        }
    }
}

void userMovement()
{
    bool isMovementAssigned = false;
    int row, col;
    while (!isMovementAssigned)
    {
        scanf("%i %i", &row, &col);
        row -= 1;
        col -= 1;
        if (isCellAvailable(row, col))
        {
            board[row][col] = 'x';
            isMovementAssigned = true;
        }
        else
        {
            printf("Enter a valid and available cell index\n");
        }
    }
}
