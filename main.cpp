#include <iostream>
#include "signup.h"
#include "signin.h"

int main() {
    int choice;
    std::cout << "Welcome! Please select an option:\n";
    std::cout << "1. Sign Up\n";
    std::cout << "2. Sign In\n";
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;

    if (choice == 1) {
        signUp();
    } else if (choice == 2) {
        signIn();
    } else {
        std::cout << "Invalid choice. Please restart the program.\n";
    }

    return 0;
}
