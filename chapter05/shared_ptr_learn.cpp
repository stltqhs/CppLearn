//
// Created by yuqing on 22-4-23.
//
#include <iostream>
#include <memory>

void foo(std::shared_ptr<int> ptr)
{
    (*ptr)++;
}

int main()
{
    auto pointer = std::make_shared<int>(10);

    foo(pointer);

    std::cout << "pointer=" << *pointer << ",used_count=" << pointer.use_count() << std::endl;

    auto pointer2 = pointer;

    std::cout << "pointer2=" << *pointer2 << ",used_count=" << pointer.use_count() << std::endl;

    pointer2.reset();

    std::cout << "pointer2=" << pointer2.get() << ",pointer used_count=" << pointer.use_count() <<std::endl;
}
