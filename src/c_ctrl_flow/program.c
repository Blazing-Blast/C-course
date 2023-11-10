#include <stdio.h>

int abs(int num)
{
    if (num >= 0)
        return num;
    else
        return num * -1;
}

int exp_goto(int base, int exponent)
{
    int number = 1;
    int count = 0;
top:
    if (count < exponent)
    {
        number *= base;
        count++;
        goto top;
    }

    return number;
}

int exp_while(int base, int exponent)
{
    int number = 1;
    int count = 0;

    while (count < exponent)
    {
        number *= base;
        count++;
    }

    return number;
}

int exp_for(int base, int exponent)
{
    int number = 1;

    for (int i = 0; i < exponent; i++)
        number *= base;

    return number;
}

int main()
{
    printf("|-9| = %d\n", abs(-9));
    printf("|5| = %d\n", abs(5));
    printf("3^4 = %d\n", exp_goto(3, 4));
    printf("2^3 = %d\n", exp_while(2, 3));
    printf("4^2 = %d\n", exp_goto(4, 2));
    return 0;
}