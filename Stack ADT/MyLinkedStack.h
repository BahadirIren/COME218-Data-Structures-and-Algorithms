#ifndef MYLINKEDSTACK_H
#define MYLINKEDSTACK_H

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};

template <typename T>
class MyLinkedStack
{
private:
    Node<T> *topPtr;

public:
    MyLinkedStack();
    ~MyLinkedStack();
    bool isEmpty() const;
    bool isFull() const;
    void getTop(T &) const;
    void pop();
    void push(T);
};

template <typename T>
MyLinkedStack<T>::MyLinkedStack()
{
    this->topPtr = NULL;
}

template <typename T>
MyLinkedStack<T>::~MyLinkedStack()
{
    while (!isEmpty())
    {
        pop();
    }
}

template <typename T>
bool MyLinkedStack<T>::isEmpty() const
{
    return (this->topPtr == NULL);
}

template <typename T>
bool MyLinkedStack<T>::isFull() const
{
    Node<T> *tempPtr = NULL;
    try
    {
        tempPtr = new Node<T>;
        delete tempPtr;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}

template <typename T>
void MyLinkedStack<T>::getTop(T &item) const
{
    if (isEmpty())
    {
        std::cout << "Stack is already empty!" << std::endl;
        return;
    }
    item = this->topPtr->data;
}

template <typename T>
void MyLinkedStack<T>::pop()
{
    if (isEmpty())
    {
        std::cout << "Stack is already empty!" << std::endl;
        return;
    }
    Node<T> *tempPtr;
    tempPtr = this->topPtr;
    this->topPtr = this->topPtr->next;
    delete tempPtr;
}

template <typename T>
void MyLinkedStack<T>::push(T item)
{
    if (isFull())
    {
        std::cout << "Stack is already full!" << std::endl;
        return;
    }
    Node<T> *tempPtr = new Node<T>;
    tempPtr->data = item;
    tempPtr->next = this->topPtr;
    this->topPtr = tempPtr;
}

#endif