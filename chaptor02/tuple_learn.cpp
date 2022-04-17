//
// Created by yuqing on 2022/4/16.
//

#include <iostream>
#include <tuple>

std::tuple<int, double, std::string> foo() {
    return std::make_tuple(1, 2.3, "123");
}

int main()
{
    auto [x, y, z] = foo();
    std::cout << x << ";" << y << ";" << z << std::endl;
}