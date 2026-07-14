#include <iostream>

int main() {
    int num1, num2;

    std::cout << "first number: ";
    std::cin >> num1;

    std::cout << "second number: ";
    std::cin >> num2;

    int result = num1 + num2;
    std::cout << "answer is " << result << '\n';

    return 0;
}
