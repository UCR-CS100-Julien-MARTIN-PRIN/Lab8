#ifndef __OPERATORS_HPP__
#define __OPERATORS_HPP__

#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>

#include "base.hpp"
#include "iterator.hpp"

using namespace std;

class Op : public Base
{
	private:
		double value;

	public:
		Op(double value_)
		{
			this->value = value_;
		};
		
		virtual Iterator* create_iterator()
		{
			Iterator* result = new NullIterator(this);
			return result;
		};

		virtual Base* left() {return nullptr;};
		virtual Base* right() {return nullptr;};


		virtual double evaluate() { return this->value; };
		virtual string stringify() { return (to_string(this->value)); };
		virtual void count(CountVisitor* cv) { cv->visit_op(); };
};



class Rand : public Base
{
	private:
		double value;

	public:
		Rand ()
		{
			this->value = rand()%100;
		};
		
		virtual Iterator* create_iterator()
		{
			Iterator* result = new NullIterator(this);
			return result;
		};

		virtual Base* left() {return nullptr;};
		virtual Base* right() {return nullptr;};
		
		virtual double evaluate() { return this->value; };
		virtual string stringify() { return (to_string(this->value)); };
		virtual void count(CountVisitor* cv) { cv->visit_rand(); };
};



class Mult : public Base
{
	private:
		Base* a;
		Base* b;
	
	public:
		Mult(Base* a_, Base* b_)
		{
			this->a = a_;
			this->b = b_;	
		};
		
		virtual Iterator* create_iterator()
		{
			Iterator* result = new BinaryIterator(this);
			return result;
		};
		virtual Base* left() {return this->a;};
		virtual Base* right() {return this->b;};


		virtual double evaluate() { return (this->a->evaluate() * this->b->evaluate()); };
		virtual string stringify() { return (to_string(this->a->evaluate()) + " * " + to_string(this->b->evaluate())); };
		virtual void count(CountVisitor* cv) { cv->visit_mult(); };
};



class Div : public Base
{
	private:
		Base* a;
		Base* b;

	public:
		/* Constructors */
		Div(Base* a_, Base* b_)
		{
			this->a = a_;
			this->b = b_;
		};
		
		virtual Iterator* create_iterator()
		{
			Iterator* result = new BinaryIterator(this);
			return result;
		};

		virtual Base* left() {return this->a;};
		virtual Base* right() {return this->b;};

		virtual double evaluate() { return (this->a->evaluate() / this->b->evaluate()); };
		virtual string stringify() { return (to_string(this->a->evaluate()) + " / " + to_string(this->b->evaluate())); };
		virtual void count(CountVisitor* cv) { cv->visit_div(); };
};

class Add : public Base
{
	private:
		Base* a;
		Base* b;

	public:
		/* Constructors */
		Add(Base* a_, Base* b_)
		{
			this->a = a_;
			this->b = b_;
		};
		
		virtual Iterator* create_iterator()
		{
			Iterator* result = new BinaryIterator(this);
			return result;
		};

		virtual Base* left() {return this->a;};
		virtual Base* right() {return this->b;};
		
		virtual double evaluate() { return (this->a->evaluate() + this->b->evaluate()); };
		virtual string stringify() { return (to_string(this->a->evaluate()) + " + " + to_string(this->b->evaluate())); };
		virtual void count(CountVisitor* cv) { cv->visit_add(); };
};



class Sub : public Base
{
	private:
		Base* a;
		Base* b;

	public:
		/* Constructors */
		Sub(Base* a_, Base* b_)
		{
			this->a = a_;	
			this->b = b_;
		};

		virtual double evaluate() { return (this->a->evaluate() - this->b->evaluate()); };
		virtual string stringify() { return (to_string(this->a->evaluate()) + " - " + to_string(this->b->evaluate())); };

		virtual Iterator* create_iterator()
		{
			Iterator* result = new BinaryIterator(this);
			return result;
		};

		virtual Base* left() {return this->a;};
		virtual Base* right() {return this->b;};


		virtual double evaluate() { return (this->a->evaluate() - this->b->evaluate()); };
		virtual string stringify() { return (to_string(this->a->evaluate()) + " - " + to_string(this->b->evaluate())); };
		virtual void count(CountVisitor* cv) { cv->visit_sub(); };
};



class Pow : public Base
{
	private:
		Base* a;
		Base* p;

	public:
		/* Constructors */
		Pow(Base* a_, Base* power)
		{
			this->a = a_;
			this->p= power;
		};

		virtual double evaluate() 
		{
			double x = this->a->evaluate();
			double y = this->p->evaluate();
			double temp = this->a->evaluate();			

			for(int i = 0; i < y; i++)
			{
				x = x * temp;
			};
			
			return x;
		};
		
		virtual Iterator* create_iterator()
		{
			Iterator* result = new BinaryIterator(this);
			return result;
		};

		virtual Base* left() {return this->a;};
		virtual Base* right() {return this->p;};
	
		virtual string stringify() { return (to_string(this->a->evaluate()) + " ** " + to_string(this->p->evaluate()));};
		virtual void count(CountVisitor* cv) { cv->visit_pow(); };
};

#endif
