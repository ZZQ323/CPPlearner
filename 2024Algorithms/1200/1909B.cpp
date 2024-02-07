#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

/** 简单数论（奇数和偶数）
 * 
 * 看见mod的时候，想到进制，优先考虑二进制
 * 
 * 首先，注意，一定要注意，k是任意可行的
 * 那么先尝试寻找特殊k
 * 
 * 在枚举注意到：居然有的输出了2，马上考虑到奇数和偶数两大类
 * 除非是全奇数和全偶数，mod2一定会有不同结果那么如果全奇、全偶呢？
 * 如何找到一个mod 2 全部相同，而mod k 就又分成两类的数字呢？
 * 
 * 尝试证明：
 * 假设我找到了一个k可以区分……无法证明；
 * 假设我找到了一个k，使得所有ai mod完之后是1；
 * x mod k ,f(k)=1的话， （ 因为我们已知一个2了嘛 ）
 * x mod 2k=0 或 k ，这个时候 f(k)就是2了
 * 
 * 相当于从2出发找其他的解答，默认通解解和特殊解之间存在关系的思路
 * 
 * 转换成二进制去看： 
 *   https://codeforces.com/predownloaded/04/d4/04d40ed602b2fa79759cb44fa5c66a3c954fa123.png
 * 
 * 结论： 对于所有的 ai，一定存在一个数 2b,b∈Z，使得 ai mod 2^b 有且仅有两个不同的值(一定可以分成两类)
*/

constexpr int N=1100;
using ll=long long ;
ll a[N];
int n;

//想要枚举的恐怖想法
bool splice(const ll d,ll lpre,ll rpre,int index,ll a[])
{   
    if( index > n )return true;
    if( (a[index]-lpre) % d == 0  )return splice(d,a[index],rpre,index+1,a);
    else if(rpre==0 || (a[index]-rpre) % d == 0 ) return splice(d,lpre,a[index],index+1,a);
    return false;
}

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        bool odd=0;
        bool even=0;
        ll minn=LLONG_MAX;
        for(register int i=1;i<=n;++i){
            scanf("%lld",a+i);
            if( a[i] & 1)odd|=1;
            else even|=1;
            minn=min(minn,a[i]);
        }
        if( odd==0 || even==0  ){
            ll k=1;
            set<ll>s;
            while( 1 ){
                s.clear();
                k<<=1;
                for(register int  i=1;i<=n;++i){
                    s.insert(a[i]%k);
                }
                if( s.size()==2 ){
                    printf("%lld\n",k);
                    break;
                } 
            }
        }else printf("2\n");
    }
    return 0;
}
