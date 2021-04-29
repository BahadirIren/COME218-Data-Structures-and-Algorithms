#include <iostream>
#include "MyLinkedList.h"
#include "MyArrayList.h"
#include "MyBook.h"

int main()
{
    // Array Based (start)
    std::cout << "\n----------- Array Based -----------\n"
              << std::endl;

    // integer data type (start)
    MyArrayList<int> list(2);
    list.insert(4);
    list.insert(3);
    list.insert(1);

    bool found;
    int x = 4;
    list.remove(x);
    list.retrieve(x, found);
    // by default when bool is false prints 0, otherwise 1
    // std::boolalpha enables us to print true or false instead of 1 and 0, respectively
    std::cout << std::boolalpha;
    std::cout << found << std::endl;

    x = 1;
    list.retrieve(x, found);
    std::cout << found << std::endl;

    x = 3;
    list.retrieve(x, found);
    std::cout << found << std::endl;

    list.insert(7);
    list.print();

    std::cout << list[0] << std::endl;
    list[0] = 9;
    list.print();

    std::cout << std::endl;
    // integer data type (end)

    // string data type (start)
    MyArrayList<std::string> list2(5);

    list2.insert("hello world");
    list2.insert("how are you");

    int length = list2.getLength();
    for (int i = 0; i < length; i++)
    {
        std::cout << list2[i] << std::endl;
    }

    std::string myStr = "hello world";
    list2.remove(myStr);
    list2.print();
    std::cout << std::endl;
    // string data type (end)

    // user defined data type (start)
    MyArrayList<MyBook> list3(100);

    MyBook book1(1111, "Intro to C++");
    list3.insert(book1);
    MyBook book2(2222, "Data Structures and Algorithms");
    list3.insert(book2);

    length = list3.getLength();
    for (int i = 0; i < length; i++)
    {
        std::cout << list3[i] << std::endl;
    }

    list3.remove(book1);
    list3.print();
    // user defined data type (end)

    std::cout << "\n-----------------------------------" << std::endl;
    // Array Based (end)

    // Linked List based (start)
    std::cout << "\n\n-------- Linked List Based --------\n"
              << std::endl;

    // integer data type (start)
    MyLinkedList<int> llist;

    llist.insert(4);
    llist.insert(3);

    bool found2 = false;
    int xx = 3;
    llist.retrieve(xx, found2);
    // integer data type (end)

    std::cout << "\n-----------------------------------\n"
              << std::endl;
    // Linked List based (end)
}