#include<bits/stdc++.h>

using namespace std;

constexpr int N=2500;
char a[N],b[N];
int dp[N][N];

int main(int argc, char const *argv[])
{
    while( ~scanf("%s%s",a+1,b+1)){
        memset(dp,0,sizeof(dp));
        int lena=strlen(a+1);
        int lenb=strlen(b+1);

        // 边界的意义也必须要关注
        for(int i=1;i<=lena;i++)
            dp[i][0]=i;
        for(int i=1;i<=lenb;i++)
            dp[0][i]=i;
        
        for(int i=1;i<=lena;++i){
            for(int j=1;j<=lenb;++j){
                if( a[i]==b[j] )
                    dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                }
            }
        }
        printf("%d\n",dp[lena][lenb]);
    }
    return 0;
}
