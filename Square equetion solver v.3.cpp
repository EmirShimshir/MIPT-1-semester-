//  Square equetion solver v.3

//  Created by Emir Shimshir on 29.08.2020.

//-----------------------------------------------------------------------------

#include<stdio.h>
#include<math.h>
#include<assert.h>

//-----------------------------------------------------------------------------

enum {NO_ROOTS, ONE_ROOT, TWO_ROOTS, INF_ROOTS, YES = 1, NO = 0};

int solve_1(double a, double b, double c, double* x1, double* x2);
int solve_2(double b, double c, double* x1);
int IsZero (double value);
void Test_IsZero();
void Test_Solve_1();
void Test_Solve_2();

//-----------------------------------------------------------------------------

int main()

{

    Test_IsZero();
    Test_Solve_1();
    Test_Solve_2() ;

    printf("\n# Square equetion solver 3.0 by Emir \n");
    printf("# FRKT\n\n");

    printf("Enter coefficients of the square equation ax^2 + bx + c\n\na, b, c:\n");

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

//-----------------------------------------------------------------------------

int solve_1(double a, double b, double c, double* x1, double* x2)

{
    assert (isfinite (a) != 0);
    assert (isfinite (b) != 0);
    assert (isfinite (c) != 0);

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (IsZero(a))
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

//-----------------------------------------------------------------------------

int solve_2(double b, double c, double* x1)

{
    if (IsZero(b))
        {
            if (IsZero(c))
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

//-----------------------------------------------------------------------------

int IsZero (double value)

{
    if (fabs(value) <= 1e-5) return YES;
    else
    return NO;
 }

//-----------------------------------------------------------------------------

void Test_IsZero()
{

    double val;
       int res;
       int exp;
       int num;

        #define DO_TEST                                              \
    if (res == exp) printf("Test_IsZero %d OK\n", num);              \
    else            printf("Test_IsZero %d BAD: IsZero (%lg) == %d, should be %d\n", num, val, res, exp);

    val = 0;
    res = IsZero (val);
    exp = YES;
    num = 1;

    DO_TEST


    val = 1;
    res = IsZero (val);
    exp = NO;
    num++;


    DO_TEST

    val = 1e-5;
    res = IsZero (val);
    exp = YES;
    num++;


   DO_TEST

    val = 0.1;
    res = IsZero (val);
    exp = NO;
    num++;


    DO_TEST


   val = 3;
    res = IsZero (val);
    exp = NO;
    num++;


   DO_TEST

}

//-----------------------------------------------------------------------------

void Test_Solve_1()
{
    double a ,b, c, x1, x2;
    int res;
    int exp;
    int num;

           #define DO_TEST_2                                             \
       if (res == exp) printf("Test_Solve_1 %d OK\n", num);              \
       else            printf("Test_Solve_1 %d BAD: Test_Solve_1 (%lg %lg %lg) == %d, should be %d\n", num, a, b, c, res, exp);
    a = 0;
    b = 0;
    c = 0;
    res =  solve_1(a, b, c, &x1, &x2);
    exp = INF_ROOTS;
    num = 1;

    DO_TEST_2

    a = 1;
    b = 2;
    c = 1;
    res =  solve_1(a, b, c, &x1, &x2);
    exp = ONE_ROOT;
    num++;

    DO_TEST_2

    a =  1;
    b = -2;
    c =  1;
    res =  solve_1(a, b, c, &x1, &x2);
    exp = ONE_ROOT;
    num++;

    DO_TEST_2

    a =  1;
    b = -6;
    c =  8;
    res =  solve_1(a, b, c, &x1, &x2);
    exp = TWO_ROOTS;
    num++;

    DO_TEST_2

    a = 1;
    b = 1;
    c = 1;
    res =  solve_1(a, b, c, &x1, &x2);
    exp = NO_ROOTS;
    num++;

    DO_TEST_2
}

//-----------------------------------------------------------------------------

void Test_Solve_2()
{
    double b, c, x1;
          int res;
          int exp;
          int num;

           #define DO_TEST_3                                      \
       if (res == exp) printf("Test_Solve_2 %d OK\n", num);       \
       else            printf("Test_Solve_2 %d BAD:Test_Solve_2 (%lg %lg) == %d, should be %d\n", num, b, c, res, exp);

    b = 0;
    c = 0;
    res =  solve_2(b, c, &x1);
    exp = INF_ROOTS;
    num = 1;

    DO_TEST_3

    b = 0;
    c = 4;
    res =  solve_2(b, c, &x1);
    exp = NO_ROOTS;
    num++;

    DO_TEST_3

    b = 1;
    c = 4;
    res =  solve_2(b, c, &x1);
    exp = ONE_ROOT;
    num++;

    DO_TEST_3
}
