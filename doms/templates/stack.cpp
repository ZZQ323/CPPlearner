//
// Created by 19169 on 2023/9/25.
//

#include<climits>
#include<iostream>
#include<cstdio>
#include<cstdlib>


#define ok 0
#define error -1

struct SeqStack{
    static int Maxn;
    int data[999];
    int tp;

    SeqStack(){;}

    bool Full(){return  tp==Maxn-1;}
    bool Empty(){return  !tp;}
    int push(int d){if( Full() ) { data[++tp] = d ;return ok;}else return error;}
    int top(){if(Empty()) {return data[tp]; }else return INT_MIN;}
    int pop(){if(Empty())return error;else { --tp; return ok;} }
};
int SeqStack::Maxn=999;

struct Node{
    int d;
    Node* next;
    Node(int vd=0)
    :d(vd),next(nullptr){;}
    Node(const Node& var){
        d=var.d;
        next== nullptr;
    }
};

struct LinkStack{
    static int Maxn;
    Node* head;
    int cnt;

    LinkStack()
    :cnt(0){head=new Node();}

    bool Full(){return  cnt==Maxn;}
    bool Empty(){return  head->next== nullptr;}
    int push(Node d);
    Node top();
    int pop();
    Node* locate(int k);
};
int LinkStack::Maxn=999;

int LinkStack::push(Node d){
    if( Full() ) {
        ++cnt ;
        Node* nx=new Node(d);
        nx->next=head->next;
        head->next=nx;
        return ok;
    }else return error;
}

Node LinkStack::top(){
    if( Empty() ) {
        return *(head->next);
    }else  exit(1);
}

int LinkStack::pop(){
    if(Empty())
        return error;
    else {
        --cnt;
        Node* temp=head->next;
        head->next=temp->next;
        delete temp;
        return ok;
    }
}

Node* LinkStack::locate(int k){
    Node* now=head;
    while(now->next && k){
        now=now->next;
        --k;
    }
    if(k==0)return now;
    else return nullptr;
}


int main(int argc,char**argv)
{

    return 0;
}

