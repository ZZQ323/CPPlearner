#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

using ll=long long ;
using llu=long long unsigned;


const int N=17;
ll dp[N][N][2][2];

using ll = long long ;

/**
 * pos:数组num的位置
 * cnt：有多少个number数字
 * number：就是我需要一个个查询个数的数字
 * prezero：防止前导0，不满足条件不对cnt进行记录； 同时记录cnt的条件还有i==number
 * flag：防止越界，根据前面有和没有达到最大的数字来决定这次能不能达到9，还是num[pos]
 * 
 * 
 * 为什么prezero就可以防止前导0？如何处理前导0？
 *  prezero的作用在于区分现在这个数字的上一面连续的好几个数字是不是0，
 *  如果是，那么连续的好几个数字都是0的话，那么就是前导0，就不能计数cnt
 *  否则的话，前面已经有一个非0数字在帮你撑腰了，那就记录
 *  传入参数的时候，也请注意，不一定你前面是前导0，后面就一直不能记录了，你可以作第一个非0数字打破预期
 *  特别是number为0的时候，你细品。
*/
ll DFS(int pos,int cnt,bool prezero,bool flag,const int number,int num[])
{
    if( !pos )return cnt;
    if( ~dp[pos][cnt][prezero][flag] )//记忆化
        return dp[pos][cnt][prezero][flag];
    //返回number的个数cnt
    ll ret=0;
    int end=flag?num[pos]:9;
    for(int i=0;i<=end;++i){
    // 通过记录以i开头的数字有多少个满足条件的来数i有多少个
        ret+=DFS( 
            pos-1, 
            cnt + ( ( !prezero || i ) && i==number ), 
            prezero && !i,
            flag && (i==num[pos]),
            number,
            num
        );
    }
    return dp[pos][cnt][prezero][flag] = ret;//记忆化
}

void calc(ll x,int a[])
{
    int len=0;
    int num[N];
    while( x ){
        num[++len]=x%10;
        x/=10;
    }
    for(int i=0;i<10;++i){
        memset(dp,-1,sizeof(dp));
        a[i]=DFS(len,0,1,1,i,num);
    }
}

int a[10],b[10];

signed main(void)
{
    
    ll l,r;
    scanf("%lld%lld",&l,&r);
    calc(l-1,a);
    calc(r,b);
    for(int i=0;i<10;++i){
        printf("%lld ",b[i]-a[i]);
    }
    fflush(stdout);
    return 0;
}