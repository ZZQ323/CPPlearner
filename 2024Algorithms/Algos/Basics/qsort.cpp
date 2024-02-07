#include<bits/stdc++.h>

using namespace std;

constexpr int N=1e5+100;
int a[N];

void qsort(int l,int r,int a[])
{
    if( r-l+1<=1 )return ;
    int ql=l,qr=r;
    int flag=a[l+r>>1];
    while( ql<=qr ){
        while(ql<=r && a[ql]<flag)++ql;
        while(qr>=l && a[qr]>flag)--qr;
        if( ql<=qr ){
            swap(a[ql--],a[qr++]);
        }
    }
    qsort(l,qr,a);
    qsort(ql,r,a);
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    qsort(1,n,a);
    for(int i=1;i<=n;++i)
        printf("%d",a[i]);
    
    return 0;
}
