# 第 3 章

## Lambda

语法：
```text
[捕获列表](参数列表) mutable(可选) 异常属性 -> 返回类型 {
// 函数体
}
```

重要的是要理解"捕获列表"：
* 值传递是，定义时便已经完成值复制；
* 引用传递；
* 隐式捕获，`&` 和 `=` 的使用；

## 函数对象包装器

### std::function

由于函数指针是非类型安全的，使用 std::function 可以包装一个函数指针。

```c++
int foo(int para) {
    return para;
}
std::function<int(int)> func = foo;
```

### std::bind 和 std::placeholder

```c++
// 将参数1,2绑定到函数 foo 上，但是使用 std::placeholders::_1 来对第一个参数进行占位
auto bindFoo = std::bind(foo, std::placeholders::_1, 1,2);
// 这时调用 bindFoo 时，只需要提供第一个参数即可
bindFoo(1);
```

## 右值引用

