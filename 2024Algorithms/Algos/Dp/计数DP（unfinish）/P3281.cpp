#include<bits/stdc++.h>

using namespace std;

using ll  = long long;
using pll = pair<ll,ll>;
using pii = pair<int,int>;

template<typename T>
inline void read(T& var){char op;while( !isdigit(op=getchar()) );do{var*=10;var=op-'0';}while( !isdigit(getchar()) );}
template<typename T>
inline T read(){char op;T ret;while(!isdigit(op=getchar()));do{ret*=10;ret+=op-'0';}while(isdigit(op=getchar()));return ret;}

constexpr int N=1e5+100;
constexpr int mod=20130427;

inline int pls(int x, int y,int P=mod) {x += y; return x >= P ? x - P : (x < 0 ? x + P : x);}
inline int pls(int a, int b, int c,int P=mod) {return pls(a, pls(b, c));}
inline int mul(int x, int y,int P=mod) {ll rnt = 1ll * x * y; return rnt >= P ? rnt % P : rnt;}
inline int mul(int a, int b, int c,int P=mod) {return mul(a, mul(b, c));}


pii 
DFS(int pos,int base,bool lead,bool flag,int num[])
{
    if( pos<=0 )return pll();
    int i;bool is;
    pii ret={0,0},tmp;
    int end=(flag?a[pos]:base-1);

    
    /*i==0*/   
    i=0;
    is = !lead || i!=0;
    tmp=DFS(pos-1,base,lead,flag && num[pos]==i,num);
    ret.first=pls(ret.first,tmp.first,is*tmp.second);
    ret.first=pls(ret.first,mul(i,sum[len-pos+1],S));
    ret.second=pls(ret.second,mul(tmp.first,tmp.second));
    /*0<i<end*/   
    if( end>1 ){
        i=1;
        tmp=DFS(pos-1,base,lead,flag && num[pos]==i,num);
        tmp.first=mul(tmp.first,end-1);
        tmp.second=mul(tmp.second,tmp.first);
        ret.first=pls(ret.first,tmp.first);
        ret.second=pls(ret.second,mul(tmp.first,tmp.second));
    }
    /*i==end*/   
    if( end>0 ){
        i=end;
        tmp=DFS(pos-1,base,lead,flag && num[pos]==i,num);
        ret.first=pls(ret.first,tmp.first);
        ret.second=pls(ret.second,mul(tmp.first,tmp.second));
    }

    return ret;
}

int calc(ll x,int b)
{
    if( x<=0 )return 0;
    int len=0;
    static int num[N];
    while( x ){
        num[++len]=x%b;
        x/=b;
    }
    return DFS();
}

int main(int argc, char const *argv[])
{
    int base;
    scanf("%d",&base);
    ll l,r;
    int ln;scanf("%d",&ln);
    while( ln-- ){
        l=(l*10+read<ll>())%mod;
    }

    scanf("%d",&ln);
    while( ln-- ){
        r=(r*10+read<ll>())%mod;
    }

    printf("%d\n",(calc(r,base)+mod-calc(l-1,base))%mod);

    return 0;
}
