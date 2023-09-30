#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(int argc,char**argv)
{
    int t;
    cin>>t;
    while(t--){
        string str;
        stack<char>st;
        cin>>str;
        for(string::iterator it=str.begin();it!=str.end();++it)
        {
            st.push(*it);    
        }
        while(st.size())
        {
            cout<<st.top();
            st.pop();
        }
        cout<<endl;
    }

    return 0;
}