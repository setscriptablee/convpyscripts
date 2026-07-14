#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "day 1 starts here.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "at 16:00 on 11 Feb 2026...\n";
    return 0;
}
