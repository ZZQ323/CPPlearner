#include<iostream>
#include<vector>
#include"Meta.hpp"
#include"algorithms.hpp"

#ifndef TUTORIAL_DYNCCONTAINER_HPP
#define TUTORIAL_DYNCCONTAINER_HPP

// const int N=10;

//通用二叉树节点
template<class T,class U=int>
struct BiTNode{
    int left=-1,right=-1;
    T key;
    U data;

    void init(T k_,U d_=U ())
    {left=right=-1;key=d_,data=d_;}

    BiTNode(T k_,U d_=U ())
    {init(k_,d_);}
};


//优先队列(大根堆)
template<class T,class Container=std::vector<T>,class cmp=Compare<T> >
struct priority_queue{

#define lson(x) (heap[x].left)
#define rson(x) (heap[x].right)
#define exist(x) (~(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

    BiTNode<T> heap[N];
    // Container heap;
    static int tp;
    static int root;

    void update(int now=root)
    {
        for(int nex=now>>1;nex;nex>>=1){
            if( cmp(heap[nex],heap[now]) )
                swap(heap[nex],heap[now]);
            else break;
        }
    }

    void push_down(int now=root)
    {
        for(int nex=now<<1;nex<=tp;nex<<=1){
            if(nex+1<=tp && cmp(heap[nex],heap[nex+1]) )
                ++nex;
            if( cmp(heap[nex],heap[now]) )break;
            swap(heap[now],heap[nex]);
            now=nex;
        }
    }

    void insert(T val)
    {
        heap[++tp]=val;
        update(tp);
    }

    void pop()
    {
        swap(heap[root],heap[tp]);
        --tp;
        push_down(root);
    }

    size_t size(){return tp;}

    T top()
    {return heap[root].key;}

#undef lson
#undef rson
#undef exist
#undef max
#undef min
};

template<class T,class Container,class cmp>
int priority_queue<T,Container,cmp>::tp=0;
template<class T,class Container,class cmp>
int priority_queue<T,Container,cmp>::root=1;

//顺序二叉树
template<class T,class U=int,class cmp=Compare<T> >
struct BiSTree{
#define lson(x) (tr[x].left)
#define rson(x) (tr[x].right)
#define exist(x) (~(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

    BiTNode<T,U> tr[N];
    static int tp;
    static int root;

    void update(int now)=0;

    void insert(T key,U data=0,int& now=root)override
    {
        if( now==-1 ){
            now=tp++;
            tr[now].init(key,data);
        }else if(key<tr[now].key){
            insert(key,data,tr[now].left);
        }else if(key>tr[now].key){
            insert(key,data,tr[now].right);
        }
        update(now);
    }

    void remove(T key,int& now=root)override
    {
        if( now == -1 )return ;
        else if( key < tr[now].key )remove(key,tr[now].left);
        else if( key > tr[now].key )remove(key,tr[now].right);
        else{
            if( tr[now].left==-1 )now=tr[now].right;
            else if( tr[now].right==-1 )now=tr[now].left;
            else {
                int nd;
                for(nd=tr[now].left;nd!=-1;nd=tr[nd].right);
                tr[now].key=tr[nd].key;
                tr[now].data=tr[nd].data;
                remove(tr[now].left,key);
            }
        }
        if( now == -1 )return ;
        update(now);
    }

    BiTNode<T,U> search(T key,int& now=root)
    {
        if( now==-1 )return BiTNode<T,U>().init();
        if(key<tr[now].key){
            search(key,tr[now].left);
        }else if(key>tr[now].key){
            search(key,tr[now].right);
        }else return {key,tr[now].data};
    }

#undef lson
#undef rson
#undef exist
#undef max
#undef min
};

template<class T,class U,class cmp >
int BiSTree<T,U,cmp>::tp=0;

template<class T,class U,class cmp >
int  BiSTree<T,U,cmp>::root=-1;

//平衡二叉树节点
template<class T, class U>
struct AVLNode:public BiTNode<T,U>{
    int height;
    AVLNode(T k=T (), U d = 0)
            :height(0),BiTNode<T,U>(k,d){;}
};

//平衡二叉树
template<class T, class U=int,class cmp=Compare<T> >
struct ALV:public BiSTree<T,U,cmp>{
#define lson(x) (tr[x].left)
#define rson(x) (tr[x].right)
#define exist(x) (~(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
    AVLNode<T,U> tr[N];
    static int tp;//栈顶
    static int root;//全局根

