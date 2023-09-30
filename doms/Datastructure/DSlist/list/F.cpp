#include<iostream>
#include<algorithm>
#include<list>

using std::cin;
using std::cout;
using std::ostream;
using std::istream;
using std::list;

#define ok 0
#define error -1

struct Node{
    int val;
    int power;
    Node* next;

    Node(int a=0,int b=0)
    :val(a),power(b){next=nullptr;}

    Node(const Node& var)
    :val(var.val),power(var.power),next(var.next){;}

    Node& operator=(const Node&var){
        val=var.val;
        power=var.power;
        next=var.next;
        return *this;
    }

    void copy(Node& var){
        val=var.val;
        power=var.power;
    }

    friend ostream& operator<<(ostream& out,Node var){
        if(var.val){
            if(var.val<0)
                out<<'('<<var.val<<')';
            else out<<var.val;

            if(var.power){
                out<<"x^";
                if(var.power<0)
                    out<<'('<<var.power<<')';
                else out<<var.power;
            }
        }
        return out;
    }
};

struct Linkedlist
{
    Node* head,*rear;
    int len;

// 构造函数
    Linkedlist(){
        head=new Node();
        rear=nullptr;
        len=0;
    }

// 析构函数
    ~Linkedlist(){
        Node* now=head;
        Node* pre=nullptr;
        while( now!=nullptr ){
            pre=now;
            now=now->next;
            delete pre;
        }
    }

    void push_front(Node x){
        Node* nx=new Node(x);
        if(rear==nullptr) {
            head->next=rear=nx;
        }else{
            nx->next=head->next;
            head->next=nx;
        }
        ++len;
    }

    void push_back(Node x){
        Node* nx=new Node(x);
        if(rear==nullptr) {
            head->next=rear=nx;
        }else{
            rear->next=nx;
            rear=rear->next;
        }
        ++len;
    }

    Node& operator[](int index){
        Node* now=head->next;
        while( now && index)
            --index,now=now->next;

        if(index)exit(1);
        else return *now;
    }

    friend ostream& operator<<(ostream& out,Linkedlist&  var){
        Node*now=var.head;

        do{
            now=now->next;
        }while( now && !now->val   );

        while( now!=nullptr ){
            out<<*now;
            do{
                now=now->next;
            }while( now && !now->val   );
            if(now) out<<" + ";
        }

        return out;
    }

    friend Linkedlist LL_merge(Linkedlist& La, Linkedlist& Lb)
    {
        Linkedlist ret;
        Node* ptr1=La.head->next;
        Node* ptr2=Lb.head->next;
        Node* ptr=ret.head;

        while( ptr1 && ptr2 ){
            ptr->next=new Node();
            ptr=ptr->next;
            if( ptr1->power == ptr2->power ){
                ptr->copy(*ptr1);
                ptr->val+=ptr2->val;

                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }else if(ptr1->power < ptr2->power){
                ptr->copy(*ptr1);

                ptr1=ptr1->next;
            }else{
                ptr->copy(*ptr2);

                ptr2=ptr2->next;
            }
        }

        while( ptr1 ){
            ptr->next=new Node();
            ptr=ptr->next;

            ptr->copy(*ptr1);
            ptr1=ptr1->next;
        }

        while( ptr2 ){
            ptr->next=new Node();
            ptr=ptr->next;

            ptr->copy(*ptr2);
            ptr2=ptr2->next;
        }

        return ret;
    }
};

signed main(int argc,char**argv)
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        Linkedlist var1;
        for(int i=0;i<n;++i)
        {
            int val,power;cin>>val>>power;
            var1.push_back({val,power});
        }
        cout<<var1<<'\n';

        cin>>n;
        Linkedlist var2;
        for(int i=0;i<n;++i)
        {
            int val,power;cin>>val>>power;
            var2.push_back({val,power});
        }
        cout<<var2<<'\n';

        Linkedlist&& temp=LL_merge(var1,var2);
        cout<<temp<<'\n';
    }
    return 0;
}