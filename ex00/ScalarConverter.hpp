#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <climits>

class ScalarConverter { 
    public:
        static void convert(std::string str);
    private:
        ScalarConverter(); 
        ScalarConverter(const ScalarConverter& other); 
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();


};
#endif