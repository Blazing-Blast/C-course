#include <iostream>

// This function is `pure` since it doesn't hade side effects. It only calculates the result and changes nothing else.
int double_int (const int a) { 
    return a * 2;
}
// This funcion does have side effects: it prints text.
void say_double(const int num) {
    std::cout << num <<  " * 2 = "<< double_int(num) << std::endl;
}
// Does this function have side effects?
void double_ptr(int& p) {
    p = p * 2;
}

int main() {
    int number = 3;     // number = 3
    double_ptr(number);
    say_double(number); // says "6 * 2 = 12"
                        // number changed to 6 somewhere??
    return 0;
}