#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data myData;

	myData.name = "Jeremiah";
	uintptr_t raw = Serializer::serialize(&myData);
	Data* deserializedData = Serializer::deserialize(raw);

	std::cout << "[ Addresses for data ]" << std::endl;
	std::cout << "Raw: " << raw << std::endl;
	std::cout << "Raw (hex): 0x" << std::hex << raw << std::endl;
	std::cout << "myData: " << &myData << std::endl;
	std::cout << "deserializedData: " << deserializedData << std::endl << std::endl;

	std::cout << "[ Serialization/Deserialization Check ]" << std::endl;
	if (deserializedData == &myData)
	{
		std::cout << "Success! Pointer serialized and deserialized.\n";
		std::cout << "Name: " << deserializedData->name << std::endl;
	}
	else
		std::cerr << "Error: serialization and deserialization failed.\n";
	return (0);
}
