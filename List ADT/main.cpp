#include <iostream>
#include "MyArrayList.h"

int main()
{

    MyArrayList<int> list(2);
    list.insert(4);
    list.insert(3);
    list.insert(1);

    bool found;
    int x = 4;
    list.remove(x);
    list.retrieve(x, found);
    std::cout << found << std::endl;
    x = 1;
    list.retrieve(x, found);
    std::cout << found << std::endl;

    list.insert(7);
    list.print();
    std::cout << list[0] << std::endl;
    list[0] = 9;
    list.print();
}