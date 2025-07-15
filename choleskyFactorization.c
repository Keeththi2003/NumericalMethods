#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool isSymmetric(double **matrix, int n)
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

double **choleskyDecomposition(double **A, int n)
{

    double **L = (double **)malloc(n * sizeof(double *));

    for (int i = 0; i < n; i++)
    {
        L[i] = (double *)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                L[i][j] = 0.0;
                for (int k = 0; k < i; k++)
                {
                    L[i][j] += L[i][k] * L[i][k];
                }
                L[i][j] = sqrt(A[i][i] - L[i][j]);
            }
            else if (i > j)
            {
                L[i][j] = 0.0;
                for (int k = 0; k < j && k < i; k++)
                {
                    L[i][j] += L[i][k] * L[j][k];
                }
                L[i][j] = (A[i][j] - L[i][j]) / L[j][j];
            }
            else
            {
                L[i][j] = 0.0;
            }
        }
    }

    return L;
}
void printMatrix(double **matrix, int n)
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
void freeMatrix(double **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

double **readMatrix(char *filename, int *n)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Could not open file %s\n", filename);
        return NULL;
    }

    fscanf(file, "%d", n);
    double **matrix = (double **)malloc(*n * sizeof(double *));
    for (int i = 0; i < *n; i++)
    {
        matrix[i] = (double *)malloc(*n * sizeof(double));
        for (int j = 0; j < *n; j++)
        {
            fscanf(file, "%lf", &matrix[i][j]);
        }
    }

    fclose(file);
    return matrix;
}

int main()
{
    int n;
    double **A = readMatrix("matrix.txt", &n);

    if (A == NULL || !isSymmetric(A, n))
    {
        printf("Matrix is not valid\n");
        return 1;
    }

    double **L = choleskyDecomposition(A, 3);
    printMatrix(A, n);
    printMatrix(L, 3);

    freeMatrix(L, 3);
    freeMatrix(A, n);

    return 0;
}