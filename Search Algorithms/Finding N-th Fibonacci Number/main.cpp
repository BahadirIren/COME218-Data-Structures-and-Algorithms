/*
    Finding N-th Fibonacci number algorithm 1,1,2,3,5,8,13,21,31....( fib(5) = 8, fib(6) = 13 )
        - Give an iterative algorithm (space complexity is constant, time complexity is linear)
        - Give a naive textbook recursion (space complexity is linear, time complexity is exponential (2^N))
        - Can we do better with recursion (space complexity is linear, time complexity is linear) (like tail recursive)
*/

#include <iostream>

int fib(int n);
int fibRec(int n);
int fibRecBetter(int n, int a, int b);

int main()
{
    std::cout << fib(5) << std::endl;
    std::cout << fibRec(5) << std::endl;
    std::cout << fibRecBetter(5, 1, 1) << std::endl;
}

// fibonacci iterative
int fib(int n)
{
    int n1 = 1, n2 = 1, sum = 0;
    if (n == 0)
        return n1;
    if (n == 1)
        return n2;
    for (int i = 2; i <= n; i++)
    {
        sum = n1 + n2;
        n1 = n2;
        n2 = sum;
    }
    return sum;
}

// fibonacci recursive
int fibRec(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    return fibRec(n - 2) + fibRec(n - 1);
}

// fibonacci recursive better way
int fibRecBetter(int n, int a, int b)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fibRecBetter(n - 1, b, a + b);
}