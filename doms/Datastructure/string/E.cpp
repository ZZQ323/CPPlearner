#include<iostream>
#include<queue>
#include<map>

using namespace std;

struct Node{
    int time;
    bool operator<(const Node& x)const {
        return time>x.time;
    }
};

pair<int ,int >client[2000];

int main(int argc,char**argv){
    int n;
    scanf("%d",&n);
    priority_queue<Node> ft;
    
    for(int i=1;i<=n;++i){
        int t,p;
        scanf("%d %d",&t,&p);
        client[i]=make_pair(t,p);
    }   
    int k;
    scanf("%d",&k);

    for(int i=1;i<=k;++i)
        ft.push({0});

    int now=0,waits=0;
    int lgs=0,lst=0;
    for(int i=1;i<=n;++i){
        Node tp=ft.top();
        ft.pop();
        if(client[i].first < tp.time){
            waits+= tp.time - client[i].first;
            lgs=max(lgs,tp.time - client[i].first);
            tp.time=tp.time+client[i].second;
            ft.push(tp);
        }else{
            tp.time=client[i].first+client[i].second;
            ft.push(tp);
        }
        lst=max(lst,tp.time);
    }   
    printf("%.1f %d %d",waits/1.0/n,lgs,lst);


    return 0;
}