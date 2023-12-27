#include<iostream>
#include<set>
#include<functional>

using namespace std;

const int N=1e5+100;

#define lson(x) (seg[x].left)
#define rson(x) (seg[x].right)

template<class _Key,class _Compare,class _Alloc>
set<_Key,_Compare,_Alloc>
        operator+( set<_Key,_Compare,_Alloc>one,
                set<_Key,_Compare,_Alloc>other ){
    one.insert(other.begin(),other.end());
    return one;
}

struct Segment
{
    struct Node
    {
        int left=-1,right=-1;
        set<int> info;
        bool tag=false;

        void 
        init(int val=0)
        {
            left=right=-1;
            info.insert(val);
        }

    }seg[N<<2];
    int root=-1;
    int tp=0;

    inline 
    void 
    update(int k)
    {seg[k].info=seg[lson(k)].info+seg[rson(k)].info;}

    void set_tag(int k)
    {seg[k].tag=1;}

    void push_down(int k){
        ;
    }

    void 
    insert(int& k,int l,int r,int pos,int w)
    {
        if(k==-1)
            k=++tp;
        if(l==r && l==pos)
            seg[k].init(w);
        else
        {
            int mid = l + r >> 1;
            push_down(k);
            if (pos <= mid)
                insert(seg[k].left, l, mid, pos, w);
            if (pos >= mid + 1)
                insert(seg[k].right, mid + 1, r, pos, w);
            update(k);
        }
    }

    void
    modify(int& k,int l,int r,int ql,int qr,int w)
    {
        if(k==-1)
            k=++tp;
        if(qr==r && ql==l)
            seg[k].init(w);
        else
        {
            int mid = l + r >> 1;
            push_down(k);
            if (qr <= mid)
                modify(seg[k].left, l, mid, ql,qr, w);
            else if (ql >= mid + 1)
                modify(seg[k].right, mid + 1, r, ql,qr, w);
            else
                modify(seg[k].left, l, mid, ql,mid, w),
                        modify(seg[k].right, mid + 1, r, mid+1,qr, w);
            update(k);
        }
    }

    void remove(int&k,int l,int r,int pos)
    {
        int mid=l+r>>1;
        if( l<r ){
            if(k==-1)return;
            if(pos<mid)remove(seg[k].left,l,mid,pos);
            else remove(seg[k].right,mid+1,r,pos);
        }else if(l==r){
            seg[k].init();
            k=-1;
        }
    }

    set<int>
    check(int k,int l,int r,int pos)
    {
        if(k==-1)return {0};
        if(l==r && l==pos){
            return seg[k].info;
        }else{
            int mid=l+r>>1;
            if(pos<=mid)
                return check(seg[k].left,l,mid,pos);
            if(pos>mid)
                return check(seg[k].right,mid+1,r,pos);   
        }
    }

    set<int>
    query(int k,int l,int r,int ql,int qr)
    {
        if(k==-1)return {0};
        if(ql==l && qr==r){
            return seg[k].info;
        }else{
            int mid=l+r>>1;
            if(qr<=mid)
                return query(seg[k].left,l,mid,ql,qr);
            else if(ql>mid)
                return query(seg[k].right,mid+1,r,ql,qr);
            else
                return query(seg[k].left,l,mid,ql,mid)
                    +query(seg[k].right,mid+1,r,mid+1,qr);
        }
    }

    void clear()
    {root=-1,tp=0;}

    size_t size(){return tp;}
}tr;

int a[N];


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        tr.insert(tr.root,1,n,i,a[i]);
    }

    int m;
    cin>>m;
    for(int i=1;i<=m;++i){
        int l,r;
        cin>>l>>r;
        cout<<tr.query(tr.root,1,n,l,r).size()<<'\n';
    }
    return 0;
}