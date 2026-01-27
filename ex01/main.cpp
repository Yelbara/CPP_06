#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data d;
    d.a = 42;
    d.b = 4.2f;
    d.c = "Hello";

    uintptr_t raw = Serializer::serialize(&d);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Original address : " << &d << std::endl;
    std::cout << "Deserialized ptr : " << ptr << std::endl;

    if (ptr == &d)
        std::cout << "✅ SUCCESS: pointers are equal" << std::endl;
    else
        std::cout << "❌ ERROR: pointers differ" << std::endl;

    std::cout << "Data values: "
              << ptr->a << ", "
              << ptr->b << ", "
              << ptr->c << std::endl;

    return 0;
}
