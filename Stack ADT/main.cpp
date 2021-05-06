#include <iostream>
#include "MyLinkedStack.h"

int main()
{
    MyLinkedStack<int> stack;

    stack.push(5);
    stack.push(3);
    stack.push(2);

    int item;
    stack.getTop(item);
    std::cout << item << std::endl;
    stack.pop();

    stack.getTop(item);
    std::cout << item << std::endl;
    stack.pop();

    stack.push(7);

    while (!stack.isEmpty())
    {
        stack.getTop(item);
        std::cout << item << std::endl;
        stack.pop();
    }

    // string data type
    MyLinkedStack<std::string> stack2;
    std::string str;
    str = "hello";
    stack2.push(str);
    str = "world";
    stack2.push(str);

    while (!stack2.isEmpty())
    {
        stack2.getTop(str);
        std::cout << str << std::endl;
        stack2.pop();
    }
}