#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate()
{
    std::srand(std::time(nullptr));
    int choice = std::rand() % 3;
    switch (choice) {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            return nullptr;
    }
}
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Undefined" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch(const std::exception& e)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch(const std::exception& e)
        {
            try
            {
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch(const std::exception& e)
            {
                (void)e;
                std::cout << "We can only cast to A, B, C >_<" << std::endl;
            }
        }
    }
}

