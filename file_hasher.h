#pragma once
#include <string>

std::string hashFile(const std::string& filename);
bool verifyFile(const std::string& filename, const std::string& expectedHash);
