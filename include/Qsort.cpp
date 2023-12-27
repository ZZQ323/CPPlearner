#include<iostream>

using namespace std;

const int N=1e5+100;
int a[N],n;

void output()
{
    for(int i=1;i<=n;++i){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

namespace first{
    void qsort(int a[],int l,int r)
    {
        int len=r-l+1;
        if(len<=1)return ;
        // int flag=a[l+r>>1];
        int flag=a[l];
        int ql=l,qr=r;
        while( ql<=qr ){
            while( a[ql]<flag  )++ql;
            while( a[qr]>flag  )--qr;
            if( ql<=qr){
                swap(a[ql++],a[qr--]);
            }
        }
        output();
        qsort(a,l,qr);
        qsort(a,ql,r);
    }   
}

namespace second{
    void qsort(int a[],int l,int r)
    {
        if( r-l+1 <=1)return ;
        int ql=l,qr=r;
        int flag=a[l];
        while( ql<qr )
        {
            // 大的qr先动，因为这个地方是空的，被保存在了flag里面
            while(ql<qr && a[qr]>=flag)--qr;
            a[ql]=a[qr];
            while(ql<qr && a[ql]<=flag)++ql;
            a[qr]=a[ql];
        }
        a[ql]=flag;
        output();
        qsort(a,l,ql-1);
        qsort(a,ql+1,r);
    }
}

using second::qsort;


int main(void)
{
    srand(time(0));
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        qsort(a,1,n);
        cout<<'\n';
    }

    return 0;
}