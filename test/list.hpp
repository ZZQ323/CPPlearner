#include <cstddef>


#ifndef USR_LIST_HPP
#define USR_LIST_HPP

namespace ZZQ323 {

    

// 双向链表节点
template <typename T>
struct ListNode {
    T data;
    ListNode* prev;
    ListNode* next;

    ListNode(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T, typename Allocator = std::allocator<T>>
class List {
private:
    using NodeAllocator = typename 
    std::allocator_traits<Allocator>::template rebind_alloc<ListNode<T>>;

public:
    // 构造函数、析构函数等...

    // 插入元素到链表末尾
    void push_back(const T& value) {
        ListNode<T>* newNode = allocateNode(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        ++size_;
    }

    // 从链表末尾移除元素
    void pop_back() {
        if (!empty()) {
            ListNode<T>* lastNode = tail;
            tail = tail->prev;
            deallocateNode(lastNode);
            --size_;
        }
    }

    // 获取链表大小
    std::size_t size() const {
        return size_;
    }

    // 检查链表是否为空
    bool empty() const {
        return size_ == 0;
    }

private:
    ListNode<T>* head;   // 链表头
    ListNode<T>* tail;   // 链表尾
    std::size_t size_;   // 链表大小
    NodeAllocator nodeAllocator;  // 节点内存分配器

    // 分配节点内存
    ListNode<T>* allocateNode(const T& value) {
        ListNode<T>* newNode = nodeAllocator.allocate(1);
        try {
            std::allocator_traits<NodeAllocator>::construct(nodeAllocator, newNode, value);
        } catch (...) {
            nodeAllocator.deallocate(newNode, 1);
            throw;
        }
        return newNode;
    }

    // 释放节点内存
    void deallocateNode(ListNode<T>* node) {
        std::allocator_traits<NodeAllocator>::destroy(nodeAllocator, node);
        nodeAllocator.deallocate(node, 1);
    }
};


    

} // ZZQ323

#endif //USR_LIST_HPP
