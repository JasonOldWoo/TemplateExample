#include <iostream>
#include <deque>

template <typename T,
    template <typename ELEM, typename ALLOC = std::allocator<ELEM> >class CONT = std::deque>
class Stack
{
private:
    CONT<T> elems_;
// ....
};

int main()
{
    std::cout << "just a test" << std::endl;
    return 0;
}
