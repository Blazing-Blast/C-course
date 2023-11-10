#include <iostream>

typedef struct SizedIntArray
{
    size_t size;
    int *array;

    void print()
    {
        for (size_t i = 0; i < this->size; i++)
            std::cout << this->array[i] << " ";
        std::cout << std::endl;
    }

} SizedIntArray;

class ClassArray
{
private:
    size_t size;
    int *array;

public:
    void print()
    {
        for (size_t i = 0; i < this->size; i++)
            std::cout << this->array[i] << " ";
        std::cout << std::endl;
    }
    ClassArray(size_t size, int *array)
    {
        this->size = size;
        this->array = array;
    }
};

namespace Numbers
{
    const float pi = 3.14159265359;
    const float e = 2.71828182846;
}

int main()
{
    int arr[] = {2, 5, 5, 6, 5};
    SizedIntArray sArr = {5, arr};
    sArr.print();
    std::cout << sArr.size << std::endl;

    ClassArray cArr(5, arr);
    cArr.print();
    // std::cout << cArr.size << std::endl; This errors

    std::cout << "pi = " << Numbers::pi << "..." << std::endl;
}