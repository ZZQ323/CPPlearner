#include<iostream>
#include<stack>
#include<cstring>
#include<queue>

using namespace std;

#define ll long long 

stack<int> st;
queue<int> qe;
char t[]="0123456789ABCDEFGHIJKLMN";

void trans1(int n,int radix)
{
    while(n){
        st.push(n%radix);
        n/=radix;
    }
    while(st.size()){
        printf("%c",t[st.top()]);
        st.pop();
    }
}

void trans2(int cnt,int n,int radix)
{
    ll p=1;
    while( p<=n ){
        p*=10;
    }

    int count=cnt;
    while(n && count--){
        n*=radix;
        qe.push(n/p);
        n-=n/p*p;
    }

    while(qe.size() && cnt){
        --cnt;
        printf("%c",t[qe.front()]);
        qe.pop();
    }

    while(cnt--)
        putchar('0');
}

char num[1000];

int main(int argc,char**argv)
{
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,k;
        scanf("%d",&a);
        bool flag=0;
        if( getchar()=='.' )
            scanf("%s",num),flag=true;
        scanf("%d",&k);
        trans1(a,k);
        if( flag ){
            putchar('.');
            b=[](char*n)-> int {
                int ret=0;
                int i=0;
                while( n[i] ){
                    ret*=10;
                    ret+=n[i++]-'0';
                }
                return ret;
            }(num);
            trans2(3,b,k);
        }
        putchar('\n');
    }

    return 0;
}