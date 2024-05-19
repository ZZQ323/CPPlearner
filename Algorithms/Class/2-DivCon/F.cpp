#include<iostream>
#include<algorithm>

using namespace std;

constexpr int N=1e4+100;
int a[N],tmp[N];

void solve(int l,int r)
{
    if(l+1>=r)return ;
    int mid=l+r>>1;
    int len=r-l+1;
    for(int i=1,k=1;i<=len;++k,i+=2){
        tmp[k]=a[i-1+l];
        if( i < len )
            tmp[(len+1)/2+k]=a[i+l];
    }
    copy(tmp+1,tmp+len+1,a+l);
    solve(l,mid);
    solve(mid+1,r);
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
    }
    solve(1,n);
    for(int i=1;i<=n;++i){
        printf(" %d"+(i==1),a[i]);
    }
    return 0;
}
