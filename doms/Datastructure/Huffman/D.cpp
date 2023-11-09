#include<iostream>

using std::cin;
using std::cout;

char cht[1100][1100];
int g[1100][1100];

enum {UNDIR,DIR};

#define min(a,b) ((a)<(b)?:(a):(b))
#define max(a,b) ((a)>(b)?:(a):(b))

inline int strlen(char tar[])
{
    int ret=0;
    while( tar[ret++] );
    return ret;
}

inline int strcmp(char tar[],char obj[])
{
    if( !tar || !obj)
        return -0x7fffffff;
    int len1=strlen(tar);
    int len2=strlen(obj);

    int i=0;
    while( true )
    {
        if( !tar[i] && !obj[i] )
            return 0;   
        if( tar[i]-obj[i] )
            return tar[i]-obj[i];
        ++i;
    }
}

int search(char tar[],char obj[][1100],int n)
{
    int ret=-0x7ffffffff;

    for(int i=0;i<n;++i){
        if( !strcmp( tar,obj[i] ) ){
            ret=i;
            break;
        }    
    }

    return ret;
}

int main(int argc,char**argv)
{
    int t;
    cin>>t;
    while(t--)
    {
        char tp;cin>>tp;
        if(tp=='D')tp=DIR;
        else tp=UNDIR;

        int n;cin>>n;
        for(int i=0;i<n;++i)
        {
            char temp;
            cin>>cht[i];    
            for(int j=0;j<n;++j)
                g[i][j]=0;
        }


        int m;cin>>m;
        for(int i=0;i<m;++i)
        {
            static char str1[1100];
            static char str2[1100];
            cin>>str1>>str2;
            g[ search(str1,cht,n) ][ search(str2,cht,n) ]++;
            if( !tp )
                g[ search(str2,cht,n) ][ search(str1,cht,n) ]++;
        }

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
                cout<<g[i][j]<<' ';
            cout<<'\n';
        }

        for(int i=0;i<n;++i)
        {
            int in=0,out=0,degree=0;
            for(int j=0;j<n;++j)
            {
                out+=g[i][j];
                in+=g[j][i];
            }
            cout<<cht[i];
            if( tp ){
                degree=in+out;
                if( degree ){
                    cout<<": "<<out<<' '<<in<<' '<<degree;
                }
            }else{
                degree=in;
                if(degree)
                    cout<<": "<<degree;
            }
            cout<<'\n';
        }
    }
    system("pause");

    return 0;
}