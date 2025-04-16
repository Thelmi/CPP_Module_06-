#include "Serializer.hpp"

Serializer:: Serializer()
{
	
}

Serializer:: Serializer(Serializer &other)
{
	(void)other;
}

Serializer& Serializer:: operator=(const Serializer& other)
{
	(void)other;
	return *this; //double check this later
}

Serializer:: ~Serializer()
{
	
}
