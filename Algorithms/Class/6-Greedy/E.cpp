#include<iostream>
#include<algorithm>

using namespace std;

constexpr int N = 2e4+100;
int w[N];

int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=2*n;++i){
			scanf("%d",w+i);
		}
		sort(w+1,w+1+2*n);
		long long sum=0;
		for(int i=1;i<=2*n;i+=2){
			sum+=w[i];
		}
		printf("%lld\n",sum);
	}
	return 0;
}