    void update(int now)
    {
        int lh = exist(lson(now)) ? tr[lson(now)].height : 0;
        int rh = exist(rson(now)) ? tr[rson(now)].height : 0;
        tr[now].height = max(lh, rh) + 1;
    }

    int heightDiff(int now)
    {
        int lh = exist(lson(now)) ? tr[lson(now)].height : 0;
        int rh = exist(rson(now)) ? tr[rson(now)].height : 0;
        return lh - rh;
    }

    int LL(int an)
    {
        int bn = tr[an].left;
        int dn = tr[bn].right;
//    摘掉了an的左子树之后左边是空的，bn右边是空的
//    所以bn要插入的东西插入到an空的地方，an插入同理
        tr[an].left = dn;
        tr[bn].right = an;

//    an在下面，先更新an
        update(an);
        update(bn);
//    由于这里还是没有更改父亲节点
//    所以这里返回头节点去在外面更新父亲
        return bn;
//    return 的永远是顶点
    }

    int RR(int an)
    {
        int bn = rson(an);
        swap(rson(an), lson(rson(an)));
        update(an);
        update(bn);
        return rson(an);
    }

    int LR(int an) {
        RR(lson(an));
        return LL(an);
    }

    int RL(int an) {
        LL(rson(an));
        return RR(an);
    }

    void insert(T key, U data = 0,int &now=root)
    {
        if (tp == 0 || now==-1 ) {
            now = tp++;
            tr[now].init(key, data);
        } else if (key < tr[now].key) {
            Insert(lson(now), key, data);
            if (heightDiff(now) == 2) {
//      因为知道了这个key一定是插入到了左子树，但是不知道在左子树的哪里
//      在左子树左边就是LL否则就是LR
                now = tr[lson(now)].key < key ? LL(now) : LR(now);
            }
        } else if (key > tr[now].key) {
            Insert(rson(now), key, data);
            if (heightDiff(now) == -2) {
                now = tr[rson(now)].key < key ? RL(now) : RR(now);
            }
        }//else (key == tr[now].key){} 键值是唯一的
//    每修改一次都需要更新一次
        update(now);
    }

    void remove(T key,int &now=root)
    {
//    这压根就不是个节点
        if (now==-1)return;
        else if (key < tr[now].key)Delete(lson(now), key);
        else if (key > tr[now].key)Delete(rson(now), key);
        else {
//key==tr[now].key找到了这个根节点
//重复修改，都是空呢，直接修改now
            if (lson(now) == -1)now = rson(now);
            else if (rson(now) == -1)now = lson(now);
            else {
                int nd;
                for (nd = lson(nd); nd != -1; nd = rson(nd));
                tr[now].key = tr[nd].key;
                tr[now].data = tr[nd].data;
                Delete(lson(now), tr[nd].key);
            }
        }
//   返回前需要做的全部事情
//   这个now为根的树只有一个节点的情况下还删掉了根
        if (now==-1)return;
//    每修改一次都需要更新一次
        update(now);

//    旋转平衡
        if (heightDiff(now) == 2) {
//      每一次调整都可把调整后的顶点 --- now 的平衡因子调为0
//      而之前被调整的顶点的平衡因子也会因此变成0
            now = heightDiff(lson(now)) >= 0 ?
                  LL(now) : LR(now);
        } else if (heightDiff(now) == -2) {
            now = heightDiff(rson(now)) <= 0 ?
                  RR(now) : RL(now);
        }
    }

    AVLNode<T,U> search(T key,int& now=root)
    {
        if( now==-1 )return AVLNode<T,U>();
        if(key<tr[now].key){
            return search(key,tr[now].left);
        }else if(key>tr[now].key){
            return search(key,tr[now].right);
        }else return {key,tr[now].data};
    }

    // 重置
    void clear()
    {root = tp = 0;}

#undef lson
#undef rson
#undef exist
#undef max
#undef min
};

template<class T, class U,class cmp>
int ALV<T,U,cmp>::tp=0;
template<class T, class U,class cmp>
int ALV<T,U,cmp>::root=1;










#endif //TUTORIAL_DYNCCONTAINER_HPP
