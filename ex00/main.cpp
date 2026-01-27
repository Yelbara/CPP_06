#include "ScalarConverter.hpp"

int main(int ac, char* av[])
{
    if(ac != 2)
        return(std::cout << "Error: invalid number of arguments\n", 1);
    ScalarConverter::convert(av[1]);
    return 0;
}