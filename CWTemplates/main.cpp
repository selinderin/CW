#include <iostream>
#include <string>
#include <iomanip>

#include "KeyValuePair.h"
#include "ByteConverter.h"

void print_bytes(const std::vector<uint8_t>& bytes)
{
    for (uint8_t byte : bytes)
    {
        std::cout
            << std::hex
            << std::uppercase
            << std::setw(2)
            << std::setfill('0')
            << static_cast<int>(byte)
            << ' ';
    }

    std::cout << std::dec << std::endl;
}

int main()
{
    KeyValuePair<int, std::string> pair1(1, "One");

    pair1.print();

    std::cout << pair1.key() << std::endl;
    std::cout << pair1.value() << std::endl;

    pair1.set_key(10);
    pair1.set_value("Ten");

    pair1.print();

    KeyValuePair<int, std::string> pair2(10, "Ten");

    std::cout
        << std::boolalpha
        << pair1.equals(pair2)
        << std::endl;

    KeyValuePair<int, std::string> pair3(100, "Hundred");

    pair1.swap(pair3);

    pair1.print();
    pair3.print();

    KeyValuePair<std::string, double> pair4("Price", 99.99);

    pair4.print();

    uint32_t value32 = 0x12345678;

    auto little = to_bytes(value32, ByteOrder::Little);
    auto big = to_bytes(value32, ByteOrder::Big);

    print_bytes(little);
    print_bytes(big);

    std::cout
        << check<uint32_t>(
               0x12345678,
               ByteOrder::Little,
               {0x12, 0x34, 0x56, 0x78})
        << std::endl;

    std::cout
        << check<uint16_t>(
               0x1234,
               ByteOrder::Big,
               {0x12, 0x34})
        << std::endl;

    return 0;
}