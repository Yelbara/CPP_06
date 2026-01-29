#include "Base.hpp"

int main()
{
    Base base;
    identify(base);
    identify(&base);
    std::cout << "-----------------" << std::endl;
    Base* basePtr = generate();
    identify(*basePtr);
    identify(basePtr);
    delete basePtr;
    return 0;
}