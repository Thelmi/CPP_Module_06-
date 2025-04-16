#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef unsigned long uintptr_t;

struct Data
{
	std:: string name;
};

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer &other);
		Serializer& operator=(const Serializer& other);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr)
		{
			return reinterpret_cast<uintptr_t>(ptr);
		}

		static Data* deserialize(uintptr_t raw)
		{
			return reinterpret_cast<Data*>(raw);
		}
};

#endif