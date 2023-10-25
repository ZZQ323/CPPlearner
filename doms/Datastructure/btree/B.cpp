#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=1e5+100;
char str[N];
int Next[N],Nextval[N];

void init(char p[],int Next[],int Nextval[])
{
    Next[0]=0;
    Next[1]=0;
    for(int i=1,j=0;p[i];   ){
        while( j && p[i]!=p[j] )j=Next[j];
        Next[++i]=(p[i]==p[j])?j+1:0;
        ++j;

        if(p[i]==p[j])Nextval[i]=Nextval[j];
        else Nextval[i]=Next[i];
    }
}

char* kmp(char s[],char p[])
{
    init(p,Next,Nextval);
    for(int i=0,j=0;s[i];){
        while( ~j && s[i]!=p[j] )
            j=Next[j];
        if(j==-1)++j;
        ++i;
        if(p[i]==0)return s+i-strlen(p);
    }
    return nullptr;
}

int main(int argc,char**argv)
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        init(str,Next,Nextval);
        int len=strlen(str);
        if( Next[len] )
            str[Next[len]]=0,puts(str);
        else
            puts("empty");
    }   


    return 0;
}
