#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char board[3][3];
char currentPlayer = 'x';

// Write all the cells of the board with ' '
void initializeBoard();
void printBoard();
bool isCellAvailable(int row, int col);
int countAvailableCells();
void computerMovement();
void userMovement();
bool isIndexValid(int row, int col);
bool checkWin();
void changePlayer();

int main()
{
    initializeBoard();
    bool thereIsAWinner = false;
    printBoard();
    while (countAvailableCells() > 0 && !thereIsAWinner)
    {
        if (currentPlayer == 'x')
        {
            userMovement();
        }
        else
        {
            computerMovement();
        }
        if (checkWin())
        {
            thereIsAWinner = true;
        }
        changePlayer();
    }
    if (thereIsAWinner)
    {
        printf("Winner: Player %c\n", currentPlayer);
    }
    else
    {
        printf("There is a tie");
    }
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
        if (isIndexValid(row, col) && isCellAvailable(row, col))
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

bool isIndexValid(int row, int col)
{
    bool rowCondition = row >= 0 && row < 3;
    bool colCondition = col >= 0 && col < 3;
    if (rowCondition && colCondition)
    {
        return true;
    }
    return false;
}

bool checkWin()
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
        {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == currentPlayer && board[1][j] == currentPlayer && board[2][j] == currentPlayer)
        {
            return true;
        }
    }
    // Check main diagonal
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
    {
        return true;
    }
    // Check antidiagonal
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
    {
        return true;
    }
    // If no one won
    return false;
}

void changePlayer()
{
    if (currentPlayer == 'x')
    {
        currentPlayer = 'o';
    }
    else
    {
        currentPlayer = 'x';
    }
}
