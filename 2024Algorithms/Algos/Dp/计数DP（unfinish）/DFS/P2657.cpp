#include<bits/stdc++.h>

using namespace std;
using ll = long long ;

constexpr int N=20;
ll dp[N][10][2][2];
// 不含前导零且相邻两个数字之差至少为 2 的正整数被称为 windy 数

/**
 * 
 * 切记！ prezero的目的是为了防止一路是0到底，生成了一个000000数字，
 * DFS过程本质上还是在想处理字符串一样自由组合各个位置上面的数字
 * 
 * 可以这么理解prezero，它是前面不存在数字的情况，这里说的prenumber=-1，其实就想表示这个意思，所以可以去掉
 * prezero本质上还是说明“前面没有东西”的意思，记得初始化为0
 * 
*/
ll DFS(int pos,int prenumber,bool nogap,bool prezero,bool flag,int num[])
{
    if( !nogap )return 0;
    if( !pos )return !prezero && nogap;
    if( ~dp[pos][prenumber][prezero][flag] )
        return dp[pos][prenumber][prezero][flag];
    ll ret=0;
    int end=(flag?num[pos]:9);
    for(int i=0;i<=end;++i){
        ret+=DFS(pos-1,i,
            prenumber==-1 || prezero ||  nogap && abs(i-prenumber)>=2,
            prezero && !i,flag && i==num[pos],num
        );
    }
    return dp[pos][prenumber][prezero][flag]=ret;
}

ll calc(ll x)
{
    if( x<=0 )return 0;
    int num[N];
    int len=0;
    while( x ){
        num[++len]=x%10;
        x/=10;
    }
    memset(dp,-1,sizeof(dp));
    return DFS(len,-1,1,1,1,num);
}

int main(int argc, char const *argv[])
{
    ll l,r;
    while(~scanf("%lld%lld",&l,&r)){
        printf("%lld\n", calc(r)-calc(l-1) );
    }
    return 0;
}
