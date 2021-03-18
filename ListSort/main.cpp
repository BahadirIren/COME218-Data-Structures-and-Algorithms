/*
    How do we find top k values within N values?
    - ADT : List
    - Data Structure: array in C++
    - Algorithms:
    1.1- Use a basic sorting algorithm to sort the N values(use selection sort) (N^2)
    1.2- Use a basic sorting algorithm to sort the N values (use insertion sort) (N^2)
    2- Use a more advanced sorting to do same thing (NlogN)
    3- How about sorting first k elements. Then go through the remaining list and compare each element
	   to the min value in the sorted portion of the list. If an element is larger than the min, then put it in its 	
       right place in the sorted list and put the old min in its location. k^2 + (N-k)*k ~ about N*k operations
    4- ?

*/

#include <iostream>
#include <chrono> // for measure time, available >= c++11
using namespace std;

struct List
{
    int length;
    int *array;
};

// prototypes
void listPrintTopK(List *l, int k);
void listSortTopK(List *l, int k);
void listSortSelection(List *l);
void listSortInsertion(List *l);

int main()
{
    // random number generates
    srand(time(NULL));
    List l;
    l.length = 20;
    l.array = new int[l.length];

    for (int i = 0; i < l.length; i++)
    {
        l.array[i] = rand() % l.length;
    }

    // prints full list
    // listPrintTopK(&l, l.length);

    int K = 5;
    auto start = chrono::steady_clock::now(); // for measure
    // listSortSelection(&l);    // part of 1.1
    // listSortInsertion(&l);    // part of 1.2
    listSortTopK(&l, K); // part of 3

    auto end = chrono::steady_clock::now(); // for measure
    cout << "Elapsed time: " << chrono::duration<double>(end - start).count() << endl;

    listPrintTopK(&l, K);

    return 0;
}

// selection sort of the list with given lenght of k, descending
void listSortTopK(List *l, int k)
{
    int largest, temp;
    for (int i = 0; i < k; i++)
    {
        largest = i;
        for (int j = i + 1; j < k; j++)
        {
            if (l->array[j] > l->array[largest])
            {
                largest = j;
            }
        }
        temp = l->array[i];
        l->array[i] = l->array[largest];
        l->array[largest] = temp;
    }

    // checks whether the value of each number of the remaining part of the list is larger than the min value(compared one by one)
    int min = k - 1;
    for (int i = k; i < l->length; i++)
    {
        // if min is smaller than remaining part of the i`th value
        if (l->array[min] < l->array[i])
        {
            // swap the number
            temp = l->array[min];
            l->array[min] = l->array[i];
            l->array[i] = temp;

            // in order to put the new value its proper place we should check whether it is in the right place or not
            for (int j = 0; j < k; j++)
            {
                if (l->array[min] > l->array[j])
                {
                    temp = l->array[j];
                    l->array[j] = l->array[min];
                    l->array[min] = temp;
                }
            }
        }
    }
}

// insertion sort, descending
void listSortInsertion(List *l)
{
    int insertValue, j;

    for (int i = 1; i < l->length; i++)
    {
        insertValue = l->array[i];
        j = i;
        while ((j > 0) && (l->array[j - 1] < insertValue))
        {
            l->array[j] = l->array[j - 1];
            j--;
        }
        l->array[j] = insertValue;
    }
}

// selection sort, descending
// goes through the list one by one, puts the next small value(or large) in its proper place
void listSortSelection(List *l)
{
    int largest, temp;
    for (int i = 0; i < l->length; i++)
    {
        largest = i;
        for (int j = i + 1; j < l->length; j++)
        {
            if (l->array[j] > l->array[largest])
            {
                largest = j;
            }
        }
        temp = l->array[i];
        l->array[i] = l->array[largest];
        l->array[largest] = temp;
    }
}

void listPrintTopK(List *l, int k)
{
    for (int i = 0; i < k; i++)
    {
        cout << l->array[i] << " ";
    }
    cout << endl;
}
