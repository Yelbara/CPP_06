#ifndef DATA_HPP
#define DATA_HPP
#include <string>

class Data {
    public:
        Data();
        Data(const Data& other);
        Data& operator=(const Data& other);
        ~Data();
        int         a;
        float       b;
        std::string c;
};

#endif