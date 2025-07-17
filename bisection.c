#include <stdio.h>
#include <math.h>
#define TOL 0.0001

double f(double x)
{
    return x * x * x - 2 * x * x - 3;
}

double absoluteRelativeError(double a, double b)
{
    return fabs((b - a) / b) * 100;
}

double bisection(double a, double b)
{
    double c, c_prev, error;
    int i = 0;

    if (f(a) * f(b) >= 0)
    {

        printf("f(a) = %.4lf, f(b) = %.4lf\n", f(a), f(b));
        printf("Assumed a and b are in correct!\n");
        return 1;
    }

    printf("Iteration a\t b\t c\t f(c)\t  Error\n");

    do
    {
        c = (a + b) / 2;

     error = absoluteRelativeError(a, b);


        printf("%d\t%.4lf\t%.4lf\t%.4lf\t%.4lf\t%.4lf\n", i + 1, a, b, c, f(c),error);


        if (f(a) * f(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
        c_prev = c;

        i++;
    } while (error > TOL);

    return c;
}

int main()
{
    double a, b, root;
    a = 2;
    b = 3;

    root = bisection(a, b);

    printf("Approximate root at x = %.4f \n", root);

    return 0;
}
