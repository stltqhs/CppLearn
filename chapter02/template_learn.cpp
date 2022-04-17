//
// Created by yuqing on 2022/4/17.
//
#include <iostream>

// 1.别名
template<typename T>
class Dummy{
public:
    T value;
};

template<typename T>
using AliasDummy = Dummy<T>;

// 2.变长参数模板
template<typename... Ts>
class Magic
{};

template<typename...Ts>
void magic(Ts... args)
{
    std::cout << sizeof...(args) << std::endl;
}

// 3.折叠表达式
template<typename... T>
auto sum(T... t)
{
    return (t + ...);
}

// 4.非类型参数模板推导
template<typename T, int BufSize>
class buffer_t
{
public:
    T data[BufSize];
};

template<auto value> void foo()
{
    std::cout << value << std::endl;
}

int main()
{
    Dummy<double> d;
    d.value = 10.5;

    AliasDummy<int> a;
    a.value = 20;

    std::cout << d.value << std::endl;
    std::cout << a.value << std::endl;

    Magic<int, double> m1;

    magic(1, 0.5, 3, 9);

    std::cout << sum(1,2,3,4,5) << std::endl;

    buffer_t<int, 20> int_buf;

    std::cout << sizeof(int_buf.data) / sizeof(int) << std::endl;

    foo<10>();
}