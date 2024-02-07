#include<bits/stdc++.h>

using namespace std;

using ll=long long;

/**
 * 采用dp[N][N][2][2][2][2][2][2][2][2][2][2]超时了，不知道为什么
 * 
 * 
*/

constexpr int N=20;
ll dp[N][N];

ll DFS(int pos,int not_0,bool lead,bool flag,int num[])
{
    if( not_0 > 3)return 0;
    if( pos<=0 )return not_0<=3 && !lead;
    if(!lead && !flag &&  ~dp[pos][not_0] ){
        return dp[pos][not_0];
    }
    ll ret=0;
    int end=(flag?num[pos]:9);
    for(int i=0;i<=end;++i){
        if( lead and !i){
            ret+=DFS(pos-1,not_0,lead && !i,flag && i==num[pos],num);
        }else{
            ret+=DFS(pos-1,not_0+(i!=0),lead && !i,flag && i==num[pos],num);
        }
    }
    if( !lead && !flag){
        dp[pos][not_0]=ret;
    }
    return ret;
}

ll calc(ll x,int base)
{
    if( x<=0 )return 0;
    int len=0;
    int num[N];
    while( x ){
        num[++len]=x%base;
        x/=base;
    }
    memset(dp,-1,sizeof(dp));
    return DFS(len,0,1,1,num);
}

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d",&t);
    ll l,r; 
    while(t--){
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",calc(r,10)-calc(l-1,10));
    }
    return 0;
}
