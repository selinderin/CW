#pragma once

#include <iostream>
#include <utility>

template<typename Key, typename Value>
class KeyValuePair
{
private:
    Key key_;
    Value value_;

public:
    KeyValuePair(const Key& key, const Value& value)
        : key_(key), value_(value)
    {
    }

    Key key() const
    {
        return key_;
    }

    Value value() const
    {
        return value_;
    }

    void set_key(const Key& key)
    {
        key_ = key;
    }

    void set_value(const Value& value)
    {
        value_ = value;
    }

    bool equals(const KeyValuePair<Key, Value>& other) const
    {
        return key_ == other.key_ && value_ == other.value_;
    }

    void swap(KeyValuePair<Key, Value>& other)
    {
        std::swap(key_, other.key_);
        std::swap(value_, other.value_);
    }

    void print() const
    {
        std::cout << "Key: " << key_
                  << ", Value: " << value_
                  << std::endl;
    }
};