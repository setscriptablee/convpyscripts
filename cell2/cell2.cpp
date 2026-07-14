#include <iostream>
#include <string>

int main() {
    std::string num1, num2;

    std::cout << "first number: ";
    std::getline(std::cin, num1);

    std::cout << "second number: ";
    std::getline(std::cin, num2);

    int result = std::stoi(num1) + std::stoi(num2);
    std::cout << "answer is " << result << '\n';

    return 0;
}
