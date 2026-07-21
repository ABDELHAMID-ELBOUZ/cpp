#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.i = 42;
    data.c = 'A';

    Data* ptr = &data;

    uintptr_t raw = Serializer::serialize(ptr);
    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original: " << ptr << std::endl;
    std::cout << "Serialized: " << raw << std::endl;
    std::cout << "Deserialized: " << restored << std::endl;
    std::cout << "Equal: " << (ptr == restored ? "true" : "false") << std::endl;
    std::cout << "Data.i: " << restored->i << std::endl;
    std::cout << "Data.c: " << restored->c << std::endl;

    return 0;
}
