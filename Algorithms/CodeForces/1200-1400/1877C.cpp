#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        if( k>3 )printf("0\n");
        else if(k==3){
            if( m<=n )
                puts("0");
            else 
                printf("%d\n",m-n-m/n+1);   
        }else if(k==2){
            if( m<=n )
                printf("%d\n",m);
            else 
                printf("%d\n",m/n+n-1);   
        }else if(k==1){
            puts("1");
        }
    }
    return 0;
}
