#include "MyLinkedBST.h"
#include <iostream>

int main()
{

    MyLinkedBST<int> bst;

    int preOrder = 0;
    int inOrder = 1;
    int postOrder = 2;

    bst.insert(5);
    bst.insert(2);
    bst.insert(8);
    bst.insert(1);
    bst.insert(3);
    bst.insert(4);

    int item = 3;
    bool found;
    bst.retrieve(item, found);
    std::cout << found << std::endl;

    bst.print(preOrder);
    bst.print(inOrder);
    bst.print(postOrder);

    std::cout << bst.getLength() << std::endl;

    bst.remove(3);
    bst.print(1);

    bst.getMin(item);
    std::cout << item << std::endl;
}