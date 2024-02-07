#include<bits/stdc++.h>

using namespace std;

/** 遇到平均数的时候：关注奇偶数性
 * 
 * 观察到每次ai+aj除以二再乘以二得到的整数是偶数
 * 因为操作之后产生的一定是偶数，所以不存在选不到偶数的情况，关注奇数即可
 * ai+aj得到的如果是奇数，那么得到的数值就会比二者的和少1
 * 奇+奇、偶+偶不会少；奇+偶会少1
 * 那么先手一定是有大于两个奇数，就选奇；否则选偶数
 * 后手那个人就一直选奇+偶数，否则就是偶数+偶数
 * 
*/

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int odd=0;
        long long sum=0;
        int temp;
        for(int i=1;i<=n;++i){
            scanf("%d",&temp);
            if( temp&1 )++odd;
            sum+=temp;
            if( i==1 ) printf("%lld ",sum);
            else printf("%lld ",sum-odd/3-(odd%3==1));
        }
        putchar('\n');
    }
    
        return 0;
}