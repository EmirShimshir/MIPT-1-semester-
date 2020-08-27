#include<stdio.h>
#include<math.h>


int solve(double a, double b, double c, double* x1, double* x2)

{
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                return 3;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            *x1 = *x2 = -c/b;

            return 1;
        }
    }
    else
    {
        double d = b*b - 4*a*c;
        if (d > 0)
        {
            *x1 = (-b + sqrt(d))/(2*a);
            *x2 = (-b - sqrt(d))/(2*a);
            return 2;
        }
        if (d < 0)
        {
            return 0;
        }
        else
        {
            *x1 = *x2 = -b/(2*a);
            return 1;
        }
    }
}

int main()

{
    printf("# Square equetion solver by Emir \n");
    printf("# FRKT\n\n");

    printf("Enter coefficients a, b, c:\n");

    double a = 0, b = 0, c = 0;
    scanf("%lg %lg %lg", &a, &b, &c);

    double x1 = 0, x2 = 0;
    int nRoots = solve(a, b, c, &x1, &x2);

    switch(nRoots)
    {
        case 0:    printf("No roots\n");
                    break;

        case 1:    printf("x = %lg\n", x1);
                    break;

        case 2:    printf("x1 = %lg, x2 = %lg\n", x1, x2);
                    break;

        case 3:    printf("Any number\n");
                    break;

        default:   printf("ERROR");
    }
}
