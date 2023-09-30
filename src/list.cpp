//
// Created by 19169 on 2023/9/28.
//

#include "../include/forward_list.hpp"
#define ok 0
#define error -1

namespace ZZQ323 {

    forward_list::forward_list()
    {
        head = new Node();
        len = 0;
    }

    forward_list::~forward_list()
    {
        Node *now, *pre;
        now = head;
        while(now != nullptr )
        {
            pre = now;
            now = now->next;
            delete pre;
        }
        len = 0;
        head = nullptr ;
    }

    Node* forward_list::index(int x)
    {
        if(x==-1)
            return head;
        Node* now=head->next;
        while(x &&  now->next!=nullptr)
            now=now->next,--x;
        if(x)return nullptr;
        else return now;
    }

    int forward_list::get(int x)
    {
        Node* now=index(x);
        return now->data;
    }

    int forward_list::insert(int x, int item)
    {
        Node* now=index(x-1);
        if(   now==nullptr  )
            return error;
        Node* nx=new Node(item);
        nx->next=now->next;
        now->next=nx;
        ++len;
        return ok;
    }

    int forward_list::del(int x)
    {
        Node* pre=index(x-1);
        if ( pre==nullptr  )
            return error;
        Node* now=pre->next;
        pre->next=now->next;
        delete now;
        --len;
        return ok;
    }


    void merge(forward_list& La, forward_list& Lb, forward_list& ret)
    {
        Node* ptr1=La.head->next;
        Node* ptr2=Lb.head->next;
        Node* ptr=ret.head;

        while( ptr1 && ptr2 ){
            if( ptr1->power == ptr2->power ){
                ptr=ptr->next=new Node(*ptr2);
                ptr->val+=ptr2->val;

                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }else if(ptr1->power < ptr2->power){
                ptr=ptr->next=new Node(*ptr1);

                ptr1=ptr1->next;
            }else{
                ptr=ptr->next=new Node(*ptr2);

                ptr2=ptr2->next;
            }
        }

        while( ptr1 ){
            ptr=ptr->next=new Node();

            ptr1=ptr1->next;
        }

        while( ptr2 ){
            ptr=ptr->next=new Node(*ptr2);

            ptr2=ptr2->next;
        }
        return void();
    }

    void forward_list::display()
    {
        Node* now=head->next;
        while( now != nullptr ){
            cout<<now->data<<' ';
            now=now->next;
        }
    }
} // ZZQ323