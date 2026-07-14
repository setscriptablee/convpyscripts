#include <iostream>
#include <random>
#include <string>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 20);

    int secret_number = dist(gen);
    int guess = 0;
    int count = 0;

    std::cout << "im thinking of a number between 1 and 20 right now\n";

    while (guess != secret_number) {
        std::cout << "whats your guess? ";
        std::cin >> guess;
        count = count + 1;

        if (guess < secret_number) {
            std::cout << "higher.\n";
        } else if (guess > secret_number) {
            std::cout << "lower.\n";
        } else {
            std::cout << "correct.\n";
            std::cout << "took you " << count << " tries\n";
        }
    }

    return 0;
}
