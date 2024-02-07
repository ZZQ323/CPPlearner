#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

using pii=pair<int ,int >;

/** 选三个最大的数之和
 * 找到最大值、次大值、次次大值
 * 最坏的情况，a选了最大值，b、c都重合，且bc第二个还重合，那么c或b就选第三个
 * 写5个纯粹是瞎操心，三个足以
 * 
*/

constexpr int N=1e5+100;
int a[N],b[N],c[N];

void getMaxthree(int n,int a[],pii ma[])
{
    for(int i=1;i<=n;++i){
        if( a[i]>ma[0].second ){
            ma[4]=ma[3];
            ma[3]=ma[2];
            ma[2]=ma[1];
            ma[1]=ma[0];
            ma[0]=pii(i,a[i]);
        }else if( a[i]>ma[1].second ){
            ma[4]=ma[3];
            ma[3]=ma[2];
            ma[2]=ma[1];
            ma[1]=pii(i,a[i]);
        }else if( a[i]>ma[2].second ){
            ma[4]=ma[3];
            ma[3]=ma[2];
            ma[2]=pii(i,a[i]);
        }else if( a[i]>ma[3].second ){
            ma[4]=ma[3];
            ma[3]=pii(i,a[i]);
        }else if( a[i]>ma[4].second ){
            ma[4]=pii(i,a[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--){
        pii ma[5];
        pii mb[5];
        pii mc[5];// id , val

        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",a+i);
        getMaxthree(n,a,ma);
        for(int i=1;i<=n;++i)
            scanf("%d",b+i);
        getMaxthree(n,b,mb);
        for(int i=1;i<=n;++i)
            scanf("%d",c+i);
        getMaxthree(n,c,mc);
        int ans=0;
        for(int i=0;i<5;++i)
        for(int j=0;j<5;++j)
        for(int k=0;k<5;++k){
            if( 
                ma[i].first!=mb[j].first 
                && mb[j].first!=mc[k].first 
                && mc[k].first!=ma[i].first 
            ){
                ans=max(ans,ma[i].second+mb[j].second+mc[k].second);
                break;
            }
        }
        printf("%d\n",ans); 
    }
    return 0;
}
