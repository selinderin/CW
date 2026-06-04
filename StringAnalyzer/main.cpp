#include <iostream>
#include <string>

int count_digits(const std::string& str);
int count_letters(const std::string& str);
std::string to_upper(const std::string& str);

int main() {
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    int digits = count_digits(input);
    int letters = count_letters(input);
    std::string upper = to_upper(input);

    std::cout << "Number of digits: " << digits << std::endl;
    std::cout << "Number of letters: " << letters << std::endl;
    std::cout << "Uppercase string: " << upper << std::endl;

    return 0;
}