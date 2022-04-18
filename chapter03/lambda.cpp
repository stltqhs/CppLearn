//
// Created by yuqing on 2022/4/17.
//
#include <iostream>

void lambda_value_capture()
{
    int value = 1;
    auto copy_value = [value] {
        return value;
    };
    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value=" << stored_value << std::endl;
}

void lambda_reference_capture()
{
    int value = 1;
    auto copy_value = [&value] {
        return value;
    };
    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value=" << stored_value << std::endl;
}

void lambda_reference_auto()
{
    int a = 1;
    int b = 2;
    auto add = [&] {
        return a + b;
    };
    int c = add();
    std::cout << c << std::endl;
}

int main()
{
    lambda_value_capture();

    lambda_reference_capture();

    lambda_reference_auto();
}