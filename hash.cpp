#include "hash.h"
#include <functional>
#include <string>
#include <sstream>

std::string hashPassword(const std::string& password) {
    std::hash<std::string> hasher;
    size_t hashedValue = hasher(password);

    // Convert the hashed value to a hexadecimal string
    std::stringstream ss;
    ss << std::hex << hashedValue;
    return ss.str();
}
