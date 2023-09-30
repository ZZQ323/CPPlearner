#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<stack>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

#define ok 0
#define error -1

// 原文链接：https://blog.csdn.net/youngurt/article/details/117477894

/*

从右到左进行遍历。
1.遇到的是运算数，直接输出。
2.遇到的是右括号')'，直接压入堆栈(括号是最高优先级，无需比较；入栈后优先级降到最低，确保其他符号正常入栈)。
3.遇到的是左括号'('，意味着括号已结束。不断弹出栈顶运算符并输出，直到遇到右括号，这个右括号弹出但是不输出。
4.遇到的是运算符('+'、'-'、'*'、'/')，有三种情况
    ①如果栈为空，直接入栈。
    ②如果栈顶元素是右括号')'，直接入栈。
    ③如果栈顶元素是运算符，则需要进行比较，
        1-如果优先级大于等于栈顶运算符，则压入堆栈；
        2-如果优先级小于栈顶运算符，则将栈顶运算符弹出并输出，然后比较新的栈顶运算符，直到优先级大于等于栈顶运算符或者栈空，再将该运算符入栈
5.如果对象处理完毕，则按顺序弹出并输出栈中所有运算符

*/

void Poland(const string& var)
{
    stack<char> st;
    stack<string> buf;    
    stringstream ss;
    for(int i=var.size()-1;i>=0;--i){
        if( isdigit(var[i]) ){
            ss<<var[i];
            while(i-1>=0 && isdigit(var[i-1])){
                ss<<var[--i];
            }
            string temp=ss.str();
            reverse(temp.begin(),temp.end());
            buf.push(temp+" ");
        }else if( var[i]==')' || var[i]=='*' || var[i]=='/'){
            st.push(var[i]);
        }else if(var[i]=='+'||var[i]=='-'){
            while( st.size() &&  (st.top()=='*' || st.top()=='/' )  ){
                buf.push(to_string(st.top())+" ");
                st.pop();
            }
            st.push(var[i]);
        }else if(var[i]=='('){
            while( st.size() && st.top()!=')' ){
                buf.push(to_string(st.top())+" ");
                st.pop();
            }

            if( st.size() ){
                st.pop();
            }else{
                cerr<<"wrong\n";
                throw runtime_error("illegal input");
            }
        }
        ss.str("");
    }

    while(st.size()){
        buf.push(to_string(st.top())+" ");
        st.pop();
    }

    while(buf.size()){
        cout<<buf.top();
        buf.pop();
    }

}

/*
从左到右进行遍历。
1.遇到的是运算数，直接输出。
2.遇到的是左括号'('，直接压入堆栈(括号是最高优先级，无需比较；入栈后优先级降到最低，确保其他符号正常入栈)。
3.遇到的是右括号')'，意味着括号已结束。不断弹出栈顶运算符并输出，直到遇到左括号，这个左括号弹出但是不输出。
4.遇到的是运算符('+'、'-'、'*'、'/')，有三种情况
    ①如果栈为空，直接入栈。
    ②如果栈顶元素是左括号'('，直接入栈
    ③如果栈顶元素是运算符，则需要进行比较，
        1-如果优先级大于栈顶运算符，则压入堆栈；
        2-如果优先级小于等于栈顶运算符，则将栈顶运算符弹出并输出，然后比较新的栈顶运算符，直到优先级大于栈顶运算符或者栈空，再将该运算符入栈
5.如果对象处理完毕，则按顺序弹出并输出栈中所有运算符
*/

void revPoland(const string& var)
{
    stack<char> st;
    stringstream ss;
    for(int i=0;i<var.size();++i)
    {
        if( isdigit(var[i]) ){
            ss<<var[i];
            while( i+1<var.size() && isdigit(var[i+1])){
                ss<<var[++i];
            }
            cout<<ss.str()<<' ';
        }else if(var[i]=='('){
            st.push(var[i]);
        }else if( var[i]=='*' || var[i]=='/' ){
            while( st.size() && st.top()!='('){
                cout<<st.top()<<' ';
                st.pop();
            }
            st.push(var[i]);
        }else if(var[i]=='+' || var[i]=='-'){
            while( st.size() && 
                st.top()=='*' || st.top()=='/' &&
                st.top()!='('
                ){
                cout<<st.top()<<' ';
                st.pop();
            }
            st.push(var[i]);
        }else if(var[i]==')'){
            while( st.size() && st.top()!='('){
                cout<<st.top()<<' ';
                st.pop();
            }
            if(st.size()){
                st.pop();
            }else{
                cerr<<"wrong\n";
                throw runtime_error("");
            }
        }
        ss.str("");
    }

    while( st.size() ){
        cout<<st.top()<<' ';
        st.pop();
    }
}

int main(int argc,char**argv)
{
    int T;
    cin>>T;
    while(T--){
        string line;
        cin>>line;
        Poland(line);
        cout<<'\n';
        revPoland(line);
        cout<<'\n';
    }
    return 0;
}
