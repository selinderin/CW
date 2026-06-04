#include <string>
#include <cctype>

int count_digits(const std::string& str) {
    int count = 0;
    for (char c : str) {
        if (std::isdigit(c)) {
            count++;
        }
    }
    return count;
}