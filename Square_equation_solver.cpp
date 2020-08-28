#include<stdio.h>
#include<math.h>
#include<assert.h>

enum {NO_ROOTS, ONE_ROOT, TWO_ROOTS, INF_ROOTS};


int solve_1(double a, double b, double c, double* x1, double* x2);
int solve_2(double b, double c, double* x1);


int main()

{
    printf("# Square equetion solver 2.0 by Emir \n");
    printf("# FRKT\n\n");

    printf("Enter coefficients a, b, c:\n");

    double a = NAN, b = NAN, c = NAN;
    scanf("%lg %lg %lg", &a, &b, &c);

    double x1 = NAN, x2 = NAN;
    int nRoots = solve_1(a, b, c, &x1, &x2);

    switch(nRoots)
    {
        case NO_ROOTS :    printf("No roots\n");
                    break;

        case ONE_ROOT :    printf("x = %lg\n", x1);
                    break;

        case TWO_ROOTS:    printf("x1 = %lg, x2 = %lg\n", x1, x2);
                    break;

        case INF_ROOTS:    printf("Any number\n");
                    break;

        default:   printf("ERROR");
    }
}

int solve_1(double a, double b, double c, double* x1, double* x2)

{
    assert (isfinite (a) != 0);
    assert (isfinite (b) != 0);
    assert (isfinite (c) != 0);

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (a == 0)
    {
        return solve_2( b,  c, x1);
    }
    else
    {
        double d = b*b - 4*a*c;
        double sqrtd = sqrt(d);

        if (d > 0)
        {
            *x1 = (-b + sqrtd)/(2*a);
            *x2 = (-b - sqrtd)/(2*a);
            return 2;
        }
        if (d < 0)
        {
            return NO_ROOTS;
        }
        else
        {
            *x1 = -b/(2*a);
            return ONE_ROOT;
        }
    }
}

int solve_2(double b, double c, double* x1)

{
    if (b == 0)
        {
            if (c == 0)
            {
                return INF_ROOTS;
            }
            else
            {
                return NO_ROOTS;
            }
        }
    else
        {
            *x1 = -c/b;
            return ONE_ROOT;
        }
}
