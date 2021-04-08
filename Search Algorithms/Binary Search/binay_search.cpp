/* 

    Search Algorithms
        Fill an array with N random numbers and search for an integer x value (binary search)
            1- Iterative Algorithm
            2- Recursive Algoritm

            For iterative version: 
                space complexity is constant, 
                time complexity is N, N/2, N/4, N/8, ..., N/2^d => 1 = N/2^d => logN = d

            For recursive version:
                space complexity ?
                time complexity ?
                T(N) = T(N/2) + 1
                T(N/2) = T(N/4) + 1
                ....
                T(2) = T(1) + 1
                Simplfy this set of equations so that you get T(N) = O(logN)
            
*/

#include <iostream>

#define N 10
#define NOT_FOUND -1

// prototype
int binarySearch(int *a, int x, int low, int high);
int binarySearchRec(int *a, int x, int low, int high);
void sort(int *a, int size);
void print(int *a, int size);

int main()
{
    srand(time(NULL));
    int *a = new int[N];

    for (int i = 0; i < N; i++)
    {
        a[i] = rand() % N; // between 0 - (N - 1)
    }
    print(a, N);
    sort(a, N);
    print(a, N);
    std::cout << binarySearch(a, 5, 0, N) << std::endl;
    std::cout << binarySearchRec(a, 5, 0, N) << std::endl;
}

int binarySearch(int *a, int x, int low, int high)
{

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] < x)
            low = mid + 1;
        else if (a[mid] > x)
            high = mid - 1;
        else
            return mid;
    }
    return NOT_FOUND;
}

int binarySearchRec(int *a, int x, int low, int high)
{
    int mid = (low + high) / 2;
    if (low > high)
        return NOT_FOUND;
    if (a[mid] < x)
        return binarySearchRec(a, x, mid + 1, high);
    else if (a[mid] > x)
        return binarySearchRec(a, x, low, mid - 1);
    else
        return mid;
}

// insertion sort, ascending order
void sort(int *a, int size)
{
    int insertValue, j;

    for (int i = 1; i < size; i++)
    {
        insertValue = a[i];
        j = i;
        while ((j > 0) && (a[j - 1] > insertValue))
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = insertValue;
    }
}

void print(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << a[i] << "  ";
    }
    std::cout << std::endl;
}
