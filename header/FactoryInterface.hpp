#ifndef __FACTORYINTERFACE_HPP__
#define __FACTORYINTERFACE_HPP__

#include <iostream>
#include <string>

#include "base.hpp"

class FactoryInterface
{
	public:
		/* Constructors */
		FactoryInterface() {};

		virtual Base* parse(char** input, int length) = 0;
};

#endif
