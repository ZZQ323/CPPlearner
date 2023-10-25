#include<iostream>
#include<list>
#include<algorithm>

using namespace std;


int main(int argc,char**argv){
    int n;
    scanf("%d",&n);
    list<int> ls;
    ls.push_back(1);
    for(int i=2;i<=n;++i){
        int k,p;
        scanf("%d%d",&k,&p);
        auto it=find(ls.begin(),ls.end(),k);
        if(p){
            ls.insert(++it,i);
        }else {
            ls.insert(it,i);
        }
    }

    int m;
    scanf("%d",&m);
    while(m--){
        int x;
        scanf("%d",&x);
        ls.remove(x);
    }
    
    for(auto tpp:ls)
        printf("%d ",tpp);
    
    return 0;
}