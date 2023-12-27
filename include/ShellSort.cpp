#include<iostream>

using namespace std;

const int N=1e5+100;
int a[N];

void InserSort(int a[],int n,int gap=1)
{
    for(int i=gap+1;i<=n;++i){
        for(int j=i;j>=1 && a[j]>=a[j-gap];j-=gap){
            swap(a[j],a[j-gap]);
        }
    }
}

void ShellSort(int a[],int n)
{
    for(int gap=10;gap >= 1;gap>>=1){
        InserSort(a,n,gap);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        ShellSort(a,n);
        for(int i=1;i<=n;++i){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}