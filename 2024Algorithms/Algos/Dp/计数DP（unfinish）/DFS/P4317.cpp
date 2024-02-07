#include<bits/stdc++.h>

using namespace std;
using ll =long long ;

constexpr int mod=10000007;
const int N=64;

ll dp[N][N];

ll DFS(int pos,int _1,bool perzero,bool flag,int num[])
{
    if( pos<=0 )return !perzero * _1;
    if(!perzero and !flag and ~dp[pos][_1] )
        return dp[pos][_1];
    ll ret=1;
    int end=(flag?num[pos]:1);
    for(int i=0;i<=end;++i){
        ll temp=DFS(pos-1,_1+(i==1),perzero and !i,flag and (i==num[pos]),num);
        if( temp )
            ret=(ret*temp)%mod;
    }
    if( !perzero and !flag ){
        dp[pos][_1]=ret;
    }
    return ret;
}

ll calc(ll x)
{
    int num[N];
    int len=0;
    while( x ){
        num[++len]=x&1;
        x>>=1;
    }
    return DFS(len,0,1,1,num);
}

int main(int argc, char const *argv[])
{
    ll n;
    memset(dp,0xff,sizeof(dp));
    while( ~scanf("%lld",&n) ){
        printf("%lld\n",calc(n));
    }
    return 0;
}
