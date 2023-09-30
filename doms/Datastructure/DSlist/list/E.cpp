#include<iostream>

using std::cin;
using std::cout;
using std::endl;

#define error -1
#define ok 0

struct Node
{
    int data;
    Node*next;

    Node(int d=0){
        data=d;
        next=nullptr;
    }
};

// 归并到La
int LL_merge(Node *La, Node *Lb)
{
    if(La==nullptr)return error;
    if(Lb==nullptr)return error;

    while( La->next && Lb->next ){
        if(La->next->data < Lb->next->data){
            La=La->next;
        }else {
            Node* temp=Lb->next;
            Lb->next=Lb->next->next;
            temp->next=La->next;
            La->next=temp;
            La=La->next;
        }
    }

    if( Lb->next ){
        La->next=Lb->next;
    }

    return ok;
}

void display( Node*h )
{
    if(h->next==nullptr)return void();
    h=h->next;
    while(h!=nullptr){
        cout<<h->data<<' ';
        h=h->next;
    }
}


signed main(int argc,char**argv)
{
    int n;
    cin>>n;
    Node*var1=new Node(),*var2=new Node();
    Node* temp=new Node();


    var1->next=temp;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        temp->data=x;
        if(i!=n-1){
            temp->next=new Node();
            temp=temp->next;
        }
    }

    cin>>n;
    temp=new Node();
    var2->next=temp;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        temp->data=x;
        if(i!=n-1){
            temp->next=new Node();
            temp=temp->next;
        }
    }

    LL_merge(var1,var2);
    display(var1);

    
    return 0;
}