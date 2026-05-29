#pragma once
#include <string>

std::string caesarEncrypt(const std::string& text, int shift);
std::string caesarDecrypt(const std::string& text, int shift);
std::string xorCipher(const std::string& text, char key);
