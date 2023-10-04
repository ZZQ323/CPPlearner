#include <bits/stdc++.h>

using namespace std;

template <typename T>
concept container_compatible_range = requires(T t) {
    // 检查 T 是否是一个容器范围
    typename T::value_type;      // 存储的元素类型
    typename T::iterator;        // 迭代器类型
    typename T::const_iterator;  // 常量迭代器类型
    { t.begin() } -> typename T::iterator;             // 返回迭代器的 begin() 函数
    { t.end() } -> typename T::iterator;               // 返回迭代器的 end() 函数
    { t.cbegin() } -> typename T::const_iterator;       // 返回常量迭代器的 cbegin() 函数
    { t.cend() } -> typename T::const_iterator;         // 返回常量迭代器的 cend() 函数
};

template <container_compatible_range<T>R>
void assign_range(R&& rg) {
    // 实现赋值操作
    // ...
}

int main()
{
    std::vector<int> source = {1, 2, 3, 4, 5};
    std::vector<int> target;

    assign_range(source);  // 将 source 中的元素赋值给 target

    return 0;
}