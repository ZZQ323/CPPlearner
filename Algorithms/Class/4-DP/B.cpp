#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int n;
constexpr int N=1e5+100;
int a[N],dp[N];

int main(int argc, char const *argv[])
{
	while (~scanf("%d",&n))
	{
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
		}
		for(int i=1;i<=n;++i){
			dp[i] = max(dp[i-1]+a[i],a[i]);
		}
		int ans=INT_MIN;
		for(int i=1;i<=n;++i){
			ans = max( ans, dp[i]);
		}printf("%d\n",ans);
	}
	
	return 0;
}
