#include "ScalarConverter.hpp"


void print_char(std::string str)
{
    char *endptr;
    std::cout << "char: ";
    long nb = strtol(str.c_str(), &endptr, 10);
    if(errno == ERANGE )
        return(std::cout << "impossible" << std::endl, void());
    if(endptr[0] != '\0' && str.length() == 1)
        std::cout << "'" << str[0] << "'" << std::endl;
    else if (endptr[0] == '\0' && nb >= 32 && nb < 127)
        std::cout << "'" << static_cast<char>(nb) << "'" << std::endl;
    else if(endptr[0] == '\0' && ((nb >= 0 && nb <= 31) || nb == 127))
        std::cout << "Non displayable" << std::endl;
    else if(endptr[0] == '.' )
    {
        int i = 1;
        while(endptr[i] != '\0' && (endptr[i] >= 48 && endptr[i] <= 57))
            i++;
        if(!(endptr[i] == '\0' || (endptr[i] == 'f' && endptr[i + 1] == '\0')))
            return(std::cout << "impossible" << std::endl, void());
        if(nb >= 32 && nb < 127)
            std::cout << "'" << static_cast<char>(nb) << "'" << std::endl;
        else if((nb >= 0 && nb <= 31) || nb == 127)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "impossible" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
}

int print_int(std::string str)
{
    
    char *endptr;
    std::cout << "int: ";
    long nb = strtol(str.c_str(), &endptr, 10);
    if(errno == ERANGE )
        return(std::cout << "impossible" << std::endl, -1);
    if(endptr[0] == '\0')
        return(std::cout  << nb << std::endl, 0);
    else if(endptr[0] != '\0' && str.length() == 1)
        return(std::cout << static_cast<int>(str[0]) << std::endl, 0);
    else if(endptr[0] == '.')
    {
        int i = 1;
        while(endptr[i] != '\0' && (endptr[i] >= 48 && endptr[i] <= 57))
            i++;
        if(!(endptr[i] == '\0' || (endptr[i] == 'f' && endptr[i + 1] == '\0')))
            return(std::cout << "impossible" << std::endl, -1);
        std::cout << nb << std::endl;
    }
    else
        return(std::cout << "impossible" << std::endl, -1);
    return 0; 
}


int print_float(std::string str)
{
    
    char *endptr;
    std::cout << "float: ";
    double nb = strtod(str.c_str(), &endptr);
    if(errno == ERANGE )
        return(std::cout << "impossible" << std::endl, -1);
    if(std::isnan(nb))
        return(std::cout << "nanf" << std::endl, 0);
    if(std::isinf(nb))
    {
        if(nb > 0)
            return(std::cout << "+inff" << std::endl, 0);
        else
            return(std::cout << "-inff" << std::endl, 0);
    }
    if(endptr[0] != '\0' && endptr[0]  == 'f' && endptr[1]  == '\0')
        return(std::cout << std::fixed << std::setprecision(1) << nb << "f" << std::endl, 0);
    else if(endptr[0] != '\0')
        return(std::cout << "impossible" << std::endl, -1);
    std::cout << std::fixed << std::setprecision(1) << nb << "f" << std::endl;
    return 0;
}
int print_double(std::string str)
{
    
    char *endptr;
    std::cout << "double: ";
    double nb = strtod(str.c_str(), &endptr);
    if(errno == ERANGE )
        return(std::cout << "impossible" << std::endl, -1);
    if(std::isnan(nb))
        return(std::cout << "nan" << std::endl, 0);
    if(std::isinf(nb))
    {
        if(nb > 0)
            return(std::cout << "+inf" << std::endl, 0);
        else
            return(std::cout << "-inf" << std::endl, 0);
    }
    if(endptr[0] != '\0' && endptr[0]  == 'f' && endptr[1]  == '\0')
        return(std::cout << std::fixed << std::setprecision(1) << nb  << std::endl, 0);
    else if(endptr[0] != '\0')
        return(std::cout << "impossible" << std::endl, -1);
    std::cout << std::fixed << std::setprecision(1) << nb << std::endl;
    return 0;
}


void ScalarConverter::convert(std::string str)
{
        print_char(str);
        print_int(str);
        print_float(str);
        print_double(str);
}