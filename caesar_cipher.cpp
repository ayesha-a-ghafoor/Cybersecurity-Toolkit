#include "caesar_cipher.h"

std::string caesarEncrypt(const std::string& text, int shift) {
    shift = ((shift % 26) + 26) % 26;
    std::string result = text;
    for (char& c : result) {
        if (c >= 'a' && c <= 'z') {
            c = static_cast<char>('a' + (c - 'a' + shift) % 26);
        } else if (c >= 'A' && c <= 'Z') {
            c = static_cast<char>('A' + (c - 'A' + shift) % 26);
        }
    }
    return result;
}

std::string caesarDecrypt(const std::string& text, int shift) {
    return caesarEncrypt(text, 26 - (((shift % 26) + 26) % 26));
}

std::string xorCipher(const std::string& text, char key) {
    std::string result = text;
    for (char& c : result) {
        c = static_cast<char>(c ^ key);
    }
    return result;
}
