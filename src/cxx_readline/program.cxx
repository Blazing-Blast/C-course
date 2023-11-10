#include <iostream>
#include <string>

int main() {
    std::cout << "Your input: ";
    std::string input;
    std::getline(std::cin, input);
    std::cout << "You said: " << input << std::endl;
    return 0;
}