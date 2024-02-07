# LIS板子

**hdu1257**
  
```cpp
#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e5+100;
int a[N],dp[N];

int main(int argc, char const *argv[])
{
    int n;  
    while(~scanf("%d",&n)){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;++i)
            scanf("%d",a+i);
        dp[1]=1;//注意初始化
        for(int i=2;i<=n;++i){
            int x=0;//是有可能选不上的
            for(int j=1;j<i;++j){
                if( a[j]<a[i] && dp[j]>dp[x]){
                    x=j;
                }//从过去比他矮的地方选dp转移的前面一位
            }
            dp[i]=max(dp[i],dp[x]+1);
        }
        int maxn=0;//答案不一定在最后
        for(int i=1;i<=n;++i){
            maxn=max(maxn,dp[i]);
        }
        printf("%d\n",maxn);
    }
    return 0;
}
```



