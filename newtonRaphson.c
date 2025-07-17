#include <stdio.h>
#include <math.h>
#define TOL 0.0001

double f(double x)
{
    return x * x * x - 2 * x * x - 3;
}

double fDiff(double x)
{
    return 3 * x * x - 4 * x;
}

double absoluteRelativeError(double x0, double x1)
{
    return fabs((x1 - x0) / x1) * 100;
}

double newtonRaphson(double x0)
{
    double x1, error;
    int i = 0;

    printf("Iteration\tx0\tf(x0)\tf'(x0)\tx1\tError\n");

    do
    {

        if (fDiff(x0) == 0)
        {
            printf("No solution found.\n");
            return NAN;
        }

        x1 = x0 - f(x0) / fDiff(x0);

        error = absoluteRelativeError(x0, x1);

        printf("%d\t%.4lf\t%.4lf\t%.4lf\t%.4lf\t%.4lf\n", i + 1, x0, f(x0), fDiff(x0), x1, error);

        x0 = x1;
        i++;
    } while (error > TOL);

    return x1;
}

int main()
{
    double x0, root;
    printf("Enter initial guess: ");
    scanf("%lf", &x0);

    root = newtonRaphson(x0);

    printf("Approximate root at x = %.4f \n", root);

    return 0;
}