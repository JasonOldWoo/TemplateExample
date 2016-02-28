#include <string>
#include <typeinfo>
#include <iostream>

template<typename T>
inline T const& max(T const& a, T const& b)
{
    return a < b ? b : a;
}

template<typename T>
inline T max2(T a, T b)
{
    return a < b ? b : a;
}

template<typename T>
void ref(T const& x)
{
    std::cout << "x in ref(T const&): " << typeid(x).name() << std::endl;
}

template<typename T>
void nonref(T x)
{
    std::cout << "x in nonref(T): " << typeid(x).name() << std::endl;
}

int main()
{
    std::string s;

    ::max("apple", "peach");    // OK
#if 0
    ::max("apple", "tomato");   // Error
    ::max("apple", s);          // Error
#endif

    ::max2("apple", "tomato");
#if 0
    ::max2("apple", s);         // Error
#endif

    ref("Hello");
    nonref("Hello");

    return 0;
}
