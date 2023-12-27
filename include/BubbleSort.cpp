#include<iostream>

using namespace std;

void BubbleSort(int a[],int n)
{
    int ret=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n-i;++j){
            if( a[j] > a[j+1] )
                swap(a[j],a[j+1]),++ret;
        }

    }
    cout<<ret<<'\n';
}

const int N=1e5+100;
int a[N];

int main(void)
{
    int n;
    while (cin>>n)
    {
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        BubbleSort(a,n);
    }
    
    return 0;
}