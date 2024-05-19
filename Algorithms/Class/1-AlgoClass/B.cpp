#include<iostream>

using namespace std;

using ll=long long ;
const int N=2e5+100;
int A[N],cnt[210];

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	ll sum=0;
	for(int i=1;i<=n;++i){
		scanf("%d",A+i);
		A[i]%=200;
		++cnt[A[i]];
	}
	for(int i=0;i<200;++i){
		sum+=1ll*cnt[i]*(cnt[i]-1)/2;
	}
	printf("%lld",sum);
	return 0;
}
