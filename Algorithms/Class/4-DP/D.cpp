#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>
#include<climits>

using namespace std;
using ll = long long ;
using pii = pair<int,int>;
using vi = vector<int>;

constexpr int N=600;

ll dp[N][N];
int n,p[N];


int main(int argc, char const *argv[])
{
	while( ~scanf("%d",&n) ){
		memset(dp, 0 , sizeof(dp));

		for(int i=0 ; i<=n; ++i){
			scanf("%d",p+i);
		}

		for(int len=2 ; len<=n ; ++len){
			for(int l=1 ; l+len-1<=n ; ++l){
				int r=l+len-1;
				dp[l][r] = INT_MAX;
				for(int k=l+1 ; k<=r ; ++k){
					dp[l][r] = min( dp[l][r] , dp[l][k-1] + dp[k][r] + p[l-1]*p[k-1]*p[r] );
				}
			}
		}
		printf("%lld\n",dp[1][n]);
	}
	return 0;
}
