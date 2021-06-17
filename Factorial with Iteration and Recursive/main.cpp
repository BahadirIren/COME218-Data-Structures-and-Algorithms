/* 

Implement a factorial (0! = 1)
    1- Use iteration: space complexity is constant, time complexity is linear
    2- Use recursion: space complexity is linear, time complexity is linear
    3- Use tail recursion: better than recursive

*/

#include <iostream>

// prototypes
int factorialIteration(int num);
int factorialRecursive(int num);
int factorialRecursiveTail(int num, int x);

int main()
{
    std::cout << factorialIteration(4) << std::endl;
    std::cout << factorialRecursive(4) << std::endl;
    std::cout << factorialRecursiveTail(4, 1) << std::endl;
}

// iteration, requires less space (factorial and i)
// space analysis is constant (we need 2 variable to get result)
int factorialIteration(int num)
{
    int factorial = 1;

    for (int i = 2; i <= num; i++)
    {
        factorial *= i;
    }
    return factorial;
}

// recursive, requires more spaces in order to keep track of the previous results
// space analysis is growing linearly
int factorialRecursive(int num)
{
    if (num == 1)
        return 1;
    if (num == 0)
        return 1;
    return num * factorialRecursive(num - 1);
}

// tail recursive better than recursive because it keeps the result
// only go forward with, result is send to the parameter of the function
int factorialRecursiveTail(int num, int x)
{
    if (num == 1)
        return x;
    if (num == 0)
        return x;
    return factorialRecursiveTail(num - 1, num * x);
}
