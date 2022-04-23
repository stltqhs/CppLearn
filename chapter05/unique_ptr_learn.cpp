//
// Created by yuqing on 22-4-23.
//
#include <iostream>
#include <memory>

int main()
{
    auto pointer = std::make_unique<int>(1);
//    auto pointer2 = pointer;
    auto pointer2 = std::move(pointer);

    std::cout << "pointer=" << pointer.get() << std::endl;
    std::cout << "pointer2=" << *pointer2 << std::endl;
}