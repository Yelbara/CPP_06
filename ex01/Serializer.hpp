#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
// #include <cstdint> // not work new for c++98
#include <stdint.h>

class Serializer {
    Serializer();
    Serializer& operator=(const Serializer& other);
    Serializer(const Serializer& other);
    ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};

#endif 