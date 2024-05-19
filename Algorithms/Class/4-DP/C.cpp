#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

constexpr int N=400;
struct Retangle{
	int l,d,h;
	int idx;

	Retangle(int a=0,int b=0,int c=0,int id=0)
	:l(a),d(b),h(c),idx(id){;}

	bool operator<(const Retangle& x)const {
		if(l*d!=x.l*x.d)return l*d>x.l*x.d;
		if(l!=x.l)return l>x.l;
		if(d!=x.d)return d>x.d;
		if(h!=x.h)return h>x.h;
	}
}var[N];

inline bool TupleOver(int l1,int l2,int r1,int r2)
{return l1<r1 && l2<r2 ;}

inline bool CanPlaceOver(int a,int b)
{
	return TupleOver(var[a].l,var[a].d,var[b].l,var[b].d)|| 
			TupleOver(var[a].l,var[a].d,var[b].d,var[b].l) ;
}

int n;
bool vis[N];
int ans,dp[N];
vector<int> g[N];

int DP(int cur)
{
	if( ~dp[cur] )
		return dp[cur];
	int ret=0;
	for(int i=0; i < g[cur].size() ;++i){
		int j = g[cur][i];
		if( !vis[j] ){
			vis[j] = 1;
			ret = max( ret , DP(j) );
			vis[j] = 0;
		}
	}return dp[cur] = ret + var[cur].h;
}

int main(int argc, char const *argv[])
{
	while( ~scanf("%d",&n) ){
		ans=0;
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<N;++i) g[i].clear();		

		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&var[i*3-2].l,&var[i*3-2].d,&var[i*3-2].h);
			var[i*3-1] = {var[i*3-2].d,var[i*3-2].h,var[i*3-2].l};
			var[i*3] = {var[i*3-2].h,var[i*3-2].l,var[i*3-2].d};
			var[i*3-2].idx=var[i*3-1].idx=var[i*3].idx=i;
		}
		sort(var+1,var+1+n*3);
		for(int i=1;i<=3*n;++i){
			for(int j=1;j<=3*n;++j){
				if( CanPlaceOver(j,i) ){
					g[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=3*n;++i){
			ans = max( ans , DP(i) );
		}
		printf("%d\n",ans);
	}
	return 0;
}
