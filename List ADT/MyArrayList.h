#ifndef MYARRAYLIST_H
#define MYARRAYLIST_H

template <typename T>
class MyArrayList
{

private:
    int maxLength;
    int length;
    T *array;
    bool isFull() const;  // it is not changing the state of the object just checking the status
    bool isEmpty() const; // it is not changing the state of the object just checking the status

public:
    MyArrayList(int = 100);
    ~MyArrayList();
    int getLength() const;
    void retrieve(T &item, bool &found);
    void insert(T item);
    void remove(T &item);
    void makeEmpty();
    void print() const;
    T &operator[](int);      // to get the element of the array
    T operator[](int) const; // just for the const case  ,not implemented
};

// Constructor
template <typename T> // we should implement every function of the template
MyArrayList<T>::MyArrayList(int maxLength)
{
    this->maxLength = maxLength;
    array = new T[maxLength];
    length = 0;
}

// Destructor
template <typename T> // we should implement every function of the template
MyArrayList<T>::~MyArrayList()
{
    delete[] array;
}

/*
        Observer Functions
*/
template <typename T>
bool MyArrayList<T>::isFull() const
{
    return (this->length == this->maxLength);
}

template <typename T>
bool MyArrayList<T>::isEmpty() const
{
    return (this->length == 0);
}

template <typename T>
int MyArrayList<T>::getLength() const
{
    return this->length;
}

template <typename T>
void MyArrayList<T>::retrieve(T &item, bool &found)
{
    // linear search
    found = false;
    for (int i = 0; i < this->length; i++)
    {
        if (array[i] == item)
        {
            found = true;
            break;
        }
    }
}
/*  
    Transformer Functions

*/
template <typename T>
void MyArrayList<T>::insert(T item)
{
    if (this->isFull())
    {
        std::cout << "List is full ! " << std::endl;
        return;
    }
    array[this->length] = item;
    this->length++;
}

template <typename T>
void MyArrayList<T>::remove(T &item)
{
    if (this->isEmpty())
        return;
    for (int i = 0; i < this->length; i++)
    {
        if (item == array[i])
        {
            array[i] = array[length - 1];
            this->length--;
            return;
        }
    }
}

template <typename T>
void MyArrayList<T>::makeEmpty()
{
    this->length = 0;
}

/*

        Observer + transformer operation
*/
template <typename T>
T &MyArrayList<T>::operator[](int index)
{
    return array[index];
}

/*
        Iterator operations
*/

template <typename T>
void MyArrayList<T>::print() const
{
    for (int i = 0; i < this->length; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

#endif