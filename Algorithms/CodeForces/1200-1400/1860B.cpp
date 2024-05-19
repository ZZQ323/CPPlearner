#include<iostream>
#include<algorithm>

using namespace std;

using ll = long long ;

/** 
 * 逻辑上，先用k再用1去配置总体上消耗的金币肯定是最少的。
 * 由此，优先用k，也优先缺k。
 * 如果k不够但是1还有剩余，那就补过去
 * 如果都不够那么就躺平；
 * 如果k剩余而1不足是没有办法补救的，因为补的东西肯定是小于k的，一补就超了，只能欠着。
 * 
 * 三分做法：
 *  如果把x作为能够满足总金额m的k的个数，f(x)代表用了多少个fancy金币
 *  固定下来所需要的全部x，就是去求f(x)的最小值。
 *  对于同一个金额f(x+1)意味着用一个k换了k个1
 *  f(x)是单调不减的，f(x+1)-f(x)是单调不减的
 *  这意味着可以进行三分搜索。
*/

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--){
        ll m,k,a1,ak;
        scanf("%lld%lld%lld%lld",&m,&k,&a1,&ak);

        int taken_k=m/k;
        int taken_1=m%k;
        int taken_fancy_1=max(0ll,taken_1-a1);
        int left_regular_1=max(0ll,a1-taken_1);
        int taken_fancy_k=max(0ll,taken_k-ak);
        int to_replace=min(left_regular_1/k,1ll*taken_fancy_k);
        int ans=taken_fancy_1+taken_fancy_k-to_replace;
        printf("%d\n",ans);
    }
    return 0;
}
