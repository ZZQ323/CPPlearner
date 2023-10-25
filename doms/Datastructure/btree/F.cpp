#include<iostream>

using namespace std;

struct Node{
    char data;
    Node *lchild,*rchild;

    Node(char d=0)
    :data(d),lchild(nullptr),rchild(nullptr)
    {}

};

Node* head=nullptr;
const int N=1e4+100;
char str[N];
int ans;

bool build(Node* &now,int& id)
{
    if(str[++id]=='0'){
        now=nullptr;
        return false;
    }else{
        now=new Node(str[id]);
        int tp=0;
        tp+=build(now->lchild,id);
        tp+=build(now->rchild,id);
        ans+=(tp==0);
        return true;
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
        ans=0;
        head=nullptr;
        scanf("%s",str);
        int id=-1;
        build(head,id);
        del(head);
        printf("%d\n",ans);
    }
    system("pause");

    return 0;
}
