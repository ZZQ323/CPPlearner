//
// Created by 19169 on 2023/9/30.
//
#include"include/list.hpp"
#include <stdexcept>

#define ok 0
#define error -1

namespace ZZQ323{

    Circulist::Circulist(){
        rear=new Node();
        len=0;
    }

    Circulist::Circulist(const Circulist&var){
        rear=new Node();
        len=0;

        Node*now=rear;
        Node*they=var.rear->next;
        while( they!=nullptr ){
            now=now->next=new Node();
            now->shallow_copy(*they);
            they=they->next;
            ++len;
        }
    }

    Circulist& Circulist::operator=(const Circulist&var){
        if(&var==this)
            return *this;
        rear=new Node();
        len=0;

        Node*now=rear;
        Node*they=var.rear->next;
        while( they!=nullptr ){
            now=now->next=new Node();
            now->shallow_copy(*they);
            they=they->next;
            ++len;
        }
    }

    Circulist::~Circulist(){
        rear->pre->next=nullptr;
        rear->pre=nullptr;

        Node*now=rear;
        Node*pre=nullptr;

        while(now!=nullptr){
            pre=now;
            now=now->next;
            delete pre;
        }
    }

    // two ciclist becomes one 
    void Circulist::merge(const Circulist& var){
        Node* headA=this->rear->next;
        this->rear->next=var.rear->next->next;
        delete var.rear->next;
        var.rear->next= headA;
    }

    int Circulist::push_back(Node var)
    {
        Node*nx=new Node();
        nx->pre=rear;
        rear=rear->next=nx;
        nx->shallow_copy(var);
    }

    int Circulist::push_front(Node var)
    {
        Node*pr=new Node();
        pr->next=rear->next;
        rear->next=pr->next->pre=pr;
        pr->shallow_copy(var);
    }

    int Circulist::pop_back()
    {
        Node* temp=rear->pre;
        rear->pre=temp;
        temp->next=rear;
        delete temp;
    }

    int Circulist::pop_front()
    {
        Node*temp=rear->next;
        rear->next=temp->next;
        temp->next->pre=rear;
        delete temp;
    }

    // 访问
    Node& Circulist::operator[](int id)
    {
        Node*now=rear->next;

        while(now && id--){
            now=now->next;    
        }

        if(id)throw std::runtime_error("ZZQ323::Ciclist out of range");
        else return *now;
    }



    struct Circulist::iterator
    {
        void ch_next();
        void ch_pre();

        explicit iterator(Node var,Node*hd=nullptr)
        :list_head(hd){current=&var;}

        explicit iterator(Node* var,Node*hd=nullptr)
        :list_head(hd),current(var){;}

        iterator(const iterator&var)=default;

        iterator operator+(int id);
        iterator operator-(int id);
        iterator& operator+=(int id);
        iterator& operator-=(int id);
        iterator operator++(int);
        iterator& operator++();
        iterator operator--(int);
        iterator& operator--();

        Node* current;
        Node* list_head;
    };

    
    void Circulist::iterator::ch_next()
    {
        do{
            current=current->next;
        }while(current);
    }
        
    void Circulist::iterator::ch_pre()
    {
        do{
            current=current->pre;
        }while(current);
    }

    Circulist::iterator Circulist::iterator::operator+(int id)
    {
        Circulist::iterator now(*this);
        while(id--)
            now.ch_next();
        return now;
    }

    Circulist::iterator Circulist::iterator::operator-(int id)
    {
        Circulist::iterator now(*this);
        while(id--)
            now.ch_pre();
        return now;
    }

    Circulist::iterator& Circulist::iterator::operator+=(int id)
    {
        while(id--)
            ch_next();       
        return *this;
    }   

    Circulist::iterator& Circulist::iterator::operator-=(int id)
    {
        while(id--)
            ch_pre(); 
        return *this;
    }

    Circulist::iterator Circulist::iterator::operator++(int)
    {
        Circulist::iterator now(*this);
        ch_next();
        return now;
    }

    Circulist::iterator& Circulist::iterator::operator++()
    {  
        ch_next();
        return *this;
    }

    Circulist::iterator Circulist::iterator::operator--(int)
    {
        Circulist::iterator now(*this);
        ch_pre();
        return now;
    }

    Circulist::iterator& Circulist::iterator::operator--()
    {
        ch_pre();
        return *this;
    }

    Circulist::iterator Circulist::begin()
    {
        return Circulist::iterator(rear->next,rear);
    }

    Circulist::iterator Circulist::end()
    {
        return Circulist::iterator(rear,rear);
    }

    int Circulist::insert(int indx,Node var)
    {
        Node temp=operator[](indx);
        Node* nx=new Node(var);
        nx->next=&temp;
        nx->pre=temp.next;
        nx->next->pre=nx;
        nx->pre->next=nx;
        return ok;
    }

    int Circulist::earse(int indx)
    {
        Node temp=operator[](indx);
        temp.next->pre=temp.pre;
        temp.pre->next=temp.next;
        delete &temp;
        return ok;
    }

    int Circulist::insert(iterator indx,Node var)
    {
        Node*& now=indx.current;
        Node* nx=new Node(var);
        nx->next=now;
        nx->pre=now->next;
        nx->next->pre=nx;
        nx->pre->next=nx;
    }

    int Circulist::earse(iterator indx)
    {
        Node*& now=indx.current;
        now->next->pre=now->pre;
        now->pre->next=now->next;
        delete now;
        return ok;
    }


} // ZZQ323

