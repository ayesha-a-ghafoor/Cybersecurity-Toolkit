#include "password_checker.h"
#include <cctype>
#include <sstream>

PasswordResult checkPassword(const std::string& password) {
    PasswordResult result;
    result.score = 0;
    std::ostringstream feedback;

    bool hasLower    = false;
    bool hasUpper    = false;
    bool hasDigit    = false;
    bool hasSpecial  = false;

    for (char c : password) {
        if (std::islower(c))  hasLower   = true;
        if (std::isupper(c))  hasUpper   = true;
        if (std::isdigit(c))  hasDigit   = true;
        if (std::ispunct(c))  hasSpecial = true;
    }

    int len = static_cast<int>(password.size());

    if (len >= 8)  result.score++;
    if (len >= 12) result.score++;
    if (len >= 16) result.score++;
    if (hasLower)  result.score++;
    if (hasUpper)  result.score++;
    if (hasDigit)  result.score++;
    if (hasSpecial) result.score++;

    if (!hasLower)   feedback << "  - Add lowercase letters\n";
    if (!hasUpper)   feedback << "  - Add uppercase letters\n";
    if (!hasDigit)   feedback << "  - Add numbers\n";
    if (!hasSpecial) feedback << "  - Add special characters (!@#$...)\n";
    if (len < 8)     feedback << "  - Use at least 8 characters\n";
    if (len < 12)    feedback << "  - 12+ characters is recommended\n";

    if      (result.score <= 2) result.strength = "Very Weak";
    else if (result.score <= 3) result.strength = "Weak";
    else if (result.score <= 4) result.strength = "Moderate";
    else if (result.score <= 5) result.strength = "Strong";
    else                         result.strength = "Very Strong";

    result.feedback = feedback.str();
    if (result.feedback.empty()) result.feedback = "  - Great password!\n";

    return result;
}
