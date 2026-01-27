#include "Data.hpp"

Data::Data() : a(0), b(0.0f), c("yassine") {
}

Data::Data(const Data& other) : a(other.a), b(other.b), c(other.c) {
}

Data& Data::operator=(const Data& other)
{
    a = other.a;
    b = other.b;
    c = other.c;
    return *this;
}
Data::~Data() {
}
