#ifndef MYBOOK_H
#define MYBOOK_H

#include <iostream>

class MyBook
{
private:
    int isbn;
    std::string name;

public:
    MyBook(){};
    MyBook(int, std::string);
    void setIsbn(int);
    bool operator==(const MyBook &);
    friend std::ostream &operator<<(std::ostream &, const MyBook &);
};

MyBook::MyBook(int isbn, std::string name)
{
    this->isbn = isbn;
    this->name = name;
}

bool MyBook::operator==(const MyBook &otherBook)
{
    return (this->isbn = otherBook.isbn);
}

std::ostream &operator<<(std::ostream &os, const MyBook &item)
{
    os << item.name;
    return os;
}

#endif