/* 

    Search Algorithms
        Fill an array with N random numbers and search for an integer x value (binary search)
            1- Iterative Algorithm
            
*/

#include <iostream>

#define N 10
#define NOT_FOUND -1

// prototype
int binarySearch(int *a, int x, int low, int high);
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
    std::cout << binarySearch(a, 5, N - 1, 0) << std::endl;
}

int binarySearch(int *a, int x, int low, int high)
{
    // because array is sorted descending
    while (low >= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] < x)
            low = mid - 1;
        else if (a[mid] > x)
            high = mid + 1;
        else
            return mid;
    }
    return NOT_FOUND;
}

// insertion sort, descending order
void sort(int *a, int size)
{
    int insertValue, j;

    for (int i = 1; i < size; i++)
    {
        insertValue = a[i];
        j = i;
        while ((j > 0) && (a[j - 1] < insertValue))
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
