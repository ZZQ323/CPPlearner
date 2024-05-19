#include<iostream>

using namespace std;

using ll=long long ;
int qpow(int a,int n,const int mod)
{
    int ret=1;
    while(n){
        if( n&1 )
            ret=1ll*ret*a%mod;
        a=1ll*a*a%mod;
        n>>=1;
    }return ret;
}

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,p;
        scanf("%d%d%d",&a,&b,&p);
        printf("%d\n",qpow(a,b,p));
    }
    return 0;
}
