#include<iostream>
#include<algorithm>
#include<cstring>
#include<utility>

using namespace std;

using pii=pair<int ,int>;
constexpr int N =120;
pii a[N];

inline bool cmp(const pii& a,const pii&b){ return a.second < b.second; }

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--){
		// 最大延迟
		int ans=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d%d",&a[i].first,&a[i].second);
		}
		sort(a+1,a+1+n,cmp);
		int f=0;
		for(int i=1;i<=n;++i){
			f += a[i].first;
			ans = max(ans ,f-a[i].second );
		}
		printf("%d\n",ans);
	}
	return 0;
}
