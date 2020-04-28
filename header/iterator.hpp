#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include <stack>
#include "FactorySimple.hpp"
#include "container.hpp"

class Base;

enum ChildIndicator { left, right, end };

class Iterator 
{
    protected:
        Base* self_ptr;

    public:
        Iterator(Base* ptr) { this->self_ptr = ptr; };

        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool is_done() = 0;
        virtual Base* current() = 0;
};

class BinaryIterator : public Iterator 
{
    protected:
        ChildIndicator c;

    public:
        BinaryIterator(Base* ptr) : Iterator(ptr) {};

        void first();
        void next();
        bool is_done();
        Base* current();
};

class UnaryIterator : public Iterator 
{
    protected:
        ChildIndicator c;

    public:
        UnaryIterator(Base* ptr) : Iterator(ptr) {};

        void first();
        void next();
        bool is_done();
        Base* current();
};

class NullIterator : public Iterator 
{
    public:
        NullIterator(Base* ptr) : Iterator(ptr) {};

        void first() {}
        void next() {}
        
	bool is_done() 
	{
            return true;
        }

        Base* current() { return nullptr; }
};

class PreorderIterator : public Iterator {
    protected:
        std::stack<Iterator*> iterators;

    public:
        PreorderIterator(Base* ptr) : Iterator(ptr) {};

        void first()
        {
            Iterator* it = self_ptr->create_iterator();
            it->first();
            iterators.push(it);
        };
        void next()
        {
            Iterator* it = current()->create_iterator();
            it->first();
            iterators.push(it);
            while(iterators.top()->is_done())
            {
                iterators.pop();
                if(!is_done())
                {
                    iterators.top()->next();
                }
            }
        };
            
        bool is_done()
        {
            bool result = false;
            if(iterators.empty())
            {
                result = true;
            }
            return result;
        };
        Base* current() {return iterators.top()->current();};
};

#endif
