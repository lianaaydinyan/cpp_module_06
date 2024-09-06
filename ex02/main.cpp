#include "Base.hpp"



int main(void)
{

    Base *p;
    std::srand(std::time(NULL));
    for (int i = 0; i < class_count; i++)
    {
        p = generate();
        std::cout << "* Identify -> ";
        identify(p);
        std::cout << "& Identify -> ";
        identify(*p);
        delete p;
    }
    return (0);
}