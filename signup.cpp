#include <iostream>
#include <fstream>
#include <regex>
#include "hash.h"
#include "signup.h"

bool isUserIdValid(const std::string& userId) {
    std::regex userIdPattern("^[a-zA-Z0-9]{6,10}$");
    return std::regex_match(userId, userIdPattern);
}

bool isPasswordValid(const std::string& password) {
    std::regex passwordPattern("^(?=.*[A-Z])(?=.*[0-9])(?=.*[@#$]).{8,12}$");
    return std::regex_match(password, passwordPattern);
}

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

void signUp() {
    std::string userId, password;
    
    std::cout << "Enter a User ID (6-10 characters, no special characters): ";
    std::cin >> userId;
    
    if (!isUserIdValid(userId)) {
        std::cout << "Invalid User ID. Please follow the constraints.\n";
        return;
    }
    
    if (doesUserIdExist(userId)) {
        std::cout << "User ID already exists. Please choose another.\n";
        return;
    }

    std::cout << "Enter a Password (8-12 characters, at least one capital letter, one digit, one symbol @, $, #): ";
    std::cin >> password;
    
    if (!isPasswordValid(password)) {
        std::cout << "Invalid Password. Please follow the constraints.\n";
        return;
    }

    std::string hashedPassword = hashPassword(password);

    std::ofstream userFile("user_data.txt", std::ios::app);
    userFile << userId << std::endl;

    std::ofstream passwordFile("password_data.txt", std::ios::app);
    passwordFile << hashedPassword << std::endl;

    std::cout << "Sign-Up Successful!\n";
}
