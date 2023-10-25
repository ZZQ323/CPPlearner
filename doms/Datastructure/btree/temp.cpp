#include<iostream>
#include<cstring>

using namespace std;

const int N=1e4+100;
char str[N];
int Next[N];

#define scanf(...) fscanf(fp,__VA_ARGS__)

void init(char p[],int Next[])
{
    Next[0]=Next[1]=0;
    for(int i=1,j=0;p[i];   ){
        while( j && p[j]!=p[i] )
            j=Next[j];
        if( p[j]==p[i] ){
            Next[++i]=++j;
        }else Next[++i]=0;
    }
}

int main(int argc,char**argv)
{
    FILE* fp = fopen("C:\\Users\\19169\\Downloads\\1075_test0.in","r+");
    int T;
    scanf("%d",&T);
    while( ~scanf("%s",str) ){
        init(str,Next);
        for(int i=0;i<=strlen(str);++i){
            printf("Next[%d]=%d\n",i,Next[i]);
        }
        puts("----------------------");
        system("pause");
    }
    fclose(fp);
    return  0;
}