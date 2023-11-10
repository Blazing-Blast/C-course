#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

// Makefile disbales warning.
int *bad_arr(int a0, int a1, int a2, int a3)
{
    int array[] = {a0, a1, a2, a3};
    return array;
}

int *arr(int a0, int a1, int a2, int a3)
{
    int *array = malloc(4 * sizeof(int));
    array[0] = a0;
    array[1] = a1;
    array[2] = a2;
    array[3] = a3;
    return array;
}

void arr_print(int *arr, int size)
{
    printf("{ ");
    for (int i = 0; i < size - 1; i++)
        printf("%d, ", arr[i]);

    printf("%d }\n", arr[size - 1]);
}

int main()
{
    int *array = arr(5, 6, 2, 5);
    arr_print(array, 4);
    return 0;
}