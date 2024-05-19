#include<iostream>
#include<algorithm>

using namespace std;

using ll=long long ;
constexpr int N=1e6+100;
constexpr int mod=100003;
int dp[N];

int main(int argc, char const *argv[])
{
    int N,K;
    scanf("%d%d",&N,&K);
    dp[0]=1;
    for(int i=1;i<=N;++i){
        for(int k=1;k<=min(K,i);++k){
            dp[i]=(dp[i]+dp[i-k])%mod;
        }
    }printf("%d\n",dp[N]);
    return 0;
}
