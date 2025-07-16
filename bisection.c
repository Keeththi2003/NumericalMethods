#include <stdio.h>
#include <math.h>
#define TOL 0.0001


double f(double x) {
    return x * x * x - 2*x*x - 3;  
}

double bisection(double a , double b) {
    double c;
    int i = 0;

    while (f(a) * f(b) >= 0) {

        // printf("f(a) = %.4lf, f(b) = %.4lf\n", f(a), f(b));
        // printf("Assumed a and b are in correct!\n");
        a++;
        b++;  
    }

    printf("Iteration a\t b\t c\t f(c)\n");

    while ((b - a) / 2 > TOL ) {
        c = (a + b) / 2;

                printf("%d\t%.4lf\t%.4lf\t%.4lf\t%.4lf\n", i+1, a, b, c, f(c));

        if (fabs(f(c)) < TOL) {
            return c;  
        }

        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        i++;
    } 

    return c;  
}

int main() {
    double a, b, root;
    a = 1;
    b = 2;

    root = bisection(a, b);

    printf("Approximate root at x = %.4f \n", root);

    return 0;
}
