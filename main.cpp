#include <iostream>
#include <string>
#include <limits>
#include "password_checker.h"
#include "caesar_cipher.h"
#include "file_hasher.h"

// ─── ANSI colour helpers ───────────────────────────────────────────────────
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

void printBanner() {
    std::cout << BOLD << CYAN;
    std::cout << R"(
 ██████╗██╗   ██╗██████╗ ███████╗██████╗     ████████╗ ██████╗  ██████╗ ██╗     
██╔════╝╚██╗ ██╔╝██╔══██╗██╔════╝██╔══██╗    ╚══██╔══╝██╔═══██╗██╔═══██╗██║     
██║      ╚████╔╝ ██████╔╝█████╗  ██████╔╝       ██║   ██║   ██║██║   ██║██║     
██║       ╚██╔╝  ██╔══██╗██╔══╝  ██╔══██╗       ██║   ██║   ██║██║   ██║██║     
╚██████╗   ██║   ██████╔╝███████╗██║  ██║       ██║   ╚██████╔╝╚██████╔╝███████╗
 ╚═════╝   ╚═╝   ╚═════╝ ╚══════╝╚═╝  ╚═╝       ╚═╝    ╚═════╝  ╚═════╝ ╚══════╝
)" << RESET;
    std::cout << BOLD << "         C++ Cybersecurity Toolkit  |  Educational Project\n" << RESET;
    std::cout << std::string(80, '-') << "\n\n";
}

void printMenu() {
    std::cout << BOLD << CYAN << "  Main Menu\n" << RESET;
    std::cout << "  " << GREEN << "[1]" << RESET << " Password Strength Checker\n";
    std::cout << "  " << GREEN << "[2]" << RESET << " Caesar Cipher  (encrypt / decrypt)\n";
    std::cout << "  " << GREEN << "[3]" << RESET << " XOR Cipher     (encrypt / decrypt)\n";
    std::cout << "  " << GREEN << "[4]" << RESET << " File Integrity  (hash & verify)\n";
    std::cout << "  " << RED   << "[0]" << RESET << " Exit\n";
    std::cout << "\n  Your choice: ";
}

// ─── Feature 1 : Password Strength ────────────────────────────────────────
void runPasswordChecker() {
    std::cout << "\n" << BOLD << MAGENTA << "=== Password Strength Checker ===" << RESET << "\n";
    std::string password;
    std::cout << "  Enter password: ";
    std::getline(std::cin, password);

    if (password.empty()) {
        std::cout << RED << "  No password entered.\n" << RESET;
        return;
    }

    PasswordResult res = checkPassword(password);

    std::string colour;
    if      (res.score <= 2) colour = RED;
    else if (res.score <= 4) colour = YELLOW;
    else                      colour = GREEN;

    std::cout << "\n  Strength : " << colour << BOLD << res.strength << RESET << "\n";
    std::cout << "  Score    : " << colour << res.score << "/7" << RESET << "\n";
    std::cout << "\n  Suggestions:\n" << res.feedback;
}

// ─── Feature 2 : Caesar Cipher ────────────────────────────────────────────
void runCaesarCipher() {
    std::cout << "\n" << BOLD << MAGENTA << "=== Caesar Cipher ===" << RESET << "\n";
    std::cout << "  " << GREEN << "[1]" << RESET << " Encrypt\n";
    std::cout << "  " << GREEN << "[2]" << RESET << " Decrypt\n";
    std::cout << "  Choice: ";

    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice != 1 && choice != 2) {
        std::cout << RED << "  Invalid choice.\n" << RESET;
        return;
    }

    std::cout << "  Enter text : ";
    std::string text;
    std::getline(std::cin, text);

    std::cout << "  Enter shift (1-25): ";
    int shift;
    std::cin >> shift;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string output = (choice == 1)
        ? caesarEncrypt(text, shift)
        : caesarDecrypt(text, shift);

    std::cout << "\n  " << (choice == 1 ? "Encrypted" : "Decrypted")
              << ": " << GREEN << output << RESET << "\n";
}

// ─── Feature 3 : XOR Cipher ───────────────────────────────────────────────
void runXorCipher() {
    std::cout << "\n" << BOLD << MAGENTA << "=== XOR Cipher ===" << RESET << "\n";
    std::cout << "  (Encrypt and decrypt use the same operation.)\n\n";

    std::cout << "  Enter text : ";
    std::string text;
    std::getline(std::cin, text);

    std::cout << "  Enter single-character key: ";
    char key;
    std::cin >> key;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string output = xorCipher(text, key);

    std::cout << "\n  Result (hex bytes): ";
    for (unsigned char c : output) {
        std::cout << std::hex << std::uppercase
                  << (int)c << " ";
    }
    std::cout << std::dec << "\n";
    std::cout << "  (Run the same operation again with the same key to get back the original text.)\n";
}

// ─── Feature 4 : File Integrity ───────────────────────────────────────────
void runFileHasher() {
    std::cout << "\n" << BOLD << MAGENTA << "=== File Integrity Checker ===" << RESET << "\n";
    std::cout << "  " << GREEN << "[1]" << RESET << " Hash a file\n";
    std::cout << "  " << GREEN << "[2]" << RESET << " Verify a file against a known hash\n";
    std::cout << "  Choice: ";

    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "  Enter file path: ";
    std::string filepath;
    std::getline(std::cin, filepath);

    if (choice == 1) {
        std::string hash = hashFile(filepath);
        if (hash.empty()) {
            std::cout << RED << "  Could not open file: " << filepath << RESET << "\n";
        } else {
            std::cout << "\n  Hash : " << GREEN << hash << RESET << "\n";
            std::cout << "  Save this hash to detect future tampering.\n";
        }
    } else if (choice == 2) {
        std::cout << "  Enter expected hash: ";
        std::string expected;
        std::getline(std::cin, expected);

        bool ok = verifyFile(filepath, expected);
        if (ok) {
            std::cout << "\n  " << GREEN << BOLD << "VERIFIED — file matches the expected hash." << RESET << "\n";
        } else {
            std::cout << "\n  " << RED << BOLD << "MISMATCH — file may have been tampered with!" << RESET << "\n";
        }
    } else {
        std::cout << RED << "  Invalid choice.\n" << RESET;
    }
}

// ─── Entry Point ──────────────────────────────────────────────────────────
int main() {
    printBanner();

    while (true) {
        printMenu();

        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "\n";
        switch (choice) {
            case 1: runPasswordChecker(); break;
            case 2: runCaesarCipher();    break;
            case 3: runXorCipher();       break;
            case 4: runFileHasher();      break;
            case 0:
                std::cout << GREEN << "  Goodbye!\n" << RESET;
                return 0;
            default:
                std::cout << RED << "  Invalid option — try again.\n" << RESET;
        }
        std::cout << "\n";
    }
}
