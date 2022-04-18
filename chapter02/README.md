# 第 2 章

## 常量 `nullptr` 和 `constexpr`

### `nullptr`
`nullptr` 是取代 `NULL` 的。

有些编译器会将 `NULL` 定义为 `((void *) 0)` 或者直接就是 `0`，此外，c++ 不允许将 ` void *`隐式转换为其他类型。为了让 `char *ch = NULL` 通过编译，编译器会将 `NULL` 定义为 0。但是下面怎么办：

```c++
void foo(char*);
void foo(int);
```

如果执行 `foo(NULL)` 时，是调用 `foo(char*)` 还是 `foo(int)`。

为了消除歧义，使用 `nullptr` 表示空指针，它的类型是 `std::nullptr_t`。

### constexpr

为了让编译器在编译时计算出表达式，避免运行时计算，从而加快运行速度。
注意与 `const` 的区别，如下：

```c++
const int len2 = len + 1;
constexpr int len_2_constexpr = 1 + 2 + 3;
```

`constexpr` 是让编译器编译时做计算的常量表达式，而 `const` 定义只读变量。

`constexpr` 可用在变量和函数。

## if/switch 可声明变量

```c++
if (const std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), 3);
    it != vec.end()) {
    *it = 4;
}
```

## 初始化参数列表

`std::initializer_list` 例子：

```c++
void foo(std::initializer_list<int> list)
{
    for (std::initializer_list<int>::iterator it = list.begin; it != list.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}
```

## 函数返回值支持 tuple

* `std::tuple`
* `std::make_tuple()`

## 类型推导

* `auto`
* `decltype(表达式)`

## 控制流

### if constexpr

```c++
template<typename T>
auto print_type_info(const T& t)
{
    if constexpr (std::is_integral<T>::value)
    {
        return t + 1;
    }
    else
    {
        return t + 0.001;
    }
}
```

### foreach

```c++
for (auto element : vec)
{
    
}
```

## 模板

模板的哲学在于将一切能够在编译期处理的问题放在编译期进行处理。

### 外部模板

模板只有在使用时才会被编译器实例化，C++11 引入额外控制实例化时机的方法。

```c++
template class std::vector<bool>; // 强行本此编译文件中实例化
extern template class std::vector<double>; // 不在本此编译文件中实例化
```

### 尖括号 ">"

传统 C++ 中， >> 一律被当作右移运算符来处理。而嵌套模板中：

```c++
std::vector<std::vector<int>> matrix;
```

知道 C++11才能编译成功。

### 类型别名模板

`using` 可用于为函数和模板定义别名。

```c++
using NewProcess = int(*)(void *);
template<typename T>
using TrueDarkMagic = MagicType<std::vector<T>, std::string>;
```

### 变长参数模板

```c++
template<typename... Ts> class Magic;
```

可实现 `printf` 变长参数函数。

参数解包的方法：

* 递归模板函数
* 变参模板展开
* 初始化列表展开

### 折叠表达式

```c++
template<typename ...T>
auto sum(T ... t)
{
    return (t + ...)
}
```

### 非类型模板参数推导

```c
// 1
template<typename T, int BufSize>
class buffer_t;

// 2
template <auto value> void foo(){}
```

## 面向对象

### 委托构造

一个构造函数可以调用另一个构造函数。

### 继承构造

省去传统继承构造函数的参数书写。直接使用 `using` 即可完成。

### 显示虚函数重载

* `final`
* `override`

### 显示禁用默认构造函数

* `default`
* `delete`

### 强类型枚举

`enum class`