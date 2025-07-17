#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isSymmetric(double matrix[][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return false;
            }
        }
    }
    return true;
}

void choleskyDecomposition(double A[][10], double L[][10], int n)
{

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            L[i][j] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                for (int k = 0; k < i; k++)
                {
                    L[i][j] += L[i][k] * L[i][k];
                }
                L[i][j] = sqrt(A[i][i] - L[i][j]);
            }
            else if (i > j)
            {
                for (int k = 0; k < j && k < i; k++)
                {
                    L[i][j] += L[i][k] * L[j][k];
                }
                L[i][j] = (A[i][j] - L[i][j]) / L[j][j];
            }
        }
    }

}
void printMatrix(double matrix[][10], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n = 3;
    double A[10][10] = {
        {4, 12, -16},
        {12, 37, -43},
        {-16, -43, 98}};

    if (A == NULL || !isSymmetric(A, n))
    {
        printf("Matrix is not valid\n");
        return 1;
    }

    double L[10][10];
    choleskyDecomposition(A, L, n);
    printMatrix(A, n);
    printMatrix(L, n);

    return 0;
}