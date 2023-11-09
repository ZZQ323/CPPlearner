#include<iostream>

using std::cin;
using std::cout;

const int N=1e5+100;
char str[N];


namespace zzq323{

    struct Bitree
    {

        struct Node
        {
            char val;
            Node *lchild,*rchild;

            Node(char v)
            :val(v),lchild(nullptr),rchild(nullptr)
            {;}

        };
        
        Node* head;

        void init(Node*&now,char* &s)
        {
            if(*s!='#'){
                now=new Node(*s);
                init(now->lchild,++s);
                init(now->rchild,++s);
            }
        }

        Bitree(char* s)
        :head(nullptr){;init(head,s);}

        void del(Node*now)
        {
            if(now){
                del(now->lchild);
                del(now->rchild);
                delete now;
            }
        }

        ~Bitree()
        {
            del(head);
            head=nullptr;
        }

    };

    void pre(Bitree::Node*now)
    {
        if(now){
            cout<<now->val<<' ';
            pre(now->rchild);
            pre(now->lchild);
        }
    }

    void mid(Bitree::Node*now)
    {
        if(now){
            mid(now->rchild);
            cout<<now->val<<' ';
            mid(now->lchild);
        }
    }

    void suf(Bitree::Node*now)
    {
        if(now){
            pre(now->rchild);
            pre(now->lchild);
            cout<<now->val<<' ';
        }
    }

    // template 
    struct list
    {
        
    };

    struct Queue{

    };

    void bfs(Bitree::Node*now)
    {

    }
}

using namespace zzq323;

int main(int argc,char*argv[])
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        Bitree var(str);

    }
    return 0;
}