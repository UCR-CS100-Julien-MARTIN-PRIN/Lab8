#ifndef __BINARY_ITERATOR_HPP__
#define __BINARY_ITERATOR_HPP__

#include "../header/iterator.hpp"

enum ChildIndicator { left, right, end };

ChildIndicator c;

BinaryIterator::BinaryIterator(Base* ptr) : Iterator(ptr) {
    this->c = left;
}

void BinaryIterator::first() {
    this->c = left;
}
void BinaryIterator::next() {
    if(this->c == left) {
        this->c = right;
    }
    else if(this->c == right) {
        this->c = end;
    } 
    else {
        this->c = end;
    }
}
bool BinaryIterator::is_done() {
    if(this->c == end) {
        return true;
    }
    return false;
}
Base* BinaryIterator::current() {
    if(this->c == left) {
        return this->self_ptr->left();
    }
    else if(this->c == right) {
        return this->self_ptr->right();
    }
    return nullptr;
}
#endif
