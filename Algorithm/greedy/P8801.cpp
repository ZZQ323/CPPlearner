#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

#define ll long long

ll tenp[20]={1,};

enum OP{Add,Minus};
ll change(ll num,int pos,OP state)
{
    const int mod=10;
    --pos;
    ll temp=num/tenp[pos]%10;
    if(state==Add){
         num+=( (temp+1)%mod-temp )*tenp[pos];
    }else {
        num += ((temp + mod - 1) % mod - temp) * tenp[pos];
    }
    return  num;
}

ll ans,n,a,b;

void DFS(ll num,int cnta,int cntm)
{
    ans=max(ans,num);
    if(cnta<a && ){

    }else if(){

    }
}

int main(int argc,char**argv)
{
    for(int i=1;i<=18;++i)
        tenp[i]=tenp[i-1]*10;

    scanf("%lld%lld%lld",&n,&a,&b);


    return 0;
}