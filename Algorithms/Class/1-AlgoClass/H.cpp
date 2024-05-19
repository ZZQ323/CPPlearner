#include<iostream>
#include<cstring>

using namespace std;

constexpr int N=1e5+100;
int A[N],last[N],disSum[N],dp[N];

/*
    * 如果
    *
    *
    *
*/

int main(int argc, char const *argv[])
{
    int n,q,w;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        memset(last,-1,sizeof(last));
        memset(disSum,0,sizeof(disSum));
        dp[1]=n;
        for(int i=0;i<n;++i){
            scanf("%d",A+i);
            ++disSum[i-last[A[i]]];
            last[A[i]]=i;
        }
        for(int i=n-1;i;--i)
            disSum[i]+=disSum[i+1];
        int Lastprefix=0;
        for(int i=2;i<=n;++i){
            Lastprefix += last[A[n-i+1]] == n-i+1;
            dp[i] = dp[i-1] + disSum[i] - Lastprefix;
        }
        while(q--)
        {
            scanf("%d",&w);
            printf("%d\n",dp[w]);
        }
    }
    return 0;
}
