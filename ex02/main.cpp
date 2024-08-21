#include "Base.hpp"

int main(void)
{

    for (int i = 0; i < class_count; i++)
    {
        Base *p = generate();
        std::cout << "* Identify -> ";
        identify(p);
        std::cout << "& Identify -> ";
        identify(*p);
        delete p;
    }
    return (0);
}