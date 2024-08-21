#ifndef Serializer_
#define Serializer_

#include "data.hpp"
# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# include <iomanip>
# include <stdint.h>


class Serializer
{
    private:
        Serializer(const Serializer& copy);
        Serializer();
    public:
        static uintptr_t serialize(Data *pointer);
        static Data *deserialize(uintptr_t num);
        Serializer &operator=(Serializer const &copy);
        ~Serializer();
};

#endif