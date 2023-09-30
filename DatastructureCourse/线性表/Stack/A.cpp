#include<iostream>

using namespace std;

int n,m;

struct Node{
    int data;

    Node* pre;
    Node* next;

    Node(int d=0)
    :data(d),next(nullptr),pre(nullptr)
    {;}

};

struct DSlist{
    Node * head,*rear;
    DSlist()
    {head=new Node();rear=nullptr;}

    void push_back(int d);
    Node&operator[](int id);
    int find(Node& val);
};

void DSlist::push_back(int d)
{
    if( rear== nullptr ){
        rear=head->next=new Node(d);
        rear->pre=head;
    }else{
        rear->next=new Node(d);
        rear->next->pre=rear;
        rear=rear->next;
    }
}

Node& DSlist::operator[](int id)
{
    Node*now=head->next;
    while(now!=nullptr && id){
        now=now->next;
        --id;
    }
    if(id)
        exit(1);
    else
        return *now;
}

int DSlist::find(Node& val)
{
    Node*now=head->next;
    int ret=0;
    while(now && ret<n &&  now->data != val.data ){
        now=now->next;
        ++ret;
    }
    if( now->data == val.data ){
        return ret;
    }else return -1;
}

int main(int argc,char**argv)
{
    cin>>n>>m;
    DSlist var;
    for(int i=1;i<=n;++i)
    {
        int val;
        cin>>val;
        var.push_back(val);
    }

    while(m--){
        int val;
        cin>>val;

        Node temp(val);
        int id=var.find(temp);

        if( id>0 && id<n-1 )
            cout<<var[id].pre->data<<' '<<var[id].next->data<<endl;
        else if( id==n-1 )
            cout<<var[id].pre->data<<endl;
        else if( id==0 )
            cout<<var[id].next->data<<endl;
    }

    return 0;
}