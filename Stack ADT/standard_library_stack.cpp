#include <iostream>
#include <stack>
#include <vector>

int main()
{

    std::stack<int> s;

    s.push(0);
    s.push(1);
    s.push(2);

    // while (!s.empty())
    // {
    //     std::cout << s.top() << std::endl;
    //     s.pop();
    // }

    std::stack<int> s2;

    s2.swap(s);
    std::cout << s2.top() << std::endl;

    std::stack<int, std::vector<int> > s3;
    s3.push(3);
}