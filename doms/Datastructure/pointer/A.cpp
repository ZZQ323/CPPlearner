#include<bits/stdc++.h>

using namespace std;

char month[][15]={
"January","February","March","April","May","June","July","Aguest","September","October","November","December"
};

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        if(n>=1 && n<=12)
            printf("%s\n",month[n-1]);
        else puts("error");
    }
    return 0;
}



