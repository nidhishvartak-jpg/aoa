#include <stdio.h>
#include <stdbool.h>

// Declaring maximum size for the board.
#define MAX_N 8

void printSolution(int N, int board[MAX_N][MAX_N])
{
    printf("\nHere is one possible solution:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

bool isSafe(int N, int board[MAX_N][MAX_N], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int N, int board[MAX_N][MAX_N], int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(N, board, i, col))
        {
            board[i][col] = 1;

            if (solveNQUtil(N, board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }
    return false;
}

void solveNQueens(int N)
{
    int board[MAX_N][MAX_N] = {{0}};

    if (solveNQUtil(N, board, 0) == false)
    {
        printf("Solution does not exist for N = %d\n", N);
        return;
    }

    printSolution(N, board);
}

int main()
{
    int n;
    printf("Enter the number of queens (N): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_N)
    {
        printf("Please enter a number between 1 and %d.\n", MAX_N);
        return 1;
    }

    if (n == 2 || n == 3)
    {
        printf("Solution does not exist for N = %d\n", n);
    }
    else
    {
        solveNQueens(n);
    }

    return 0;
}
