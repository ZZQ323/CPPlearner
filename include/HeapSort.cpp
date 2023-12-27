#include<iostream>

using namespace std;

const int N=1e5+100;

template<class T>
struct priority_queue{
    T d[N];
    size_t Size;
    
    void update(int id){
        for(int fa=id>>1;fa;fa>>=1){
            if( d[fa]<d[id] )swap(d[fa] , d[id]);
            else break;
        }
    }

    void push_down(int id){
        int fa=id;
        for(int now=id<<1;now<=Size;now<<=1)
        {
            if(now+1<=Size && d[now]<d[now+1])++now;
            if(d[id] <= d[now])break;
            swap(d[id],d[now]);
            id=now;
        }
    }

    int top(){return d[0];}

    void insert(int val){
        d[++Size]=val;
        update(Size);
    }

    void pop(){
        swap(d[1],d[Size]);
        push_down(1);
        --Size;
    }

    size_t size(){
        return Size;
    }

};


int a[N];
int n;

void HeapAdjust(int a[],int s,int e)
{
    for(int nex=s<<1;nex<=e;nex<<=1)
    {
        if(nex+1<=e && a[nex] > a[nex+1])++nex;
        if(a[s] <= a[nex])break;
        swap(a[s],a[nex]);
        s=nex;
    }
}

void HeapSort(int a[],int n)
{
    for(int i=n>>1;i;--i)
        HeapAdjust(a,i,n);
}


int main(void)
{
    while (cin>>n)
    {
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        HeapSort(a,n);
        cout<<n;
        for(int i=1;i<=n;++i){
            cout<<' '<<a[i];
        }
        cout<<'\n';
        for(int i=n;i>1;--i){
            swap(a[1],a[i]);
            HeapAdjust(a,1,i-1);

            cout<<n;
            for(int i=1;i<=n;++i){
                cout<<' '<<a[i];
            }
            cout<<'\n';
        }
    }
    
    return 0;   
}