#ifndef MYPRIORITYQUEUE_H
#define MYPRIORITYQUEUE_H

#include "MyLinkedBST.h"

template <typename T, typename U>
class MyPriorityQueue
{
private:
    U priorityQueue;

public:
    MyPriorityQueue();
    bool isEmpty();
    void insert(T item);
    T get();
};

template <typename T, typename U>
MyPriorityQueue<T, U>::MyPriorityQueue()
{
}

template <typename T, typename U>
bool MyPriorityQueue<T, U>::isEmpty()
{
    if (priorityQueue.isEmpty())
        return true;
    return false;
}

template <typename T, typename U>
void MyPriorityQueue<T, U>::insert(T item)
{
    priorityQueue.insert(item);
}

template <typename T, typename U>
T MyPriorityQueue<T, U>::get()
{
    T item;
    priorityQueue.getMin(item);
    priorityQueue.remove(item);
    return item;
}

#endif