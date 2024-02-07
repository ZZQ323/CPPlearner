#include<bits/stdc++.h>

using namespace std;

constexpr int N=3e5+100;
constexpr int M=1100;
int dp[2][M];


/**
 * 一开始写的是dp[N][M]，感觉没有任何问题
 * 但是标准答案是dp[N][M][2]，
 * 因为同一个状态下既然决定了在休息那就不可能前一秒在运动
 * 但如果不区分开来，这里面就会有前一秒闪现、运动、休息的到来
 * dp的状态设计不是很行啊
 * dp[2][M][2] 由于N过大，改成了滚动数组，0和1之间相互跳动
 * 
 * dp[][]也没问题。。。。。
 * 
 * 
*/

#define bin(x) (x)%2

int main(int argc, char const *argv[])
{
    int m,s,t;
    scanf("%d%d%d",&m,&s,&t);
    int maxn=0;
    int get_time=0;


    memset(dp,-0x3f,sizeof(dp)); //筛选合法状态
    dp[0][m]=0;

    for(int i=1;i<=t;++i){
        for(int j=0;j<=m+10;++j){
            dp[bin(i)][j]=max(dp[bin(i-1)][j]+17,dp[bin(i-1)][j+10]+60);
            if(j>=4){
                dp[bin(i)][j]=max(dp[bin(i)][j],dp[bin(i-1)][j-4]);
            }
            maxn=max(maxn,dp[bin(i)][j]);
            if(!get_time &&  maxn>=s ){
                get_time=i;
            }
        }
    }

    for(int i=0;i<=1;++i){
        for(int j=0;j<=m+12;++j){
            printf("%-11d ",dp[i][j]);
        }putchar('\n');
    }
    
    if( get_time ){
        puts("Yes");
        printf("%d\n",get_time);
    }else{
        puts("No");
        printf("%d\n",maxn);
    }

    return 0;
}
