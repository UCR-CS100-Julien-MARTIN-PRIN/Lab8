#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>

#include "visitor.hpp"
#include "iterator.hpp"

using namespace std;

class Base {
	
	public:
        	/* Constructors */
        	Base() {};

        	/* Pure Virtual Functions */
        	virtual double evaluate() = 0;
        	virtual std::string stringify() = 0;
		virtual Iterator* create_iterator() = 0;
		virtual CountVisitor* count() = 0;
		virtual void count(CountVisitor* cv) = 0;
		virtual Base* left() = 0;
		virtual Base* right() = 0;
};

#endif //__BASE_HPP__
