#include<iostream>
#include<cstring>

using namespace std;

constexpr int mod=998244353;
using pii=pair<int ,int >;
using ll=long long ;

inline int pls(int a,int b){return (a%mod+b%mod)%mod;}
inline int pls(int a,int b,int c){return pls(pls(a,b),c);}
inline int minu(int a,int b){return pls(a+mod,-b);}
inline int minu(int a,int b,int c){return minu(minu(a,b),c);}
inline int mul(int a,int b){return (1ll*a%mod*b%mod)%mod;}
inline int mul(int a,int b,int c){return mul(mul(a,b),c);}

ll l,r;
int k,ten[30]={1,};
pii dp[11][30][1200];

inline pii check(int state)
{
	int cnt=0;
	for(int i=0;i<10;++i){
		if( state&(1<<i) ){
			++cnt;
			if(cnt > k)
				return {0,0};
		}
	}
	return {1,0};
}

pii DFS(int pos,int state,bool lead,bool flag,const int B,int num[])
{
	if(!pos){return check(state);}
	if( !check(state).first )return {0,0};
	if( ~dp[k][pos][state].first  and  !lead  and  !flag )
		return dp[k][pos][state];
	pii ret={0,0},tmp;
	int end=(flag?num[pos]:B-1);
	for(int i=0;i<=end;++i){
		if( lead  and  !i) tmp=DFS(pos-1,state ,lead and !i,flag and (i==num[pos]),B,num);
		else tmp=DFS(pos-1,state|(1<<i),lead and !i,flag and (i==num[pos]),B,num);
		ret.first=pls(ret.first,tmp.first);
		ret.second=pls(ret.second,tmp.second,mul(i,ten[pos-1],tmp.first));
	}
	if( !lead and !flag )
		dp[k][pos][state]=ret;
	return ret;
}

int num[30];
int calc(ll x,int B=10)
{
	if( !x )return 0;
	int len=0;
	while(x){
		num[++len]=x%B;
		x/=B;
	}return DFS(len,0,1,1,B,num).second;
}

int main()
{
	// printf("%d",mod<<1);
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<30;++i)
		ten[i]=mul(ten[i-1],10);
	while( ~scanf("%lld%lld%d",&l,&r,&k) ){
		printf("%d\n",minu(calc(r),calc(l-1)));
	}
	return 0;
}