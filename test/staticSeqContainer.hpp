// 如果只允许iostream
#include<iostream>

#ifndef TUTORIAL_STATICSEQCONTAINER_HPP
#define TUTORIAL_STATICSEQCONTAINER_HPP

const int N=10;

//  静态数据结构不存在指针

// 单向链节点
template<class T>
struct FoNode{
    T data;
    int nex;

    void init()
    {nex=-1;}
};

// 双向链节点
template<class T>
struct BiNode{
    T data;
    int nex,pre;

    void init()
    {pre=nex=-1;}
};

// 静态单向链表使用的空间是从1开始的，0和后面的一连串是“操作系统管理”
template<class T>
struct SLFlist{
    FoNode<T> space[N];

//  将储存空间初始化为循环链表
    void InitMemSpace()
    {
        for(int i=0;i<N-1;++i){
            space[i].nex=i+1;
        }
        space[N-1].nex=0;
    }

// 分配储存空间
    int Malloc()
    {
        int newNode=space[0].nex;
        space[0].nex=space[newNode].nex;
        return newNode;
    }

// 回收
    void Free(int id)
    {
        space[id].nex=space[0].nex;
        space[0].nex=id;
    }

    size_t size()
    {return space[0].nex-1;}
};

// 静态双向链表，不是很实用
template<class T>
struct SLBlist{
    BiNode<T> space[N];

//  将储存空间初始化为循环链表
    void InitMemSpace()
    {
        for(int i=0;i<N;++i){
            space[i].nex=(i+1)%N;
            space[i].pre=(i+N-1)%N;
        }
    }

// 分配储存空间
    int Malloc()
    {
        int newNode=space[0].nex;
        space[0].nex=space[newNode].nex;
        space[space[newNode].nex].pre=0;
        space[newNode].init();
        return newNode;
    }

// 回收
    void Free(int id)
    {
        space[id].nex=space[0].nex;
        space[id].pre=0;
        space[space[id].nex].pre=id;
        space[space[id].pre].nex=id;
    }

    size_t size()
    {return space[0].nex-1;}
};

//栈
template<class T>
struct stack{
    T data[N];
    int tp=0;

    void push(T val)
    {data[++tp]=val;}

    void pop()
    {--tp;}

    T top()
    {return data[tp];}

    size_t size()
    {return tp;}
};

//队列
template<class T>
struct queue{
    T data[N];
    int bef=0,aft=0;

    void push(T val)
    {
        if( isfull() )
            exit(1);
        data[aft=(aft+1)%N]=val;
    }

    void pop()
    {
        if( isempty() )
            exit(1);
        bef=(bef+1)%N;
    }

    T front()
    {return data[bef+1];}

    bool isempty()
    {return bef==aft;}

    bool isfull()
    {return (aft+1)%N==bef;}

    size_t size()
    {return (aft+N-bef)%N;}
};


#endif //TUTORIAL_STATICSEQCONTAINER_HPP
