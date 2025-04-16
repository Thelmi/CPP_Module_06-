#include "Serializer.hpp"  // Make sure this includes the Serializer class

#include <iostream>

int main()
{
    Data* originalData = new Data;
    originalData->name = "Taha";

    std::cout << "Original data: " << originalData->name << std::endl;

    uintptr_t serializedData = Serializer::serialize(originalData);
    std::cout << "Serialized data (uintptr_t): " << serializedData << std::endl;

    Data* deserializedData = Serializer::deserialize(serializedData);

    std::cout << "Deserialized data: " << deserializedData->name << std::endl;

    if (originalData == deserializedData)
    {
        std::cout << "Success: The original pointer and deserialized pointer are the same!" << std::endl;
    } else {
        std::cout << "Error: The original pointer and deserialized pointer do not match!" << std::endl;
    }

    delete originalData;

    return 0;
}
