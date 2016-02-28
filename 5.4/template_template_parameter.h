#ifndef __TEMPLATE_TEMPLATE_PARAMETER_H__
#define __TEMPLATE_TEMPLATE_PARAMETER_H__

#include <deque>
#include <stdexcept>
#include <memory>

template<typename T,
    template<typename ELEM_T, typename = std::allocator<ELEM_T> >class CONT = std::deque>
class Stack
{
private:
    CONT<T> elems_;         // elements

public:
    void push(T const&);    // push element
    void pop();             // pop element
    T top() const;          // return top element
    bool empty() const          // if stack is empty
    {
        return elems_.empty();
    }
    
    // assign a stack which has T2 elem type
    template<typename T2,
        template<typename ELEM_T2, typename = std::allocator<ELEM_T2> >class CONT2>
    Stack<T,CONT>& operator=(Stack<T2, CONT2> const&);
};

template<typename T,
    template<typename, typename>class CONT>
void Stack<T, CONT>::push(T const& elem)
{
    elems_.push_back(elem);  // append new element
}

template<typename T,
    template<typename, typename>class CONT>
void Stack<T, CONT>::pop()
{
    if (elems_.empty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    elems_.pop_back();       // remove last element
}

template<typename T,
    template<typename, typename>class CONT>
T Stack<T, CONT>::top() const
{
    if (elems_.empty()) {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return elems_.back();          // return copy of the last element
}

template<typename T,
    template<typename, typename> class CONT>
        template<typename T2,
            template<typename, typename> class CONT2>
Stack<T, CONT>& Stack<T, CONT>::operator=(Stack<T2, CONT2> const& op2)
{
    if ((void*) this == (void*)& op2) {
        return *this;
    }
    
    Stack<T2, CONT2> tmp(op2);  // create copy of assigned stack
    elems_.clear();             // remove all the elements
    
    while (!tmp.empty()) {
        elems_.push_front(tmp.top());
        tmp.pop();
    }
    
    return *this;
}
#endif  // __TEMPLATE_TEMPLATE_PARAMETER_H__
