#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base
{
	public:
	    virtual ~Base() {}
};

class A : public Base
{
	public:
	    A() {}
	    ~A() {}
};

class B : public Base
{
	public:
	    B() {}
	    ~B() {}
};

class C : public Base
{
	public:
	    C() {}
	    ~C() {}
};

// Function declarations
Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif
