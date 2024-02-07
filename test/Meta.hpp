#ifndef TUTORIAL_META_HPP
#define TUTORIAL_META_HPP

// 类型比较
// 默认情况下，类型不相同
template <typename T, typename U>
struct are_same {
    static constexpr bool value = false;
};

// 特化：当两个类型相同时
template <typename T>
struct are_same<T, T> {
    static constexpr bool value = true;
};

//common_type
// 主模板定义
template <typename... Types>
struct common_type;

// 递归模板定义：处理两个类型的情况
template <typename T1, typename T2>
struct common_type<T1, T2> {
    using type = decltype(true ? declval<T1>() : declval<T2>());
};

// 递归模板定义：处理多个类型的情况
template <typename T1, typename T2, typename... Rest>
struct common_type<T1, T2, Rest...> {
    using type = typename common_type<typename common_type<T1, T2>::type, Rest...>::type;
};


// std::move，强转右值
template<class T>
constexpr
typename std::remove_reference<T>::type 
    move(T&&t)
noexcept
{
    return static_cast<typename 
        std::remove_reference<T>::type&&>(t);
}

// 去掉引用 --- 条件编译
template <typename T>
struct remove_reference {
    using type = T;
};

template <typename T>
struct remove_reference<T&> {
    using type = T;
};

template <typename T>
struct remove_reference<T&&> {
    using type = T;
};


// std::forward 可以实现完美转发参数，
// 也就是保持参数原来的样子，继续传递
template <typename T>
constexpr 
T&& 
forward_impl(typename 
    std::remove_reference<T>::type& t) 
noexcept 
{
    return static_cast<T&&>(t);
}

template <typename T>
constexpr 
T&& 
forward_impl(typename 
    std::remove_reference<T>::type&& t) 
noexcept 
{
    // 对右值引用进行完美转发
    return static_cast<T&&>(t);
}

template <typename T>
constexpr 
T&& 
forward(typename 
    std::remove_reference<T>::type& t) 
noexcept 
{
    // 调用 forward_impl 来处理左值引用
    return forward_impl<T>(t);
}

template <typename T>
constexpr 
T&& 
forward(typename 
    std::remove_reference<T>::type&& t) 
noexcept 
{
    // 调用 forward_impl 来处理右值引用
    return forward_impl<T>(std::move(t));
}


#endif //TUTORIAL_META_HPP
