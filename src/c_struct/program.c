#include <stdio.h>

typedef struct SizedIntArray
{
    size_t size;
    int *array;

} SizedIntArray;

void print_array(SizedIntArray sArray)
{
    for (size_t i = 0; i < sArray.size; i++)
        printf("%d ", sArray.array[i]);
    printf("\n");
}

int main()
{
    int arr[] = {2, 5, 5, 6, 5};
    SizedIntArray sArr = {5, arr};
    print_array(sArr);
}