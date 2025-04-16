#include "Base.hpp"

int main()
{
    Base* obj = generate();

    std::cout << "Using pointer: ";
    identify(obj);

    std::cout << "Using reference: ";
    identify(*obj);

    delete obj;

    return 0;
}
