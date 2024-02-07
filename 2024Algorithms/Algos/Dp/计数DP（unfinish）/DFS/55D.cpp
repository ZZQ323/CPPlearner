#include<bits/stdc++.h>

using namespace std;

using ll= long long ;
#define lld I64d

/**
 * 只要是判断数字有多少个的，都是这个模板，别慌。
 * 
 * 一个数字整除xx，想到什么？
 * lcm
 * 
 * number太大了存不下，也无法离散化怎么办？
 * 取mod行不行？反正最终都需要取mod。取mod不影响且有压缩性。
*/

constexpr int N=20;
constexpr int Mod=2520;//2520 <- LCM(1,2....9)
ll dp[N][Mod+30][50];

int tables[]={ 
    1,2,3,4,5,6,7,8,9,10,12,14,15,18,20,21,24,28,30,35,36,40,42,
    45,56,60,63,70,72,84,90,105,120,126,140,168,180,210,252,280,315,360,420,504,
    630,840,1260,2520,
};

inline ll GCD(ll a,ll b){return !b?a:GCD(b,a%b);}
inline ll LCM(ll a,ll b){return a/GCD(a,b)*b;}

inline int id(int num,int a[]=tables,int l=0,int r=47){
    return lower_bound(a+l,a+r+1,num)-a;
}

ll DFS(int pos,int lcm,int mod,bool prezero,bool flag,int num[])
{
    if( pos<=0 )return !prezero and (mod%lcm==0);
    if( !prezero && !flag && ~dp[pos][mod][id(lcm)] )
        return dp[pos][mod][id(lcm)] ;
    ll ret=0;
    int end=(flag?num[pos]:9);
    for(int i=0;i<=end;++i){
        ret+=DFS(pos-1, !i?lcm:LCM(lcm,i) , (10*mod%Mod+i)%Mod , prezero and !i,flag and (i==num[pos]),num);
    }
    if( !prezero && !flag )
        dp[pos][mod][id(lcm)]=ret;
    return ret;
}

ll calc(ll x)
{
    int num[N];
    int len=0;
    while( x ){
        num[++len]=x%10;
        x/=10;
    }
    return DFS(len,1,0,1,1,num);
}

void dfs(int lcm,int pre,set<int>& ans){
    ans.insert(lcm);
    for(int i=pre+1;i<=9;++i){
        dfs(LCM(lcm,i),i,ans);
    }
};

int main(int argc, char const *argv[])
{
    // printf( "%lld\n",LCM(1,LCM(2,LCM(3,LCM(4,LCM(5,LCM(6,LCM(7,LCM(8,LCM(9,10))))))))) );
    // set<int>se;
    // dfs(1,1,se);
    // for(auto it:se){
    //     printf("%d\n",it);
    // }
    // puts("****************");
    
    int t;
    scanf("%d",&t);
    memset(dp,0xff,sizeof(dp));
    ll l,r;
    while( t-- ){
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",calc(r)-calc(l-1));
    }
    return 0;
}
