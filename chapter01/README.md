# 第 1 章
这一章讲述现代 C++ 弃用的特性和 C 语言的兼容性

# 弃用的特性
弃用的特性如下：

* 字符串字面量只能赋值给 `const char *`，不能是 `char *`。原因是如果是 `char *`，编译器会把字符串分配在只读的区域，想要通过指针修改内容时会报段错误。使用 `const char *` 后表示指针内容不能修改，因此是安全的。
* `noexcept` 替代 `unexpected_handler` 、 `set_unexpected()`
* `unique_ptr` 替代 `auto_ptr`
* `register` 弃用，没有实际含义
* `bool` 的 ++ 弃用
* 应当使用 `static_cast`、`reinterpret_cast`、`const_cast` 做类型转换

# C 兼容

使用 `extern "C"` 引入 C 库。例如：

```c
#ifdef __cplusplus
extern "C" {
#endif
   // your c code 
#ifdef __cplusplus
};
#endif
```
