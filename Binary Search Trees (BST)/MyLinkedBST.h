#ifndef MYLINKEDBST_H
#define MYLINKEDBST_H
#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
};

template <typename T>
class MyLinkedBST
{
private:
    Node<T> *rootPtr;
    void removeAll(Node<T> *&nodePtr);
    int getLength(Node<T> *nodePtr) const;
    void getMin(Node<T> *nodePtr, T &item) const;
    void getMax(Node<T> *nodePtr, T &item) const;
    void retrieve(Node<T> *nodePtr, T &item, bool &found) const;
    void insert(Node<T> *&nodePtr, T item);
    void remove(Node<T> *&tree, T item);
    void getPredecessor(Node<T> *tree, T &item);
    void removeNode(Node<T> *&tree);
    void printPreOrder(Node<T> *nodePtr) const;
    void printInOrder(Node<T> *nodePtr) const;
    void printPostOrder(Node<T> *nodePtr) const;

public:
    MyLinkedBST();
    ~MyLinkedBST();
    bool isFull() const;
    bool isEmpty() const;
    int getLength() const;
    void getMin(T &item) const;
    void getMax(T &item) const;
    void retrieve(T &item, bool &found) const;
    void insert(T item);
    void remove(T item);
    void print(int order = 1) const;
};

/*   Constructor and Desctructor  */
template <typename T>
MyLinkedBST<T>::MyLinkedBST()
{
    this->rootPtr = NULL;
}

template <typename T>
MyLinkedBST<T>::~MyLinkedBST()
{
    removeAll(rootPtr);
}

template <typename T>
void MyLinkedBST<T>::removeAll(Node<T> *&nodePtr)
{
    if (nodePtr != NULL)
    {
        removeAll(nodePtr->left);
        removeAll(nodePtr->right);
        delete nodePtr;
    }
}

/*    Observer methods  */
template <typename T>
bool MyLinkedBST<T>::isFull() const
{
    Node<T> *location;
    try
    {
        location = new Node<T>;
        delete location;
        return false;
    }
    catch (const std::bad_alloc exception)
    {
        return true;
    }
}

template <typename T>
bool MyLinkedBST<T>::isEmpty() const
{
    return (this->rootPtr == NULL);
}

template <typename T>
int MyLinkedBST<T>::getLength() const
{
    return getLength(rootPtr);
}
template <typename T>
int MyLinkedBST<T>::getLength(Node<T> *nodePtr) const
{
    if (nodePtr == NULL)
        return 0;
    else
        return getLength(nodePtr->left) + getLength(nodePtr->right) + 1;
}

template <typename T>
void MyLinkedBST<T>::getMin(T &item) const
{
    if (this->rootPtr == NULL)
    {
        std::cout << "Already empty!" << std::endl;
        return;
    }

    getMin(rootPtr, item);
}

template <typename T>
void MyLinkedBST<T>::getMin(Node<T> *nodePtr, T &item) const
{
    if (nodePtr->left == NULL)
    {
        item = nodePtr->data;
        return;
    }
    return getMin(nodePtr->left, item);
}

template <typename T>
void MyLinkedBST<T>::getMax(T &item) const
{
    if (this->rootPtr == NULL)
        return;
    getMax(this->rootPtr, item);
}

template <typename T>
void MyLinkedBST<T>::getMax(Node<T> *nodePtr, T &item) const
{
    if (nodePtr->right == NULL)
    {
        item = nodePtr->data;
        return;
    }
    return getMax(nodePtr->right, item);
}

template <typename T>
void MyLinkedBST<T>::retrieve(T &item, bool &found) const
{
    retrieve(this->rootPtr, item, found);
}

template <typename T>
void MyLinkedBST<T>::retrieve(Node<T> *nodePtr, T &item, bool &found) const
{
    if (nodePtr == NULL)
        found = false;
    else if (item < nodePtr->data)
        retrieve(nodePtr->left, item, found);
    else if (item > nodePtr->data)
        retrieve(nodePtr->right, item, found);
    else
    {
        item = nodePtr->data;
        found = true;
    }
}

template <typename T>
void MyLinkedBST<T>::insert(T item)
{
    insert(this->rootPtr, item);
}

template <typename T>
void MyLinkedBST<T>::insert(Node<T> *&nodePtr, T item)
{
    bool found;
    retrieve(item, found);
    if (!found)
    {
        if (nodePtr == NULL)
        {
            nodePtr = new Node<T>;
            nodePtr->right = NULL;
            nodePtr->left = NULL;
            nodePtr->data = item;
        }
        else if (item < nodePtr->data)
        {
            insert(nodePtr->left, item);
        }
        else
        {
            insert(nodePtr->right, item);
        }
    }
    else
    {
        std::cout << "Already exists! Not added to tree" << std::endl;
        return;
    }
}

template <typename T>
void MyLinkedBST<T>::remove(T item)
{
    remove(rootPtr, item);
}

template <typename T>
void MyLinkedBST<T>::remove(Node<T> *&tree, T item)
{
    if (tree == NULL)
        return;
    if (item < tree->data)
        remove(tree->left, item); // look in left subtree
    else if (item > tree->data)
        remove(tree->right, item); // look in right subtree
    else
        removeNode(tree); // Node found
}

template <typename T>
void MyLinkedBST<T>::removeNode(Node<T> *&tree)
{
    T item;
    Node<T> *tempPtr;
    tempPtr = tree;
    if (tree->left == NULL)
    {
        tree = tree->right;
        delete tempPtr;
    }
    else if (tree->right == NULL)
    {
        tree = tree->left;
        delete tempPtr;
    }
    else
    {
        getPredecessor(tree->left, item);
        tree->data = item;
        remove(tree->left, item); // remove predecessor
    }
}

template <typename T>
void MyLinkedBST<T>::getPredecessor(Node<T> *tree, T &item)
{
    while (tree->right != NULL)
        tree = tree->right;
    item = tree->data;
}

template <typename T>
void MyLinkedBST<T>::print(int order) const
{
    if (order == 0)
    {
        std::cout << "pre order: ";
        printPreOrder(rootPtr);
        std::cout << std::endl;
    }
    else if (order == 1)
    {
        std::cout << "in order: ";
        printInOrder(rootPtr);
        std::cout << std::endl;
    }
    else if (order == 2)
    {
        std::cout << "post order: ";
        printPostOrder(rootPtr);
        std::cout << std::endl;
    }
}

template <typename T>
void MyLinkedBST<T>::printPreOrder(Node<T> *nodePtr) const
{
    if (nodePtr != NULL)
    {
        std::cout << nodePtr->data << " ";
        printPreOrder(nodePtr->left);
        printPreOrder(nodePtr->right);
    }
}
template <typename T>
void MyLinkedBST<T>::printInOrder(Node<T> *nodePtr) const
{
    if (nodePtr != NULL)
    {
        printInOrder(nodePtr->left);
        std::cout << nodePtr->data << " ";
        printInOrder(nodePtr->right);
    }
}
template <typename T>
void MyLinkedBST<T>::printPostOrder(Node<T> *nodePtr) const
{
    if (nodePtr != NULL)
    {
        printPostOrder(nodePtr->left);
        printPostOrder(nodePtr->right);
        std::cout << nodePtr->data << " ";
    }
}
#endif