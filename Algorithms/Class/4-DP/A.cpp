#include<iostream>
#include<cstring>

using namespace std;

constexpr int N=120;
int d[N][N],dp[N];

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=i;++j){
				scanf("%d",d[i]+j);
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=i;j;--j){
				if( j == 1  )
					dp[j] += d[i][j];
				else if( j == i )
					dp[j] = dp[j-1] + d[i][j];
				else 
					dp[j] = max(dp[j] ,dp[j-1]) + d[i][j];
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			ans = max(ans,dp[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
