#include<iostream>
#include<queue>

using namespace std;
using pii=pair<int ,int >;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    queue<pii> ans;
    for(int i=1;i<=n;++i){
        int x;
        scanf("%d",&x);
        if( i==1 ){
            ans.push(pii(x,i));
        }else if(x > ans.back().first ){
            ans.push(pii(x,i));
            if( ans.size()>5 )
                ans.pop();
        }
    }
    while(ans.size()){
        printf("%d ",ans.front().second);
        ans.pop();
    }
    return 0;
}
