#include "file_hasher.h"
#include <fstream>
#include <sstream>
#include <iomanip>

// A simple djb2-style hash over file bytes, output as hex string
std::string hashFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        return "";
    }

    unsigned long long hash = 5381;
    char byte;
    while (file.get(byte)) {
        hash = ((hash << 5) + hash) + static_cast<unsigned char>(byte);
    }

    std::ostringstream oss;
    oss << std::hex << std::setw(16) << std::setfill('0') << hash;
    return oss.str();
}

bool verifyFile(const std::string& filename, const std::string& expectedHash) {
    std::string currentHash = hashFile(filename);
    return !currentHash.empty() && currentHash == expectedHash;
}
