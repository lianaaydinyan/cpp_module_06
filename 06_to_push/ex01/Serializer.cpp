#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& copy)
{
    (void)copy;
}

uintptr_t Serializer::serialize(Data *pointer)
{
    return (reinterpret_cast<uintptr_t>(pointer));
}

Data* Serializer::deserialize(uintptr_t num)
{
 return (reinterpret_cast<Data*>(num));
}

Serializer& Serializer::operator=(const Serializer& copy)
{
    (void)copy;
    return (*this);
}

Serializer::~Serializer()
{

}