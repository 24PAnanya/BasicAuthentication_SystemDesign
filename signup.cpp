#include <iostream>
#include <fstream>
#include "signup.h"
#include "hash.h"

// Function to check if user ID is valid
bool isUserIdValid(const std::string& userId) {
    if (userId.length() < 6 || userId.length() > 10) {
        return false;
    }
    for (char c : userId) {
        if (!isalnum(c)) { // Only allow alphanumeric characters
            return false;
        }
    }
    return true;
}

// Function to check if password is valid
bool isPasswordValid(const std::string& password) {
    if (password.length() < 8 || password.length() > 12) {
        return false;
    }
    bool hasUpper = false, hasDigit = false, hasSymbol = false;
    for (char c : password) {
        if (isupper(c)) hasUpper = true;
        else if (isdigit(c)) hasDigit = true;
        else if (c == '@' || c == '$' || c == '#') hasSymbol = true;
    }
    return hasUpper && hasDigit && hasSymbol;
}

// Function to check if user ID already exists
bool doesUserIdExist(const std::string& userId) {
    std::ifstream userFile("user_data.txt");
    std::string existingUserId;
    while (userFile >> existingUserId) {
        if (existingUserId == userId) {
            return true;
        }
    }
    return false;
}

// Function to handle the sign-up process
void signUp() {
    std::string userId, password;

    while (true) {
        std::cout << "Enter a User ID (6-10 alphanumeric characters) or type 'exit' to quit: ";
        std::cin >> userId;

        if (userId == "exit") {
            std::cout << "Exiting sign-up process.\n";
            return;  // Exit the function if the user wants to quit
        }

        if (!isUserIdValid(userId)) {
            std::cout << "Invalid User ID. Please try again.\n";
            continue;
        }
        if (doesUserIdExist(userId)) {
            std::cout << "User ID already exists. Please enter a different User ID.\n";
            continue;
        }
        break;  // Exit the loop if the User ID is valid and does not exist
    }

    while (true) {
        std::cout << "Enter a Password (8-12 characters, at least one capital letter, one digit, and one symbol @, $, #) or type 'exit' to quit: ";
        std::cin >> password;

        if (password == "exit") {
            std::cout << "Exiting sign-up process.\n";
            return;  // Exit the function if the user wants to quit
        }

        if (!isPasswordValid(password)) {
            std::cout << "Invalid Password. Please try again.\n";
            continue;
        }
        break;  // Exit the loop if the password is valid
    }

    std::ofstream userFile("user_data.txt", std::ios::app);
    userFile << userId << std::endl;

    std::ofstream passwordFile("password_data.txt", std::ios::app);
    std::string hashedPassword = hashPassword(password);
    passwordFile << hashedPassword << std::endl;

    std::cout << "Sign-Up Successful!\n";
}
