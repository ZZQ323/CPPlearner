#include<iostream>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;
using ll=long long ;

constexpr int N=2100;
char poland[N],buffer[N];
inline bool isoperator(char x){return x=='-'||x=='+'||x=='*'||x=='/'||x=='%';}

template<class T>
struct Wraper{
    T val;
    bool isnum;
    Wraper(T val,bool isnum)
    :val(val),isnum(isnum){;}
};

void calc(queue<Wraper<ll>>& exp)
{
    stack<ll> ans;
    while(exp.size()){
        auto cur=exp.front();exp.pop();
        if( cur.isnum ){
            ans.push(cur.val);
        }else{
            auto lpos=ans.top();ans.pop();
            auto rpos=ans.top();ans.pop();
            if( cur.val=='+' ){
                ans.push(rpos+lpos);
            }else if( cur.val=='-' ){
                ans.push(rpos-lpos);
            }else if( cur.val=='*' ){
                ans.push(rpos*lpos);
            }else if( cur.val=='/' ){
                ans.push(rpos/lpos);
            }
        }
    }
    printf("%lld",ans.top());
}

void solve(char obj[])
{
    int len = strlen(obj);
    stack<char> oper;
    queue<Wraper<ll>> num;
    for(int i=0;i<len;++i){
        char cur=obj[i];
        if( isdigit(cur) ){
            ll tmp=cur-'0';
            while(i+1<len &&  isdigit(obj[i+1]) ){
                tmp*=10;
                tmp+=obj[++i]-'0';
            }
            num.push({tmp,1});
        }else if( cur=='('){   
            oper.push(cur);
        }else if(cur=='*' || cur=='/' ){   
            while(oper.size() &&  (oper.top()=='*' || oper.top()=='/' ) ){
                num.push({oper.top(),0});
                oper.pop();
            }
            oper.push(cur);
        }else if( cur=='-' || cur=='+' ){
            while(oper.size() &&  (oper.top()=='*' || oper.top()=='/' ||  oper.top()=='-' || oper.top()=='+') ){
                num.push({oper.top(),0});
                oper.pop();
            }
            oper.push(cur);
        }else if( cur==')' ){
            while( oper.size() && oper.top()!='('){
                num.push({oper.top(),0});
                oper.pop();
            }
            try{
                oper.pop(); // 去掉左括号
            }catch(const std::exception& e){
                puts("公式错误！");
                exit(1);
            }
        }
    }
    while(oper.size()){
        num.push({oper.top(),0});
        oper.pop();
    }
    calc(num);
}

void test()
{
    /*
    1+2*3-4
    1+1+1*2-4*7
    */
    fgets(buffer,N,stdin);
    solve(buffer);
    exit(1);
}

int main(int argc, char const *argv[])
{
    // test();
    int n;
    scanf("%d\n",&n);
    fgets(buffer,N,stdin);
    int len=strlen(buffer);
    for(int i=1,j=0;i<n;++i){
        char tmp;
        do tmp=getchar();while(!isoperator(tmp) && tmp!=-1);
        while( j<len && isdigit(buffer[j]) )++j;
        buffer[j++]=tmp;
    }
    solve(buffer);
    return 0;
}
