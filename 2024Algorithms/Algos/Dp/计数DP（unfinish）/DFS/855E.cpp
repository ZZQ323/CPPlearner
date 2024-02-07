#include<bits/stdc++.h>

using namespace std;
using ll=long long;

/**
 * 
 * 啊啊啊啊啊10个64怎么开得出来啊啊啊啊
 * 其实只需要储存奇偶性就可以了。
 * 极力想办法压缩数据的表示形式，不保存本身，只保存性质
 * 
*/

// struct Count{
//     int cnter[10];
// };

// inline bool check(Count& var,int base)
// {
//     for(int i=0;i<base;++i){
//         if( !(var.cnter[i]&1) ){
//             return false;
//         }
//     }
//     return true;
// }
constexpr int N=70;
ll dp[N][12][2][2][2][2][2][2][2][2][2][2];

int pk[10];
ll DFS(int pos,bool lead,bool flag,const int b,int num[])
{
    if( pos<=0 )return !lead and !(pk[0]|pk[1]|pk[2]|pk[3]|pk[4]|pk[5]|pk[6]|pk[7]|pk[8]|pk[9]);
    if(!lead and !flag and ~dp[pos][b][pk[0]][pk[1]][pk[2]][pk[3]][pk[4]][pk[5]][pk[6]][pk[7]][pk[8]][pk[9]] )
        return dp[pos][b][pk[0]][pk[1]][pk[2]][pk[3]][pk[4]][pk[5]][pk[6]][pk[7]][pk[8]][pk[9]];
    ll ret=0;
    int end=(flag?num[pos]:b-1);
    for(int i=0;i<=end;++i){
        if( lead && i==0){
            //不存在数字的时候不需要反转bit
            ret+=DFS(pos-1,lead and !i,flag and (i==num[pos]),b,num);
        }else{
            pk[i]^=1;
            ret+=DFS(pos-1,lead and !i,flag and (i==num[pos]),b,num);
            pk[i]^=1;
        }
    }
    if(!lead and !flag){
        dp[pos][b][pk[0]][pk[1]][pk[2]][pk[3]][pk[4]][pk[5]][pk[6]][pk[7]][pk[8]][pk[9]]=ret;
    }
    return ret;
}

ll calc(ll x,int base)
{
    if( x<=0 )return 0;
    int num[N];
    int len=0;
    while( x ){
        num[++len]=x%base;
        x/=base;
    }
    memset(pk,0,sizeof(pk));
    return DFS(len,1,1,base,num);
}

int main(int argc, char const *argv[])
{
    int t;
    int b;ll l,r;
    memset(dp,0xff,sizeof(dp));
    for(scanf("%d",&t);t--;){
        scanf("%d%lld%lld",&b,&l,&r);
        printf("%lld\n",calc(r,b)-calc(l-1,b));
    }
    return 0;
}
