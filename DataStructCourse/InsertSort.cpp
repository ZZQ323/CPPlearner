#include<iostream>

using namespace std;

void InserSort(int a[],int n,int gap=1)
{
    for(int i=gap+1;i<=n;++i){
        for(int j=i;j-gap>=1 && a[j] < a[j-gap];j-=gap){
            swap(a[j],a[j-gap]);
        }
        
        for(int i=1;i<=n;++i){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }
}

const int N=1e5+100;
int a[N];

int main(void)
{
    int n;
    while(cin>>n){
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        InserSort(a,n);

    }
    return 0;
}