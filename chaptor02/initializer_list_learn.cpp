//
// Created by yuqing on 2022/4/16.
//
#include <initializer_list>
#include <vector>
#include <iostream>

class MagicFoo
{
public:
    std::vector<int> vec;
    MagicFoo(std::initializer_list<int> list)
    {
        for (std::initializer_list<int>::iterator it = list.begin(); it != list.end(); it++)
        {
            vec.push_back(*it);
        }
    }
};

int main()
{
    MagicFoo foo({1,2,3,4});
    std::cout << "MagicFoo:" << std::endl;

    for (std::vector<int>::iterator it = foo.vec.begin(); it != foo.vec.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

