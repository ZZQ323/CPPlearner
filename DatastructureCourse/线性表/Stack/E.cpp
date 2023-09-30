#include<iostream>
#include<stack>
#include<string>
#include<cstring>

using std::cin;
using std::cout;
using std::string;
using std::stack;

char match[260];

int main(int argc,char**argv)
{
    memset(match,-1,sizeof(match));
    match[')']='(';
    match['}']='{';
    match[']']='[';

    int T;
    cin>>T;
    cin.get();
    while(T--){
        stack<char>st;
        char temp=0;
        bool flag=true;
        while( temp=cin.get() , temp!=-1 && temp!='\n')
        {
            if(!flag)continue;
            if(temp=='(' || temp=='{' || temp=='['){
                st.push(temp);
            }else if( temp==')' ||  temp=='}' ||  temp==']'){
                if( !st.size() ||  match[temp]!=st.top() ){
                    flag=false;
                }else{
                    st.pop();
                }
            }       
        }

        if(flag && !st.size() )
            cout<<"ok\n";
        else 
            cout<<"error\n";
    }    
    return 0;
}
