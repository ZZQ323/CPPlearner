#include<bits/stdc++.h>

using namespace std;

using ll=long long ;
using pii=pair<int,int>;

const int mod=998244353;
const int Bits=1100;//状态压缩
const int N=20;

/***
 * 状态压缩只能被用一次，如果想要更好的效果，可以反复使用的那种，必须分开写10个cnt
 *  搞得我调试半天
*/

int k;
ll ten[N]={1};
pair<ll,ll> dp[N][Bits];

pair<ll,ll>
check(int state){
    int num=0;
    for(int i=0;i<10;++i){
        if( state&(1<<i) ){
            ++num;
            if( num>k ){
                return {0,0};
            }
        }
    }
    return {1,0};
}

pair<ll,ll> /*第一个返回值是方案数，第二个是总合（儿子）*/ 
DFS(int pos,int state,bool lead,bool flag,int num[])
{
    if( !check(state).first )return {0,0};
    if( pos<=0 )return check(state);
    if(!flag and !lead and ~dp[pos][state].first ){
        return dp[pos][state];
    }
    pair<ll,ll> ret={0,0};
    int end=(flag?num[pos]:9);
    for(int i=0;i<=end;++i){
        pair<ll,ll> tmp;
        if( lead && i==0 ){
            tmp=DFS(pos-1,state,lead and !i,flag and i==num[pos],num);
        }else{
            tmp=DFS(pos-1,state|(1<<i),lead and !i,flag and i==num[pos],num);
        }
        ret.first=(ret.first+tmp.first)%mod;
        //first方案数也容易爆longlong，只要是mod答案，那么所有的因子都应该取模
        ret.second=(ret.second+(tmp.second+tmp.first%mod*i%mod*ten[pos-1]%mod)%mod)%mod;
    }
    if(!flag and !lead){
        dp[pos][state]=ret;
    }
    return ret;
}

pair<ll,ll> calc(ll x)
{
    if( x<=0 )return {0,0};
    int num[N];
    int len=0;
    while( x ){
        num[++len]=x%10;
        x/=10;
    }
    return DFS(len,0,1,1,num);
}

int main(int argc, char const *argv[])
{
    // memset(dp,0xff,sizeof(dp));
    for(int i=0;i<N;++i){
        if( i>=1 )
            ten[i]=(ten[i-1]*10)%mod;
        for(int j=0;j<Bits;++j){
            dp[i][j]={-1,-1};
        }
    }
    ll l,r;
    while( ~scanf("%lld%lld%d",&l,&r,&k) ){
        printf("%lld\n",(calc(r).second+mod-calc(l-1).second)%mod );
    }
    return 0;
}
