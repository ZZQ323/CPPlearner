#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>

using namespace std;

const int mod=1e9+7;
#define ll long long

int num[20];
ll f[20][200];

ll DFS(int pos,int sum,bool flag)
{
    if(pos<=0)
        return sum;
    if( !flag &&  ~f[pos][sum] )
        return  f[pos][sum];
    ll ret=0;
    int lim=(flag?num[pos]:9);
    for(int i=0;i<=lim;++i){
        ret=( ret+DFS(pos-1,sum+i,flag && i==num[pos]) )%mod;
    }

    if(!flag)
        f[pos][sum]=ret;
    return  ret;
}

ll calc(ll x)
{
    int len=0;
    while(x){
        num[++len]=x%10;
        x/=10;
    }
    return DFS(len,0,true);
}

int main(int argc,char**argv)
{
    int T;
    scanf("%d",&T);
    memset(f,-1,sizeof(f));
    while(T--){
        ll l,r;
        scanf("%lld%lld",&l,&r);
        ll temp=calc(r)-calc(l-1);
        printf("%lld\n",(temp+mod)%mod);
    }

    return 0;
}