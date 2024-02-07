#include<bits/stdc++.h>

using namespace  std;

constexpr int N=1e4+100;

struct Node{
    int val;//已经有了多少个
}tree[N];
int n;

inline int lowbit(int x)
{return x&(-x);}

void change(int pos,int val)
{
    for(int i=pos;i<=n;i+=lowbit(i)){
        tree[i].val+=val;
    }
}

int ask(int pos)
{
    int ret=0;
    for(int i=pos;i;i-=lowbit(i)){
        ret+=tree[i].val;
    }
    return ret;
}

int query(int l,int r)
{
    return ask(r)-ask(l-1);
}

using pii=pair<int ,int >;
vector<pii> ve;

int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int temp;
        scanf("%d",&temp);
        ve.push_back(pii(temp,i));
    }
    sort(ve.begin(),ve.end(),greater<pii>() );

    long long ans=0;
    for(int i=0;i<ve.size();++i){
        ans+=ask(ve[i].second);
        change(ve[i].second,1);
    }
    printf("%lld\n",ans);

    return 0;
}
