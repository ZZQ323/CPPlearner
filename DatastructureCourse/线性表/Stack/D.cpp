#include<iostream>
#include<stack>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stack;

int main(int argc,char**argv)
{
    int T;
    cin>>T;
    while(T--){
        string str;
        stack<char>st;
        stack<char>rst;
        cin>>str;
        for(auto it:str){
            if(it!='#')
                st.push(it);
            else if( st.size() )
                st.pop();
        }
        if(st.size()){
            while( st.size() ){
                rst.push(st.top());
                st.pop();
            }
            while( rst.size() ){
                cout<<rst.top();
                rst.pop();
            }
            cout<<'\n';
        }else {
            cout<<"NULL\n";
        }
    }
    return 0;
}