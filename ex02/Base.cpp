#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
};

Base* generate(void)
{
    srand(time(NULL)); // time(NULL) :> to get useconds_t. || srand(unsigned int seed); :> seed value to initialize the random number generator.
    int random = rand() % 3; // generates one number: 0 or 1 in all execution
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void    identify(Base* p)
{
    
    if(dynamic_cast<A*>(p))
    {
        std::cout << "TYPE A" << std::endl;
        return;
    }
    else
    {
        if(dynamic_cast<B*>(p))
        {
            std::cout << "TYPE B" << std::endl;
            return;
        }
        else if(dynamic_cast<C*>(p))
        {
            std::cout << "TYPE C" << std::endl;
            return;
        }
    }
    std::cout << "UNKNOWN TYPE" << std::endl;
}

void    identify(Base& p)
{
    // in this reference dynamic_cast work differently, it throws an exception if the cast fails
    // don't throw nullptr or 0 like pointer version
    /*-------- BECAUSE ----------*/
    /*
        inside references we have the actual object, not an nullptr or 0.
        int &r = 0; :> error
        int &r = nullptr; :> error
        so need throw exception if the cast fails
    */
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "TYPE A" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
        try
        {
            B& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "TYPE B" << std::endl;
            return;
        }
        catch(const std::exception& e)
        {
            try
            {
                C& c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "TYPE C" << std::endl;
                return;
            }
            catch(const std::exception& e)
            {
                std::cout << "UNKNOWN TYPE" << std::endl;
            }
        }
    }
}

