#include<iostream>
#include<cstring>

using namespace std;

const int N=1e5+100;
char str[N],tar[N],rep[N];
int Next[N];

void init(char p[],int Next[])
{
    Next[0]=-1;
    for(int i=0,j=-1;p[i];      ){
        if(j==-1 || p[i]==p[j]){
            Next[++i]=++j;
            if( p[i]==p[Next[i]] ){
                Next[i]=Next[Next[i]];
            }
        }else{
            j=Next[j];
        }
    }
}

char* KMP_match(char s[],char p[])
{
    init(p,Next);
    for(int i=0,j=0; s[i]  ;    ){
        while( ~j && s[i]!=p[j] )j=Next[j];
        if(j==-1 || s[i]==p[j]){
            ++j;
        }
        ++i;
        if( !p[j] )
            return s+i-strlen(p);
    }
    return nullptr;
}

int main(int argc,char**argv)
{
    int t;scanf("%d",&t);
    while(t--){
        scanf("%s %s %s",str,tar,rep);
        puts(str);
        
        char* tp=KMP_match(str,tar);
        if( tp ){
            strcat( rep+strlen(rep) , tp+strlen(tar) );
            sprintf(tp,"%s",rep);
        }
        puts(str);
    }

    return 0;
}