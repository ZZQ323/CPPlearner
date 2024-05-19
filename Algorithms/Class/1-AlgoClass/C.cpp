#include<iostream>
#include<algorithm>
#include<set>
#include<climits>

using namespace std;

constexpr int N=110;
int A[N],B[N];
using pii=pair<int ,int>;

int main(int argc, char const *argv[])
{
    int n;
    int l=0,r=INT_MAX;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",A+i);
        l=max(A[i],l);
    }
    for(int i=1;i<=n;++i){
        scanf("%d",B+i);
        r=min(B[i],r);
    }
    int ans=r-l+1;
    printf("%d",ans>0?ans:0);
    return 0;
}
