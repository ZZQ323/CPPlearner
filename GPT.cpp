#include<bits/stdc++.h>

using namespace std;

const int N=2e5+100;
int P[N],S[N];

int main(void)
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>P[i];
    }

    for(int i=1;i<=n-k+1;++i)
    {
        memcpy(S+1,P+1,n*sizeof(int));
        sort(S+i,S+i+k);
        for(int j=1;j<=n;++j)
        {
            cout<<S[j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}