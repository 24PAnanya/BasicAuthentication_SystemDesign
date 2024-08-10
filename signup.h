#include <string>
#ifndef SIGNUP_H
#define SIGNUP_H

bool isUserIdValid(const std::string& userId);
bool isPasswordValid(const std::string& password);
bool doesUserIdExist(const std::string& userId);
void signUp();

#endif
