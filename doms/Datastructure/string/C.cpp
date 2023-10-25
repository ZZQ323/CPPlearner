#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack>

using namespace std;

queue<int> qe,buf,ans;
vector<vector<int > >a;
char s[100];

bool check(int val,int obj)
{
    int p1=-1,p2=-1;
    for(int i=0;i<a.size() ;++i){
        for(int j=0;j<a[i].size();++j){
            if(a[i][j]==val)
                p1=i;
            if(a[i][j]==obj)
                p2=i;
        }
    }
    return p1==p2;
}


int main(int argc,char** argv)
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        int n;
        scanf("%d",&n);
        int x;
        a.push_back(vector<int>(0));
        while(n--){
            scanf("%d",&x);
            a[i].push_back(x);
        }
    }

    while( ~scanf("%s",s)  && strcmp(s,"STOP") ){
        if( !strcmp(s,"ENQUEUE") ){
            int val;
            scanf("%d",&val);
            bool done=0, flag=0;
            while( qe.size() ){
                int tp=qe.front();
                qe.pop();
                bool tpp=check(tp,val);
                if( tpp  && !flag)flag=1;

                if(!done &&  flag ^ tpp )
                    buf.push(val),done=1;
                buf.push(tp);
            }

            if( !done )buf.push(val);

            while( buf.size() ){
                qe.push(buf.front());
                buf.pop();
            }
        }else{
            ans.push(qe.front());
            qe.pop();
        }
    }

    printf("%d",ans.front());
    ans.pop();
    while(ans.size()){
        printf(" %d",ans.front());
        ans.pop();
    }


    return 0;
}
