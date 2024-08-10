#include <iostream>
#include <fstream>
#include "hash.h"
#include "signin.h"
#include "signup.h"

bool verifyPassword(const std::string& userId, const std::string& inputPassword) {
    std::ifstream userFile("user_data.txt");
    std::ifstream passwordFile("password_data.txt");

    std::string existingUserId, storedHashedPassword;
    while (userFile >> existingUserId && passwordFile >> storedHashedPassword) {
        if (existingUserId == userId) {
            std::string hashedInputPassword = hashPassword(inputPassword);
            return hashedInputPassword == storedHashedPassword;
        }
    }
    return false;
}

void signIn() {
    std::string userId, password;
    
    std::cout << "Enter your User ID: ";
    std::cin >> userId;

    if (!doesUserIdExist(userId)) {
        std::cout << "User ID not found. Please sign up first.\n";
        return;
    }

    std::cout << "Enter your Password: ";
    std::cin >> password;

    if (verifyPassword(userId, password)) {
        std::cout << "Sign-In Successful!\n";
    } else {
        std::cout << "Incorrect Password. Please try again.\n";
    }
}
