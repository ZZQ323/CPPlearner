#include<iostream>
#include<algorithm>

using namespace std;

constexpr int N=1e5+100;
int l[N],r[N],c[N];

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d",l+i);
        }
        for(int i=1;i<=n;++i){
            scanf("%d",r+i);
        }
        for(int i=1;i<=n;++i){
            scanf("%d",c+i);
        }
        sort(l+1,l+1+n);
        sort(r+1,r+1+n);
        sort(c+1,c+1+n,greater<int>() );
        long long sum=0;
        for(int i=1;i<=n;++i){
            sum+=1ll*(r[i]-l[i])*c[i];
        }
        printf("%lld\n",sum);
    }
    return 0;
}
