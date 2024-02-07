#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>

using namespace std;

// using ll = long long ;
typedef long long ll;

const int N=64;
ll dp[N][N][N][2][2];

/**
 * 切记！！ 前导0是不存在的，不能算在数字里面
 * 除非声明0011之类的数字合法
*/

ll DFS(int pos,int _1,int _0,bool prezero,bool flag,int num[])
{
    if( pos<=0 )return !prezero and (_1<=_0);
    if( ~dp[pos][_1][_0][prezero][flag] )
        return dp[pos][_1][_0][prezero][flag];
    ll ret=0;
    int end=(flag?num[pos]:1);
    for(int i=0;i<=end;++i){
        ret+=DFS(pos-1,_1+(i==1),_0+(!prezero and i==0),prezero and !i,flag and (i==num[pos]),num);
    }
    return dp[pos][_1][_0][prezero][flag]=ret;
}   

ll calc(ll x)
{
    if(x<=1)
        return 0;
    int num[N];
    int len=0;
    while( x ){
        num[++len]=x%2;
        x/=2;
    }
    memset(dp,0xff,sizeof(dp));
    return DFS(len,0,0,1,1,num);
}

int main(int argc, char const *argv[])
{
    ll l,r;
    while( ~scanf("%lld%lld",&l,&r) ){
        printf("%lld\n",calc(r)-calc(l-1));
    }
    return 0;
}
