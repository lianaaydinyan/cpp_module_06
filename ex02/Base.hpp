#ifndef Base_
#define Base_

#include <cstdlib>
#include <iostream>
#include <ctime>

#define class_count 15

class Base
{
    public:
        virtual ~Base();
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif