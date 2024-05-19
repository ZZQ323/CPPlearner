#include<iostream>
#include<cstring>

using namespace std;

constexpr int N=1100;
int M[N][N],a[N];

/** 二进制序列
 * 萃取思维：用已有的东西进行运算来提取分解出来的东西
 * 
 * 构造一个序列，满足矩阵限制 M[i][j]==a[i]|a[j]
 * 注意C++的>>是算数右移
 * 
 * M[i][j]是由a[i]、a[j]提供的，那么a[i]、a[j]公有和私有的部分全部在里面；
 * 用31个1分别和M[i][1]、M[i][2]……M[i][n]，取&就可以取出a[i]的贡献部分
 * 因为a[i]有的M[i][……]一定有，但是反之不真
 * 
*/

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            a[i]=(1<<30)-1;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                scanf("%d",M[i]+j);
                if( i!=j ){
                    a[i]&=M[i][j];
                    a[j]&=M[i][j];
                }
            }
        }
        if( n==1 ){
            printf("Yes\n%d\n",M[1][1]);
            continue;
        }
        bool flag=0;
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                if( M[i][j] != (a[i]|a[j]) ){
                    puts("NO");
                    flag=1;
                    break;
                }
            }
            if( flag )break; 
        }
        if( flag )continue;
        puts("YES");
        for(int i=1;i<=n;++i){
            printf("%d ",a[i]);
        }
        putchar('\n');
    }
    return 0;
}
