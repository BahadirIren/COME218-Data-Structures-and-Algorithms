#include "MyLinkedBST.h"
#include <iostream>

int main()
{

    MyLinkedBST<int> bst;
    bst.insert(5);
    bst.insert(7);
    bst.insert(3);
    int item;
    bst.getMin(item);
    std::cout << item << std::endl;

    bst.remove(3);
    bst.getMin(item);
    std::cout << item << std::endl;
}