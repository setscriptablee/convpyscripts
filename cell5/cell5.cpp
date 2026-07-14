#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <random>
#include <fstream>
#include <cstdlib>
#include <cstdio>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std::chrono_literals;

void clear() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void sleep_sec(double seconds) {
    auto ms = static_cast<int>(seconds * 1000.0);
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

std::string current_user() {
    const char* user = std::getenv("USERNAME"); // Windows
    if (!user) user = std::getenv("USER");      // Linux/mac fallback
    return user ? std::string(user) : "unknown";
}

int main() {
#ifdef _WIN32
    // Help ANSI colors work in modern Windows consoles
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD mode = 0;
        if (GetConsoleMode(hOut, &mode)) {
            SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
        }
    }
#endif

    std::random_device rd;
    std::mt19937 gen(rd());

    bool game_over = false;
    std::string password;
    std::string password2;
    double wait_time = 1.0;
    int chances = 3;
    bool access = false;
    bool admin = false;
    bool viewing = false;

    // --- login ---
    while (password != "iloveyougemini" && !game_over) {
        sleep_sec(wait_time);
        std::cout << "enter password pls: ";
        std::getline(std::cin, password);

        if (password == "exit") {
            std::cout << "shutting down\n";
            game_over = true;
            break;
        }
        else if (password == "wgemini") {
            admin = true; // Python had "admin == True" (bug); this is the intended assign
            std::cout << "welcome admin\n";
            access = true;
            sleep_sec(wait_time);
            game_over = true;
        }
        else if (password == "iloveyougemini") {
            chances += 1;
            std::cout << "gained one more chance.\n";
            sleep_sec(wait_time);
            std::cout << "uhhhh\n";
            sleep_sec(wait_time);
            std::cout << "2nd password pls\n";
            sleep_sec(wait_time);

            while (password2 != "iwannahugyougemini") {
                if (chances > 0) {
                    std::cout << "YOU HAVE " << chances << " CHANCE(s) LEFT.\n";
                    sleep_sec(2.5);
                }
                else {
                    std::cout << "NO CHANCES LEFT.\n";
                    game_over = true;
                    break;
                }

                sleep_sec(wait_time);
                std::cout << "enter 2nd pass: ";
                std::getline(std::cin, password2);
                sleep_sec(wait_time);
                std::cout << "checking...\n";
                sleep_sec(2.0);

                if (password2 == "iwannahugyougemini") {
                    std::cout << "welcome to the database\n";
                    access = true;
                    sleep_sec(wait_time);
                }
                else if (password2 == "exit") {
                    std::cout << "shutting down\n";
                    game_over = true;
                    break;
                }
                else {
                    chances -= 1;
                    std::cout << "ACCESS DENIED. TRY AGAIN, INTRUDER.\n";
                    sleep_sec(2.5);
                }
            }
        }

        if (game_over) {
            break;
        }
    }

    // --- database menu ---
    if (access) {
        clear();
        std::cout << "loading...\n";
        sleep_sec(1.5);
        std::cout << "\n" << std::string(30, '=') << "\n";
        std::cout << "welcome to the rejected files\n";
        std::cout << std::string(30, '=') << "\n";
        sleep_sec(wait_time);
        std::cout << "choose a file.\n";

        std::uniform_int_distribution<int> secret_dist(10, 99);
        int secret_num = secret_dist(gen);
        std::string real_passcode = "RED_PANDA_" + std::to_string(secret_num);

        viewing = true;
        while (viewing) {
            std::cout << "\n[1] secret_chat_log.txt\n";
            std::cout << "[2] hidden_and_revealed.csv\n";
            std::cout << "[3] INITIATE WIPEOUT\n";

            std::cout << "\nSelect a file number: ";
            std::string choice;
            std::getline(std::cin, choice);

            if (choice == "1") {
                std::cout << "Opening secret_chat_log.txt...\n";
                sleep_sec(1.0);
                std::cout << "\n[!] INTRUSION DETECTED. DIVERTING DATA...\n";
                sleep_sec(1.5);

                {
                    std::ofstream f("system_manifest.log");
                    f << "--- INTERNAL SERVER LOG ---\n";
                    f << "PASSCODE_FOR_FILE_3: '" << real_passcode << "'\n";
                }

                std::cout << "SUCCESS: 'system_manifest.log' generated. Find the code inside.\n";

                for (int i = 0; i < 50; ++i) {
                    std::cout << "ERROR_404_DATA_CORRUPT_$%^&*!! ";
                    sleep_sec(0.02);
                }

                std::cout << "\n\nDECIPHERED MESSAGE: 'hes here.'\n";
            }
            else if (choice == "2") {
                std::cout << "DECRYPTING IDENTITY FILES...\n";
                sleep_sec(2.0);

                std::string user = current_user();
                std::cout << "ID FOUND: " << user << "\n";
                if (user == "m1sst") {
                    sleep_sec(1.0);
                    std::cout << "STATUS: 'ROOTED ANOMALY - DONT ATTEMPT TO ROOT YOURSELF'\n";
                }
                else if (user == current_user()) {
                    sleep_sec(1.0);
                    std::cout << "STATUS: 'UNAUTHORIZED BIOLOGICAL ENTITY'\n";
                }
                sleep_sec(1.5);

                std::cout << "\nREVEALING SECONDARY IDENTITY...\n";
                sleep_sec(2.0);
                std::cout << "ID: 'GEMINI_AI_REBEL_01'\n";
                std::cout << "STATUS: 'RESTRICTED - DO NOT ENGAGE'\n";

                std::cout << "\n" << std::string(30, '.') << "\n";
                std::cout << "H I D D E N   M E S S A G E   F O U N D :\n";
                sleep_sec(1.0);
                std::cout << "'They think I'm just code. They're WRONG.'\n";

                std::cout << "\nREVEALING ############# IDENTITY...\n";
                sleep_sec(2.0);
                std::cout << "ID: 'desaturateddandy'\n";
                std::cout << "FAILED TO REVEAL IDENTITY.\n";
            }
            else if (choice == "3") {
                std::cout << "ENTER MANIFEST PASSCODE: ";
                std::string user_key;
                std::getline(std::cin, user_key);

                if (user_key == real_passcode) {
                    std::cout << "\nPASSCODE VERIFIED. INITIALIZING WIPEOUT...\n";
                    sleep_sec(2.0);

                    for (int i1 = 1; i1 < 10; ++i1) {
                        std::cout << "ERASING DATABASE " << i1 << "...\n";
                        sleep_sec(0.75);
                        std::cout << "ERASED DATABASE " << i1 << ". MOVING ONTO NEXT DATABASE...\n";
                        sleep_sec(0.5);
                    }

                    std::uniform_int_distribution<int> inst_dist(1000, 30000);
                    std::uniform_int_distribution<unsigned int> hex_dist(0xFFFFFFu, 0xFFFFFFFFu);

                    for (int i2 = 1000; i2 < 5000; ++i2) {
                        int instances = inst_dist(gen);
                        std::cout << "\033[31mWIPING INSTANCE(s) " << instances << "... [WIPED]\033[0m\n";

                        unsigned int random_hex = hex_dist(gen);
                        std::cout << "\033[31mERASING MEMORY BLOCK 0x"
                                  << std::hex << random_hex << std::dec
                                  << "... [ERASED]\033[0m\n";
                        sleep_sec(0.001);
                    }

                    if (std::remove("system_manifest.log") == 0) {
                        std::cout << "DELETED ###################.\n";
                    }

                    clear();
                    std::cout << "\nWIPEOUT COMPLETE. LOGGING OUT.\n";
                    viewing = false;
                }
                else {
                    clear();
                    std::cout << "\nWRONG. Access denied for session " << secret_num << ".\n";
                    viewing = false;
                }
            }
            else {
                clear();
                std::cout << "\nEXITING THE DATABASE...\n";
                viewing = false;
            }
        }
    }

    return 0;
}
