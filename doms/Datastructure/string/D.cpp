#include<iostream>
#include<stack>

using namespace std;

const int N=1e5+10;
char s[N];

int main(int argc,char**argv){
    stack<int> st;
    scanf("%s",s);
    char boy=s[0];
    for(int i=0;s[i];++i){
        if( s[i]==boy )
            st.push(i);
        else {
            printf("%d %d\n",st.top(),i);
            st.pop();
        }
    }
    return 0;
}