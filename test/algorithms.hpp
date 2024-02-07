#include "Meta.hpp"
#include <iostream>
#include <algorithm>
#include "staticSeqContainer.hpp"

// uninitialized_copy 和copy有什么区别

#ifndef TUTORIAL_ALGORITHMS_HPP
#define TUTORIAL_ALGORITHMS_HPP

//默认比较函数
template<class T>
struct Compare{
    bool operator()(const T& a,const T& b){
        return a<b;
    }
};

//默认执行函数
template<class T>
struct Log{
    void dosth(){
        std::cout<<"Do"<<'\n';
    }
};

//交换函数
template<class T,class U>
inline void
swap(T a,U b)noexcept
{
    common_type<T,U> temp=a;
    a=b;
    b=temp;
}


// 排序函数


// 冒泡排序
void BubbleSort(int a[],int n)
{
    int ret=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n-i;++j){
            if( a[j] > a[j+1] )
                swap(a[j],a[j+1]),++ret;
        }

    }
    cout<<ret<<'\n';
}

// 选择排序
void SeltionSort(int a[],int n)
{
    int ret=0;
    for(int i=1;i<=n;++i){
        int*maxn=a+i;
        for(int j=i+1;j<=n;++j){
            if( a[j] < *maxn )[
                maxn=a+j;
            ]
        }
        swap(*maxn,a[i]);
    }
    cout<<ret<<'\n';
}

// 树形选择排序


// 简单插入排序
void InserSort(int a[],int n,int gap=1)
{
    for(int i=gap+1;i<=n;++i){
        for(int j=i;j-gap>=1 && a[j] < a[j-gap];j-=gap){
            swap(a[j],a[j-gap]);
        }
        
        for(int i=1;i<=n;++i){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }
}

// 希尔排序
void ShellSort(int a[],int n)
{
    for(int gap=n>>1;gap >= 1;gap>>=1){
        InserSort(a,n,gap);
        output();
    }
}

// 堆上排序
void HeapAdjust(int a[],int s,int e)
{
    for(int nex=s<<1;nex<=e;nex<<=1)
    {
        if(nex+1<=e && a[nex] > a[nex+1])++nex;
        if(a[s] <= a[nex])break;
        swap(a[s],a[nex]);
        s=nex;
    }
}

void HeapSort(int a[],int n)
{
    for(int i=n>>1;i;--i)
        HeapAdjust(a,i,n);
}

// 分治，归并排序
void MergeSort(int a[],int l,int r)
{
    if(r-l<=1)return ;
    
    int mid=l+r>>1;
    MergeSort(a,l,mid);
    MergeSort(a,mid+1,r);
    int*tmp=new int[r-l+1];
    std::merge(a+l,a+mid+1,a+mid+1,a+r+1,tmp);
    std::copy(tmp,tmp+r-l+1,a+l);
    delete[] tmp;
}

// 快速（插入）排序-简写
void qsort(int a[],int l,int r)
{
    int len=r-l+1;
    if(len<=1)return ;
    // int flag=a[l+r>>1];
    int flag=a[l];
    int ql=l,qr=r;
    while( ql<=qr ){
        while( a[ql]<flag  )++ql;
        while( a[qr]>flag  )--qr;
        if( ql<=qr){
            swap(a[ql++],a[qr--]);
        }
    }
    output();
    qsort(a,l,qr);
    qsort(a,ql,r);
}   

// 快速（插入）排序-考试
void qsort(int a[],int l,int r)
{
    if( r-l+1 <=1)return ;
    int ql=l,qr=r;
    int flag=a[l];
    while( ql<qr )
    {
        // 大的qr先动，因为这个地方是空的，被保存在了flag里面
        while(ql<qr && a[qr]>=flag)--qr;
        a[ql]=a[qr];
        while(ql<qr && a[ql]<=flag)++ql;
        a[qr]=a[ql];
    }
    a[ql]=flag;
    output();
    qsort(a,l,ql-1);
    qsort(a,ql+1,r);
}



#endif //TUTORIAL_ALGORITHMS_HPP
