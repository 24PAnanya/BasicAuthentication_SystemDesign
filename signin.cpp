#include <iostream>
#include <fstream>
#include "signin.h"
#include "signup.h"
#include "hash.h"

// Function to check if user ID exists
bool doesUserIdExist2(const std::string& userId) {
    std::ifstream userFile("user_data.txt");
    std::string existingUserId;
    while (userFile >> existingUserId) {
        if (existingUserId == userId) {
            return true;
        }
    }
    return false;
}

// Function to retrieve hashed password for a user ID
std::string getStoredHashedPassword(const std::string& userId) {
    std::ifstream userFile("user_data.txt");
    std::ifstream passwordFile("password_data.txt");
    std::string existingUserId, hashedPassword;

    while (userFile >> existingUserId) {
        passwordFile >> hashedPassword;
        if (existingUserId == userId) {
            return hashedPassword;
        }
    }
    return "";
}

// Function to handle the sign-in process
void signIn() {
    std::string userId, password;

    while (true) {
        std::cout << "Enter your User ID (or type 'exit' to quit): ";
        std::cin >> userId;

        if (userId == "exit") {
            std::cout << "Exiting sign-in process.\n";
            return;  // Exit the function if the user wants to quit
        }

        if (!doesUserIdExist2(userId)) {
            std::cout << "User ID not found. Do you want to sign up? (yes/no): ";
            std::string choice;
            std::cin >> choice;
            if (choice == "yes") {
                signUp();  // Redirect to sign-up process
                return;
            } else {
                continue;  // Ask for the user ID again
            }
        }

        std::string storedHashedPassword = getStoredHashedPassword(userId);

        while (true) {
            std::cout << "Enter your Password (or type 'exit' to quit): ";
            std::cin >> password;

            if (password == "exit") {
                std::cout << "Exiting sign-in process.\n";
                return;  // Exit the function if the user wants to quit
            }

            if (hashPassword(password) == storedHashedPassword) {
                std::cout << "Sign-In Successful!\n";
                return;
            } else {
                std::cout << "Incorrect Password. Please try again.\n";
            }
        }
    }
}
