#include "Base.hpp"

Base* generate(void) 
{
    srand(time(NULL));

    int choice = rand() % 3;
    if (choice == 0)
        return new A;
    else if (choice == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p) 
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "C" << std::endl;
    }
    else
    {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) 
{
    if (dynamic_cast<A*>(&p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(&p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(&p))
    {
        std::cout << "C" << std::endl;
    }
    else
    {
        std::cout << "Unknown type" << std::endl;
    }
}
