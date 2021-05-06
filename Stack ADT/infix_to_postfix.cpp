/*
    Simple postfix evaluator: (infix : 1 + 2) => (postfix: 12+) , (4+2)*(3+5) => 24+53+*

*/

#include <iostream>
#include "MyLinkedStack.h"

int evaluator(std::string expr);

int main()
{
    std::string expr = "24+53+*";
    std::cout << evaluator(expr) << std::endl;
}

int evaluator(std::string expr)
{
    MyLinkedStack<int> stack;
    int x, y;

    // c++11 required
    for (char c : expr)
    {
        if (isdigit(c))
        {
            stack.push(c - '0');
        }
        else
        {
            stack.getTop(x);
            stack.pop();
            stack.getTop(y);
            stack.pop();
            if (c == '+')
                x += y;
            else if (c == '*')
                x *= y;
            stack.push(x);
        }
    }
    stack.getTop(x);
    return x;
}