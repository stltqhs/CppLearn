//
// Created by yuqing on 2022/4/17.
//
#include <iostream>

void foo(char *);

void foo(int);

int main()
{
    if (std::is_same<decltype(NULL), decltype(0)>())
    {
        std::cout << "NULL == 0" << std::endl;
    }

    if (std::is_same<decltype(NULL), decltype((void *)0)>()) {
        std::cout << "NULL == ((void *)0)" << std::endl;
    }

    if (std::is_same<decltype(NULL), std::nullptr_t>())
    {
        std::cout << "NULL == std::nullptr_t" << std::endl;
    }

    if (std::is_same<decltype(nullptr), std::nullptr_t>())
    {
        std::cout << "nullptr == std::nullptr_t" << std::endl;
    }

    foo(0);
    foo(nullptr);
}

void foo(char *)
{
    std::cout << "foo(char*) is called" << std::endl;
}

void foo(int i)
{
    std::cout << "foo(int) is called" << std::endl;
}