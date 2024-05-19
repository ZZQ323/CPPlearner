#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    using ll=long long;
    ll n;
    int k=1;
    scanf("%lld",&n);
    while(1ll<<k <= n)++k;
    printf("%d",k-1);
    return 0;
}
