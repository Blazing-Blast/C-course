#include <iostream>

// Makefile disbales warning.
int *arr_local(int a0, int a1, int a2, int a3)
{
    int array[] = {a0, a1, a2, a3};
    return array;
}

int *arr_malloc(int a0, int a1, int a2, int a3)
{
    int *array = (int *)malloc(4 * sizeof(int));
    array[0] = a0;
    array[1] = a1;
    array[2] = a2;
    array[3] = a3;
    return array;
}

int *arr_new(int a0, int a1, int a2, int a3)
{
    int *array = new int[4];
    array[0] = a0;
    array[1] = a1;
    array[2] = a2;
    array[3] = a3;
    return array;
}

void arr_print(int *arr, int size)
{
    std::cout << "{ ";
    for (int i = 0; i < size - 1; i++)
        std::cout << arr[i] << ", ";

    std::cout << arr[size - 1] << " }" << std::endl;
}

void main_malloc(int a0, int a1, int a2, int a3)
{
    int *array = arr_malloc(a0, a1, a2, a3);
    arr_print(array, 4);
    free(array);
}

void main_new(int a0, int a1, int a2, int a3)
{
    int *array = arr_new(a0, a1, a2, a3);
    arr_print(array, 4);
    delete array;
}

int main()
{
    main_malloc(5, 6, 2, 5);
    main_new(2, 5, 5, 6);
    return 0;
}