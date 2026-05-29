#pragma once
#include <string>

struct PasswordResult {
    int score;
    std::string strength;
    std::string feedback;
};

PasswordResult checkPassword(const std::string& password);
