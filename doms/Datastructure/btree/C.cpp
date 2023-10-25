#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=1e5+100;
char str[N],tar[N];
int Next[N];
// 原文链接：https://blog.csdn.net/bjbz_cxy/article/details/126799481

void init(char p[],int Next[])
{
    Next[0]=0;
    Next[1]=0;
    for(int i=1,j=0;p[i];   ){
        while(j && p[i]!=p[j])j=Next[j];
        Next[++i]=(p[i]==p[j])?++j:0;
    }
}

int kmp(char s[],char p[],int Next[])
{
    int ret=0;
    init(p,Next);
    for(int i=0,j=0;s[i];   ){
        while(j && s[i]!=p[j] )j=Next[j];
        if( s[i]==p[j] )++j;
        ++i;
        ret=max(ret,j);
        if(!p[j]){
            break;
        }
    }
    return ret;
}


int main(int argc,char** argv)
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        char* tp=str;
        int ans=0;
        for(int i=1;str[i];++i){
            sprintf(tar,"%.*s",i,str);
            ans=max(ans,kmp(tar,str+i,Next) );
        }
        printf("%d\n",ans==0?-1:ans);
    }
    
    return 0;
}