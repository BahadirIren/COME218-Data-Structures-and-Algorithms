/* 

    Search Algorithms
        Fill an array with N random numbers and search for an integer x value (linear search)
            1- Iterative Algorithm
            2- Recursive Algorithm

*/

#include <iostream>
#include <cstdlib>

#define N 10
#define NOT_FOUND -1

// prototype
int linearSearch(int *a, int x);
int linearSearchRec(int *a, int x, int start, int end);

int main()
{
    srand(time(NULL));
    int *a = new int[N];

    for (int i = 0; i < N; i++)
    {
        a[i] = rand() % N; // between 0 - (N - 1)
    }

    std::cout << linearSearch(a, 5) << std::endl;
    std::cout << linearSearchRec(a, 5, 0, N) << std::endl;
}

// if we chose N to 1000000 then algorithm work properly
// time complexity is linear, space complexity is const
int linearSearch(int *a, int x)
{
    for (int i = 0; i < N; i++)
    {
        if (a[i] == x)
            return i;
    }
    return NOT_FOUND;
}

// if we chose N to 1000000 then we run out of space (stackoverflow)
// time complexity is linear, space complexity is linear
int linearSearchRec(int *a, int x, int start, int end)
{
    if (start == end) // N-1 index so start == end return not found
        return NOT_FOUND;
    if (a[start] == x)
        return start;
    return linearSearchRec(a, x, ++start, end); // start++ doesnt work (++start works)
}