#include<iostream>
#include<algorithm>
#include<cstring>
#include<utility>

using namespace std;

constexpr int N = 1e4+100;
// int s[N],t[N];
using pii = pair<int,int >;
pii t[N];

inline bool cmp(const pii& a,const pii&b){ return a.second < b.second; }

int main(int argc, char const *argv[])
{
	int n;
	while( scanf("%d",&n) != EOF ){
		int ans=1;
		for(int i=1;i<=n;++i){
			scanf("%d%d",&t[i].first,&t[i].second);
		}
		sort(t+1,t+1+n,cmp);
		int f=t[1].second;
		for(int i=2;i<=n;++i){
			if( t[i].first >= f ){
				f = max(f,t[i].second);
				++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
