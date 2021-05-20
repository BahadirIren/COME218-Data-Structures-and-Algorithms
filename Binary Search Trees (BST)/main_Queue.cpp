#include "MyPriorityQueue.h"
#include <iostream>

int main()
{
    MyPriorityQueue<int, MyLinkedBST<int> > priorityQueue;

    priorityQueue.insert(3);
    priorityQueue.insert(5);
    priorityQueue.insert(2);

    while (!priorityQueue.isEmpty())
    {
        std::cout << priorityQueue.get() << std::endl;
    }
}