#include<iostream>
#include<cstring>
#include <cctype>

using namespace std;

using pii=pair<int ,int >;
using ll=long long ;
constexpr int mod=20130427;
constexpr int N=1e5+10;
inline int pls(int a,int b){return (a%mod+b%mod)%mod;}
inline int pls(int a,int b,int c){return pls(pls(a,b),c);}
inline int minu(int a,int b){return pls(a+mod,-b);}
inline int minu(int a,int b,int c){return minu(minu(a,-b),c);}
inline int mul(int a,int b){return (1ll*a%mod*b%mod)%mod;}
inline int mul(int a,int b,int c){return mul(mul(a,b),c);}

int S[N]={1,},powB[N]={1,};

inline int read()
{
	bool f=0;char op;int ret=0;
	do op=getchar(); while(op!='-' && !isdigit(op));
	if(op=='-')f=1;
	do ret*=10,ret+=op-'0',op=getchar(); while( isdigit(op) );
	if(f)ret=-ret;
	return ret;
}

inline void read(int& x)
{
	bool f=0;char op;x=0;
	do op=getchar(); while(op!='-' && !isdigit(op));
	if(op=='-')f=1;
	do x*=10,x+=op-'0',op=getchar(); while( isdigit(op) );
	if(f)x=-x;
}

inline void read(int x[],int n)
{for(int i=n;i;--i)read(x[i]);}

inline int check(int a[], int n, int ret = 0) 
{
	for(register int i = 1; i <= n; i++)
		ret = pls(ret, mul(i, a[i], S[i]));
	return ret;
}

pii dp[N];
int suf[N],len;
//first存的是 ，second存的是
pii DFS(int pos,bool lead,bool flag,const int B,int num[])
{
	if(!pos)return {0,0};
	if( !lead and !flag and ~dp[pos].first ){
		return dp[pos];
	}
	pii ret={0,0},tmp;
	int end=(flag?num[pos]:B-1);
	
	int k,cnt,l,r;
	bool nzero;

	/*-------------------- k = 0 -----------------------*/
	k = 0;
	nzero = !lead || k != 0;
	//指这个位置上数字贡献了的个数
	cnt = (flag and (k == num[pos])) ? (suf[pos - 1] + 1) : powB[pos];
	tmp = DFS(pos -1  , lead and (k == 0) , flag and (k == end),B,num);
	ret.first = pls(ret.first, tmp.first, nzero * tmp.second);
	ret.first = pls(ret.first, mul(k, S[pos], cnt));
	ret.second = pls(ret.second, tmp.second, mul(k, S[pos], cnt));
	/*-------------------- k > 0 && k < end -----------------------*/
	if(end>1){
		k=1;
		nzero = !lead || k != 0;
		cnt = (flag and (k == num[pos])) ? (suf[pos - 1] + 1) : powB[pos];
		tmp = DFS(pos -1  , lead and (k == 0) , flag and (k == end),B,num);
		r=end-1;l=1; ll Len=(r-l+1); 
		ret.first = pls(ret.first, mul(pls(tmp.first, nzero * tmp.second),Len));
		ret.second = pls(ret.second, mul(tmp.second,Len));
		Len=(l+r)*Len/2;Len%=mod;
		Len=mul(Len,cnt,S[pos]);
		ret.first=pls(ret.first,Len);
		ret.second=pls(ret.second,Len);
	}
	/*-------------------- k = end -----------------------*/
	if(end>0){
		k = end;
		nzero = !lead || k != 0;
		cnt = (flag and (k == num[pos])) ? (suf[pos - 1] + 1) : powB[pos];
		tmp = DFS(pos -1  , lead and (k == 0) , flag and (k == end),B,num);
		ret.first = pls(ret.first, tmp.first, nzero * tmp.second);
		ret.first = pls(ret.first, mul(k, S[pos], cnt));
		ret.second = pls(ret.second, tmp.second, mul(k, S[pos], cnt));
	}
	if( !lead and !flag){
		dp[pos]=ret;
	}return ret;
}

pii calc(int a[],int n,int B=10)
{
	memset(dp,-1,sizeof(dp));
	memset(suf,0,sizeof(suf));
	len=n;
	for(register int i=1;i<n;++i){
		suf[i]=pls(suf[i-1],mul(powB[i-1],a[i]));
	}
	return DFS(n-1,1,1,B,a);
}

int l[N],r[N],B;

int main()
{
	int n,m;
	read(B);read(n);read(l,n);read(m);read(r,m);
	for(register int i=1;i<N;++i){
		powB[i]=mul(powB[i-1],B);
		S[i]=pls(S[i-1],powB[i-1]);
	}
	printf("%d\n",pls(calc(r, m).first, check(l, n) - calc(l, n).first) );
	return 0;
}