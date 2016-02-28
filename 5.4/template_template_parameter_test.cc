#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "template_template_parammeter.h"

int main()
{
    try {
        Stack<int> intStack;        // stack of ints
        Stack<float> floatStack;    // stack of floats

        // operate int stack
        intStack.push(42);
        intStack.push(7);
        // operate float stack
        floatStack.push(7.7);

        // assign a stack of different type
        floatStack = intStack;

        // print float stack
        std::cout << floatStack.top() << std::endl;
        floatStack.pop();
        std::cout << floatStack.top() << std::endl;
        floatStack.pop();
        std::cout << floatStack.top() << std::endl;
        floatStack.pop();
    }

    catch (std::exception const& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;

        // int stack
        Stack<int, std::vector> vStack;
        // ....
        vStack.push(42);
        vStack.push(7);
        std::cout << vStack.top() << std::endl;
        vStack.pop();
    }
    
    return 0;
}
