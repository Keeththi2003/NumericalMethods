#include <stdio.h>
#include <math.h>
#define TOL 0.0001

double f(double x) {
    return x * x * x - 2*x*x - 3;  
}
double secant(double x0, double x1)
{
    double x2;
    int i = 0;

    printf("Iteration\tx0\tf(x0)\tf(x1)\tx1\tx2\n");

    while (fabs(f(x0)) >= TOL)

    {

        if (f(x1) - f(x0) == 0.0)
        {
            printf("Error: Division by zero\n");
            return NAN;
        }

        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
        printf("%d\t\t%.4lf\t%.4lf\t%.4lf\t%.4lf\t%.4lf\n", i + 1, x0, f(x0), f(x1), x1, x2);

        if (fabs(x2 - x1) < TOL)
        {
            return x2;
        }

        x0 = x1;
        x1 = x2;
        i++;
    }

    return x2;
}

int main()
{
    double x0, x1, root;
    printf("Enter initial guess x0: ");
    scanf("%lf", &x0);

    printf("Enter second guess x1: ");
    scanf("%lf", &x1);

    root = secant(x0, x1);

    printf("Approximate root at x = %.4f \n", root);

    return 0;
}