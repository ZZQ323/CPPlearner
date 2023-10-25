#include<iostream>
#include<cstring>

using namespace std;

const int N=1e4+100;
char str[N];
int Next[N];

void init(char p[],int Next[])
{
    Next[0]=Next[1]=0;
    for(int i=1,j=0;p[i];   ){
        while( j && p[j]!=p[i] )
            j=Next[j];
        if(p[i]==p[j]){
            Next[++i]=++j;
        }else Next[++i]=0;
    }
}

int main(int argc,char**argv)
{
    int T;
    scanf("%d\n",&T);
    while(T--){
        scanf("%s",str);
        int len=strlen(str);
        init(str,Next);
        if( !Next[len] )printf("%d\n",len);
        else{
            int tp=len-Next[len];
            printf("%d\n",(tp-len%tp)%tp);
        } 
    }
    
    system("pause");

    return 0;
}


