#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
#include<cmath>

using namespace std;

#define ll long long

int n,m;
const int N=1e6+100;
int flag,pos,sum;
int lg[N],a[N];

void SA()
{
    for(int i=1;i<=10000;++i)
    {
        int l=rand()%m+1,r=m+rand()%(n-m)+1;
        sum^=a[l];
        sum^=a[r];
        swap(a[l],a[r]);
        if(sum==pos){
            flag=true;
            return void();
        }
    }
}

int main(int argc,char**argv)
{
    srand(time(nullptr));

    //计算1<<(int)log2(i)-1
    for(int i=1;i<=N;++i)
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);

    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);

        for(int i=1;i<=n;++i) a[i]=i;
        sum=0;
        for(int i=1;i<=m;++i) sum^=i;
        pos=(1<<lg[n])-1;

        if(n==m){
            if(sum==pos){
                for(int i=1;i<=n;++i){
                    printf("%d ",a[i]);
                }putchar('\n');
            }else printf("-1\n");
        }else {
            flag=false;
            for(int i=1;i<=90;++i){
                SA();
                if(flag){
                    for(int j=1;j<=m;++j)
                        printf("%d ",a[j]);
                    putchar('\n');
                    break;
                }
            }
            if( !flag )
                puts("-1");

        }
    }
    return 0;
}