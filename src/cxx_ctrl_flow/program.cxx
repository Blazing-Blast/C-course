#include <iostream>
#include <vector>

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
        number *= base; // multiply by base
        count++;        // increment by 1
        goto top;       // repeat
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

int sum_arr(int *start, int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
        sum += start[i];

    return sum;
}

int sum_vec(std::vector<int> vec)
{
    int sum = 0;
    for (int num : vec)
        sum += num;
    return sum;
}

int main()
{
    std::cout << "|-9 | = " << abs(-9) << std::endl;
    std::cout << "| 5 | = " << abs(5) << std::endl;
    std::cout << "3 ^ 4 = " << exp_goto(3, 4) << std::endl;
    std::cout << "2 ^ 3 = " << exp_while(2, 3) << std::endl;
    std::cout << "4 ^ 2 = " << exp_for(4, 2) << std::endl;

    const int length = 3;
    int arr[length] = {4, 5, 2};
    std::vector<int> vec(arr, arr + 3);

    std::cout << "4 + 5 + 2 = " << sum_arr(arr, length) << std::endl;
    std::cout << "4 + 5 + 2 = " << sum_vec(vec) << std::endl;

    return 0;
}