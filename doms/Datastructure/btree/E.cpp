#include<iostream>

using namespace std;

struct Node{
    char data;
    Node *lchild,*rchild;

    Node(char d=0)
    :data(d),lchild(nullptr),rchild(nullptr)
    {}

};

// struct Btree{
//     Node* head;
//     Btree()
//     :head(nullptr){}
// };

Node* head=nullptr;
const int N=1e4+100;
char str[N];

void build(Node* &now,int& id)
{
    if(str[++id]=='#'){
        now=nullptr;
    }else{
        now=new Node(str[id]);
        build(now->lchild,id);
        build(now->rchild,id);
    }
}

void Preout(Node* now)
{
    if(now){
        putchar(now->data);
        Preout(now->lchild);
        Preout(now->rchild);
    }
}

void Midout(Node* now)
{
    if(now){
        Midout(now->lchild);
        putchar(now->data);
        Midout(now->rchild);
    }
}

void Sufout(Node* now)
{
    if(now){
        Sufout(now->lchild);
        Sufout(now->rchild);
        putchar(now->data);
    }
}

void del(Node*now)
{
    if(now){
        del(now->lchild);
        del(now->rchild);
        delete now;
    }
}

int main(int argc,char**argv)
{
    int t;
    scanf("%d",&t);
    while(t--){
        head=nullptr;
        scanf("%s",str);
        int id=-1;
        build(head,id);
        Preout(head);puts("");
        Midout(head);puts("");
        Sufout(head);puts("");
        del(head);
    }
    return 0;
}
