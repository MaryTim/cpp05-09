#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    Data data;
    data.id = 1;
    data.name = "hello world";

    uintptr_t raw = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << &data << std::endl;
    std::cout << "Recovered pointer: " << deserialized << std::endl;

    if (deserialized == &data) {
        std::cout << "Pointers match" << std::endl;
        std::cout << "Deserialized Data - id: " << deserialized->id << ", name: " << deserialized->name << std::endl;
    } else {
        std::cout << "Failure: Pointers don't match." << std::endl;
    }
    return 0;
}