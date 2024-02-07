#include<iostream>

using namespace std;

constexpr int N=1100;
char s[N][N];
int n;

/***
 * 简单模拟
 * 
 * 如何旋转一个矩阵？用复数（注意不是向量）乘法可以一战。
 * 
*/

inline char& rotate(int i,int j,int mode)
{
    switch (mode)
    {
    case 1:
        return s[i][j];
    case 2:
        return s[j][n+1-i];
    case 3:
        return s[n+1-i][n+1-j];
    case 4:
        return s[n+1-j][i];
    }
}

inline void solve()
{
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(
                rotate(i,j,1)!=rotate(i,j,2) ||
                rotate(i,j,1)!=rotate(i,j,3) ||
                rotate(i,j,1)!=rotate(i,j,4) ||
                rotate(i,j,2)!=rotate(i,j,3) ||
                rotate(i,j,2)!=rotate(i,j,4) ||
                rotate(i,j,3)!=rotate(i,j,4)
            ){
                char op=max(max(max(rotate(i,j,1),rotate(i,j,2)),rotate(i,j,3)),rotate(i,j,4));
                ans+=op-rotate(i,j,1);
                ans+=op-rotate(i,j,2);
                ans+=op-rotate(i,j,3);
                ans+=op-rotate(i,j,4);
                rotate(i,j,1)=rotate(i,j,2)=rotate(i,j,3)=rotate(i,j,4)=op;
            }
        }
    }
    printf("%d\n",ans); 
}

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%s",s[i]+1);
        }
        solve();
    }
    return 0;
}
