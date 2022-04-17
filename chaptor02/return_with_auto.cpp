//
// Created by yuqing on 2022/4/17.
//
#include <iostream>

template<typename T, typename U>
auto add(T x, U y)
{
    return x + y;
}

int main()
{
    auto sum = add(1, 0.5);
    std::cout << sum << std::endl;
    if (std::is_same<decltype(sum), double>()) {
        std::cout << "sum is double" << std::endl;
    }
}