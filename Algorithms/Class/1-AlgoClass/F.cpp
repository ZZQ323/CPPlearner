#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long Solve(int x, int n)
{
    // TODO: 递推第 n 轮的结果
    if(!n)return 1ll;
    return (x+1)*Solve(x,n-1);
}

int main()
{
    long long x, n;
    while(scanf("%lld%lld", &x, &n) != EOF)
    {
        printf("%lld\n", Solve(x, n));
    }
    return 0;
}