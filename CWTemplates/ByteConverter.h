#pragma once

#include <vector>
#include <cstdint>
#include <type_traits>
#include <algorithm>

enum class ByteOrder
{
    Little,
    Big
};

template<typename T>
std::vector<uint8_t> to_bytes(T value, ByteOrder order)
{
    static_assert(std::is_integral_v<T>,
                  "Integral type required");

    std::vector<uint8_t> bytes(sizeof(T));

    for (size_t i = 0; i < sizeof(T); ++i)
    {
        bytes[i] =
            static_cast<uint8_t>(
                (static_cast<uint64_t>(value) >> (8 * i)) & 0xFF
            );
    }

    if (order == ByteOrder::Big)
    {
        std::reverse(bytes.begin(), bytes.end());
    }

    return bytes;
}

template<typename T>
bool check(
    T value,
    ByteOrder order,
    const std::vector<uint8_t>& reference)
{
    return to_bytes(value, order) == reference;
}