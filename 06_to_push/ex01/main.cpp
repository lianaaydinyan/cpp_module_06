#include "Serializer.hpp"

int main()
{
    Data dat;
    dat.value = 42;
    uintptr_t intPtr = Serializer::serialize(&dat);
    Data* u_ptr = Serializer::deserialize(intPtr);
    std::cout << intPtr << std::endl;
    std::cout << u_ptr << std::endl;
    return 0;
}