#include<iostream>
#include<cstring>

using namespace std;

const int N=1e5+100;
char pattern[N],text[N];
int Next[N];

void init(char p[])
{
    Next[0]=-1;
    int i=0,j=-1;
    while( p[i] ){
        if(j==-1 || p[i]==p[j]){
            Next[++i]=++j;
        }else {
            j=Next[j];
        }
    }
}

int match(char s[],char p[])
{
    for( int i=0,j=0;s[i];){
        if(j==-1 || s[i]==p[j]){
            if( !p[j+1] )return i-strlen(p)+1;
            else ++i,++j;
        }else j=Next[j];
    }
    return -1;
}

int main(int argc,char**argv)
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",text,pattern);
        init(pattern);
        for(int i=0;pattern[i];++i){
            printf("%d ",Next[i]);
        }
        printf("\n%d\n",match(text,pattern)+1);
    }
    return 0;
}