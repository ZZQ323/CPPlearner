#include<bits/stdc++.h>

using namespace std;

constexpr int N=20;
using ll=long long ;

ll dp[N][11][11][2][2][2][2];


/**
 * 注意！记忆化的时候务必把所有参数都记录上
 * 因为很可能存在“不同状态，但是更新了同一个方块的尴尬情况
 * 还有不要写全称，能缩写就缩写，但是一开始写全称可以辅助自己理解和检查
 * 
*/
ll DFS(int pos,int ppr,int pre,bool con,bool _4,bool _8,bool flag,int num[])
{
    // 号码中要出现至少3个相邻的相同数字；
    // 号码中不能同时出现 8 和 4
    // 必须同时包含两个特征才满足条件
    // 手机号码一定是 11 位数，且不含前导的 0
    if( _4 and _8)return 0;
    if(pos<=0)return con;
    if( ~dp[pos][ppr][pre][_4][_8][con][flag] ){
        return dp[pos][ppr][pre][_4][_8][con][flag];
    }
    ll ret=0;
    int end=(flag?num[pos]:9);
    for(int i=0;i<=end;++i){
        ret+=DFS(pos-1,pre,i,con or (i==pre and i==ppr),_4 or i==4,_8 or i==8,flag and i==num[pos],num);
    }
    return dp[pos][ppr][pre][_4][_8][con][flag]=ret;
}

ll calc(ll x)
{         
    if( x<1e10 )
        return 0;
    int num[N];
    int len=0;
    while( x ){
        num[++len]=x%10;
        x/=10;
    }

    memset(dp,0xff,sizeof(dp));
    ll ret=0;
    for(int i=1;i<=num[len];++i){
        ret+=DFS(len-1,-1,i,0,i==4,i==8,i==num[len],num);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    ll l,r;
    scanf("%lld%lld",&l,&r);
    printf("%lld",calc(r)-calc(l-1));
    // while( ~ ){
    // }
    return 0;
}
