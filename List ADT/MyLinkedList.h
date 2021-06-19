#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};

template <typename T>
class MyLinkedList
{
private:
    unsigned int length;
    Node<T> *firstPtr;

public:
    MyLinkedList();
    ~MyLinkedList();
    bool isFull() const;
    bool isEmpty() const;
    unsigned int getLength() const;
    void retrieve(T &item, bool &found) const;
    void insert(T item);
    void remove(T &item);
    void makeEmpty();
    void print() const;
};

template <typename T>
MyLinkedList<T>::MyLinkedList()
{
    this->length = 0;
    this->firstPtr = NULL;
}

template <typename T>
MyLinkedList<T>::~MyLinkedList()
{
    // this->makeEmpty();
}

template <typename T>
bool MyLinkedList<T>::isFull() const
{
    // no limits on length, so try to check if memory is full ...
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
bool MyLinkedList<T>::isEmpty() const
{
    return (this->firstPtr == NULL);
}

template <typename T>
unsigned int MyLinkedList<T>::getLength() const
{
    return this->length;
}

template <typename T>
void MyLinkedList<T>::retrieve(T &item, bool &found) const
{
    bool moreToSearch;
    Node<T> *currentPointer = this->firstPtr;
    found = false;

    moreToSearch = (currentPointer != NULL);
    while (moreToSearch && !found)
    {
        if (item == currentPointer->data)
        {
            found = true;
            std::cout << "I found it " << currentPointer->data << std::endl;
        }
        else
        {
            currentPointer = currentPointer->next;
            moreToSearch = (currentPointer != NULL);
        }
    }
}

template <typename T>
void MyLinkedList<T>::insert(T item)
{
    if (this->isFull())
    {
        std::cout << "Not enough space !!!" << std::endl;
        return;
    }
    else
    {
        Node<T> *tempPointer = new Node<T>;
        tempPointer->data = item;
        tempPointer->next = this->firstPtr;
        this->firstPtr = tempPointer;

        this->length++;
    }
}
template <typename T>
void MyLinkedList<T>::remove(T &item)
{
    if (this->isEmpty())
        return;
    Node<T> *currentPtr = this->firstPtr;
    Node<T> *tempPtr = NULL;
    // find node to delete
    if (item == currentPtr->data)
    { // first node ?
        tempPtr = currentPtr;
        this->firstPtr = this->firstPtr->next;
    }
    else
    {
        while (currentPtr->next != NULL && !(item ==
                                             currentPtr->next->data))
            currentPtr = currentPtr->next;
        if (currentPtr->next != NULL)
        {
            tempPtr = currentPtr->next;
            currentPtr->next = currentPtr->next->next;
        }
    }
    if (tempPtr != NULL)
    {
        delete tempPtr;
        length--;
    }
}

template <typename T>
void MyLinkedList<T>::makeEmpty()
{
    Node<T> *tempPtr = NULL;
    while (this->firstPtr != NULL)
    {
        tempPtr = this->firstPtr;
        this->firstPtr = this->firstPtr->next;
        delete tempPtr;
    }
    this->length = 0;
}

template <typename T>
void MyLinkedList<T>::print() const
{
    Node<T> *currentPtr = this->firstPtr;
    while (currentPtr != NULL)
    {
        std::cout << currentPtr->data << " ";
        currentPtr = currentPtr->next;
    }
    std::cout << std::endl;
}
#endif