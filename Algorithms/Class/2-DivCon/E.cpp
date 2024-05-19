#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 5e7 + 10;
const int mod = 1e9 + 7;
int a[maxn],n,m,k;

void print(int l,int r){
    for(int i=l;i<=r;++i){
        printf(" %d"+(i==l),a[i]);
    }putchar('\n');
}

int qsort(int l, int r,int cnt)
{
    if( l>=r ){
        return a[l];
    }
    int mid=l+r>>1;
    int flag=a[mid];
    int i=l-1,j=r+1;
    while( i < j ){
        do ++i; while(a[i]<flag);
        do --j; while(a[j]>flag);
        if( i<j ){
            swap(a[i],a[j]);
        }
    }
    if(cnt <= j-l+1)
        return qsort(l,j,cnt);
    else
        return qsort(j+1,r,cnt-(j-l+1));
}


int main(int argc, char const *argv[])
{
    while( ~scanf("%d%d%d",&n,&m,&k) ){
        a[1] = m;
        for(int i = 2; i <= n; i ++)
            a[i] = 1LL * a[i - 1] * m % mod;
        printf("%d\n",qsort(1,n,k));
        // print(1,n);
    }
    return 0;
}
