#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

constexpr int N = 1e4+100;
int w[N];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i){
			scanf("%d",w+i);
		}
		sort(w+1,w+1+m);
		int tot=0,ans=0;
		for(int i=1;i<=m;++i){
			if( tot+w[i] <=n ){
				++ans;
				tot+=w[i];
			}else break;
		}
		printf("%d\n",ans);
	}
	return 0;
}