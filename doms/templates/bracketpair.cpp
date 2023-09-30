#include<iostream>


bool judge(char s[])
{
    char buf[1000];int tp=0;
    static char match[256];

    buf[')']='(';
    buf[']']='[';
    buf['}']='{';

    for(int i=0; s[i] ;++i){
        if( s[i]=='(' || s[i]=='[' || s[i]=='{' )
            buf[++tp]=buf[i];
        else if(tp &&  buf[tp]==match[ s[i] ] )
            --tp;
        else return false;
    }
    return !tp;
}

char str[1000];

signed main(int argc,char**argv)
{

    while( ~scanf("%s",str) ){
        if( judge(str) )puts("yes");
        else puts("no");
    }
    return 0;
}