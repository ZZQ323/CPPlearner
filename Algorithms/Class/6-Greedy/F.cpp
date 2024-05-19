#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

constexpr int N = 1e4+100;
int dp[N],a[N],high[N];

// LIS 问题

int main(int argc, char const *argv[])
{
	int n;
	while (scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
		}
		int len = 1;
		high[1] = a[1];
		for(int i=2;i<=n;++i){
			if( a[i] > high[len] ){
				high[++len]=a[i];
			}else{
				int idx = lower_bound(high+1,high+1+len,a[i]) - high;
				high[idx] = a[i];
			}
		}printf("%d\n",len);
	}
	return 0;
}
