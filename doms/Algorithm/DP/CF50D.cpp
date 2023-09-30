#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define ll long long 


/*
dp[i][j][k]  长度、开头数字、整除掉什么

gpt说只需要考虑不同长度的数字剩下部分能整除什么就能知道后面的情况，
事实上并不是这样的，整个数能整除某个数和部分能整除某个数没有关系。

dp[i][j]  长度、整除掉什么
整除的数字其实本身问题在于只整除身体上的数字；
dp[i][j]=\sum dp[i][k] (j%k==0)


一个数能被它的所有非零数位整除，则能被它们的最小公倍数整除（前缀和思想）
如果这个数能够整除它的每个数位上的数字，那么它一定能够整除他们的最小公倍数，是充要的。

定义状态dp[i][j][k]
i是长度，代表i位数字
第j个最小公倍数，离散化的结果
k是每个数位上的数字之积mod2520
dp--方案数。
*/ 

ll gcd(ll a,ll b)
{
	if(!b)return a;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
	//防止溢出
}

// 记忆化
ll dp[21][60][2520];

// Hash一下，所有
int Hash[2530];

void init()
{
	memset(dp,-1,sizeof(dp));
	int cc=0;
	for(int i=1;i<=8;i*=2)
		for(int j=1;j<=9;j*=3)
			for(int k=1;k<=5;k*=5)
				for(int l=1;l<=7;l*=7)
					Hash[i*j*k*l]=++cc;
	;
}


int num[21];
// 全世界都这么写数位DP......
// 第几个位置，是否顶格，剩下的根据需要设置参数去转移
ll DFS(int pos,int presum,int prelcm,bool flag)
{
	if(pos <= 0)
		return (presum%prelcm==0);

	int cd=Hash[prelcm];

	if(!flag && ~dp[pos][ cd ][presum])
		return dp[pos][ cd ][presum];

	int maxn=(flag?num[pos]:9);
	ll ans=0;
	for(int i=0;i<=maxn;++i)
	{
		int p=(presum*10+i)%2520;
		ans+=DFS(pos-1, p , i==0?prelcm:lcm(prelcm,i),i==num[pos] && flag );
	}
	
	// if(!flag && ~dp[pos][ cd ][presum]) 这里不能这么写，这样无法记忆化
	if(!flag)
		dp[pos][cd][presum]=ans;	

	return ans;
}


// 计算0-x之间有多少满足条件的数字？
ll calc(ll x)
{
	// 倒序
	int len=0;
	while(x)
	{
		num[++len]=x%10;
		x/=10;
	} 

	return DFS(len,0,1,true);
}

ll l,r;

int main(void)
{
	init();
	int t;
	cin>>t;
	while(t--)
	{
		// scanf("%lld%lld",&l,&r);
		cin>>l>>r;
		cout<<calc(r)-calc(l-1)<<'\n';
	}

	return 0;
}