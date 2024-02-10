#include<utility>
#include<list>

#ifndef TUTORIAL_HASH_HPP
#define TUTORIAL_HASH_HPP

const int N=1e5+100;
const int mod=11;//初始化的mod值
int m;//关键字集合的长度

//线性探测
namespace linear{
    int hs[N];
    void insert(int x)
    {
        int cnt=1;
        int hsNum=x%mod;
        for(;hs[hsNum]!=x && cnt<m ;++cnt){
            if( hs[hsNum]==-1){
                hs[hsNum]=x;
                return ;
            }
            hsNum=(hsNum+1)%m;
        }
    }

    std::pair<int,int> search(int x)
    {
        int cnt=1;
        int hsNum=x%mod;
        for(;cnt<m;++cnt){
            if( hs[hsNum]==x )
                return {hsNum,cnt};
            hsNum=(hsNum+1)%m;
        }
        return {-1,cnt};
    }
}


//二次探测
//就只是hsNum=( x%mod+( sqr(cnt+1>>1) )*Odd(cnt)%m+m) %m;
namespace quadratic{
    int hs[N];
    using ll=long long ;

    auto Odd=[](int x)-> int {
        return x&1?1:-1;
    };
    auto sqr=[](ll x)-> ll {
        return x*x;
    };

    void insert(int x)
    {
        int cnt=1;
        int hsNum=x%mod;
        for(;hs[hsNum]!=x && cnt<m ;++cnt){
            if( hs[hsNum]==-1){
                hs[hsNum]=x;
                return ;
            }
            hsNum=( x%mod+( sqr(cnt+1>>1) )*Odd(cnt)%m+m) %m;
        }
    }

    std::pair<int,int> search(int x)
    {
        int cnt=1;
        int hsNum=x%mod;
        for(;cnt<m;++cnt){
            if( hs[hsNum]==x )
                return {hsNum,cnt};
            hsNum=( x%mod+( sqr(cnt+1>>1) )*Odd(cnt)%m+m) %m;
        }
        return {-1,cnt};
    }
}

//链表法
namespace linklist
{
    using std::list;
    list<int>hs[N];

//    同时用于插入和删除
    int search(int x)
    {
        int hsNum=x%mod;
        int indx=0;
        auto it=hs[hsNum].begin();
        for(;it!=hs[hsNum].end();it++,++indx){
            if( *it == x)break;
        }
        return (it==hs[hsNum].end())?(hs[hsNum].push_front(x),-1):indx+1;
    }

}

#endif
