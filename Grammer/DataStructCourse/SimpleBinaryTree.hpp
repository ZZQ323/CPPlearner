#include<iostream>
#include"staticSeqContainer.hpp"


#ifndef TUTORIAL_SIMPLEBINARYTREE_HPP
#define TUTORIAL_SIMPLEBINARYTREE_HPP

struct BiTNode{
    char val;
    int left;
    int right;
}tr[N];

//树的递归遍历方式
//赋值粘贴的时候不要出错了
void PreDo(int now)
{
    if( now!=-1 ){
//        do
        PreDo(tr[now].left);
        PreDo(tr[now].right);
    }
}
void MidDo(int now)
{
    if( now!=-1 ){
        MidDo(tr[now].left);
        //        do
        MidDo(tr[now].left);
    }

}
void PostDo(int now)
{
    if( now!=-1 ){
        PostDo(tr[now].left);
        PostDo(tr[now].left);
        //        do
    }

}

//树的非归遍历方式
void PreDO(int now)
{
    stack<int>stNode;
    if( now==-1 )return ;
    while( stNode.size() || now!=-1 ){
        if( now!=-1 ){
            std::cout<<tr[now].val<<'\n';
            stNode.push(now);
            now=tr[now].left;
        }else if( stNode.size() ){
            now=stNode.top();
            stNode.pop();
            now=tr[now].right;
        }
    }
}

void MidDO(int now)
{
    stack<int>stNode;
    if( now==-1 )return ;
    while( stNode.size() || now!=-1 ){
        if( now!=-1 ){
            stNode.push(now);
            now=tr[now].left;
        }else if( stNode.size() ){
            now=stNode.top();
            stNode.pop();
            std::cout<<tr[now].val<<'\n';
            now=tr[now].right;
        }
    }
}

void PostDO(int now)
{
    stack<int> stNode,status;
    if(now==-1)return ;
    while( stNode.size() || now!=-1 ){
        if( now!=-1 ){
//                第一次经过这个节点，探索左边
            stNode.push(now);
            now=tr[now].left;
            status.push(0);
        }else{
//            不删节点，因为等到节点确实不存在的时候，栈顶就是上一个存在的节点
            now=stNode.top();
            if( status.top()==0 ){
//                第二次经过这个节点，探索右边，更新状态
                now=tr[now].right;
                status.pop();
                status.push(1);
            }else{
//                最后一次经过，删除节点和状态，完成遍历
                std::cout<<tr[now].val<<'\n';
                status.pop();
                stNode.pop();
                now=-1;
            }
        }
    }
}

void LayerDo(int now)
{
    queue<int>qe;
    while( qe.size() ){
        auto now=qe.front();
        qe.pop();

    }
}




#endif //TUTORIAL_SIMPLEBINARYTREE_HPP
