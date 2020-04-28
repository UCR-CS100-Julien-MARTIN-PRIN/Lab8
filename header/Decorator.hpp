#ifndef __DECORATOR_HPP__
#define __DECORATOR_HPP__

#include <iostream>
#include <string>
#include <cmath>
#include "iterator.hpp"
#include "base.hpp"

using namespace std;

class Decorator : public Base
{
	private:
		Base* child;

	public:
		/* Constructors */
		Decorator() {};
		Decorator(Base* child_) { this->child = child_; };
		virtual Iterator* create_iterator()
		{
			Iterator* result = new UnaryIterator(this);
			return result;
		};
		virtual Base* left() { return this->child; };
		virtual Base* right() { return nullptr; };
		virtual double evaluate() = 0;
		virtual std::string stringify() = 0;
		virtual void count(CountVisitor* cv) = 0;
};

#endif
