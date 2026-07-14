#include <iostream>
#include <thread>
#include <chrono>

int main() {
    using namespace std::chrono_literals; // allows 1s, 2s

    std::cout << "at 21:00 on 11 Feb 2026...\n";
    std::this_thread::sleep_for(1s);

    std::cout << "initiate lockdown.\n";
    std::this_thread::sleep_for(1s);

    std::cout << "initiating lockdown...\n";
    std::this_thread::sleep_for(2s);

    // range(10, 0, -1) → 10, 9, ..., 1
    for (int i = 10; i > 0; --i) {
        std::cout << "everything will be locked down in " << i << " seconds.\n";
        std::this_thread::sleep_for(1s);
    }

    std::cout << "everything is now locked down.\n";
    std::this_thread::sleep_for(1s);

    std::cout << "lockdown successfully.\n";
    std::this_thread::sleep_for(1s);

    std::cout << "day 1 ends here.\n";

    return 0;
}
