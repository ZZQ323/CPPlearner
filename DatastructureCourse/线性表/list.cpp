/*
    * DataStructure Course
    *  顺序（存储）线性表，随机存取
    *  链式（存储）线性表，顺序存取
    * 
    *  难点：有序表合并：
    *   顺序线性表写错容易tle，直接默写归并排序的归并就好了。
    *   链式线性表写错容易RE
    * 注意：
    *   指针判空一定在前面
    *   一定要返回状态，防止幽闭
    *   RE错误：越界访问、访问0地址、重复释放（浅拷贝）、数组过大、递归爆栈、
    *   TLE错误：死循环、
    *
*/


#include<iostream>

using namespace std;

#define ok 0
#define error -1

// 顺序表类定义
struct Seqlist
{
    int *list;      // 元素数组
    static int maxsize;    // 顺序表最大长度
    int size;       // 顺序表实际长度

    // 构造函数
    Seqlist(){size=0;list = new int[maxsize];}

    Seqlist(const Seqlist& var){
        size=0;
        list = new int[maxsize];
        for(int i=0;i<var.size;++i)
            list[i]=var.list[i];
    }

    // 析构函数
    ~Seqlist() {delete []list;}

    // 获取顺序表实际长度
    int list_size(){return size;}

    // 单个（尾部）加入
    int push_back(int val);
    
    // 单个（尾部）删除
    int pop_back();

    // 单个插入，参数是插入的数值和位置                   
    int list_insert(int x, int item); 
    
    // 单个删除，参数是删除的位置
    int list_del(int x);      

    // 访问元素，参数是获取的位置        
    int list_get(int x);  

    // 批量插入，参数是插入的数值和位置      
    int multiinsert(int x, int n, int item[]);

    // 批量删除，参数是删除的位置
    int multidel(int x, int n);

    // 输出整个顺序表             
    void list_display();   

    int& operator[](int index){ return list[index]; }

    // 有序表合并
    friend int merge(Seqlist& itemA,Seqlist& itemB,Seqlist& ret);
};

int Seqlist::maxsize = 1000;

int Seqlist::push_back(int val)
{
    if( size>=maxsize )
        return  error;
    list[size++]=val;
    return ok;
}

int Seqlist::pop_back()
{
    if( size>=maxsize )
        return  error;
    --size;
    return ok;
}

int Seqlist::list_insert(int x, int item)
{
    if( size>=maxsize || x<0 || x>size )
        return error;
    for(int i=size;i>x;--i)
        list[i]=list[i-1];
    list[x]=item;
    ++size;
    return ok;
}   

int Seqlist::list_del(int x)
{
    if( !size || x<0   || x > size-1 )
        return error;
    for(int i=x+1;i<size;++i)
        list[i-1]=list[i];
    --size;
    return ok;
}        

int Seqlist::list_get(int x)
{
    return list[x];
}   

int Seqlist::multiinsert(int x, int n, int item[])
{
    if( size+n > maxsize || x<0 || x>size  )
        return error;
    for(int i=size-1;i>=x;--i){
        list[i+n]=list[i];
    }
    for(int i=x;i<x+n;++i){
        list[i]=item[i-x];
    }
    size+=n;
    return ok;
}

int Seqlist::multidel(int x, int n)
{
    if( size < n  || x<0 || x>size  )
        return error;
    for(int i=x+n;i<size;++i){
        list[i-n]=list[i];
    }
    size-=n;
    return ok;
}

void Seqlist::list_display()
{
    for(int i=0;i<size;++i)
    {
        cout<<list[i]<<' ';
    }
}   

int merge(Seqlist& itemA,Seqlist& itemB,Seqlist& ret)
{
    if(itemB.size+itemA.size>ret.maxsize)
        return error;
    int i=0,j=0,k=0;
    ret.size=itemB.size+itemA.size;
    while( i<itemA.size &&  j<itemB.size )
    {
        if( itemA.list[i] < itemB.list[j] )
            ret.list[k++]=itemA.list[i++];
        else
            ret.list[k++]=itemB.list[j++];
    }
    while( i<itemA.size)
        ret.list[k++]=itemA.list[i++];
    while( j<itemB.size)
        ret.list[k++]=itemB.list[j++];

    return ok;
}

/////////////////////////////////////////////////////////////////////////
//////////////////@_@////////////////////////////////////////////////////
//////////////////////////////////////////@_@////////////////////////////
///////@_@///////////////////////////////////////////////////////////////
///////////////////////////////@_@///////////////////////@_@/////////////
/////////////////////////////////////////////////////////////////////////
///////////@_@///////////////////////////////////////////////////////////

// 多项式链表
struct Node
{
    int val;
    int power;
    int data;
    Node* next;

    Node(int a=0,int b=0)
    :val(a),power(b){next = nullptr;}

    Node(const Node& var)
    {
        val=var.val;
        power=var.power;
        next=nullptr;
    }
};

// 带头结点的单链表类定义
struct Linklist
{
    Node *head;
    int len;

    // 构造函数
    Linklist();

    // 析构函数
    ~Linklist();

    // 返回第x个结点的指针，如果不存在返回NULL
    Node* index(int x);

    // 获取第x个元素的数据
    int get(int x);       

    // 把数值item插入第x个位置
    int insert(int x, int item);

    // 删除第x个结点
    int del(int x);

    //有序表合并
    void merge(const Linklist& var){
        Node*here=this->head;
        Node*there=var.head->next;
        while( here->next!= nullptr ){
            if(here->next->power > there->power){
                Node*temp=here->next;
                here=here->next=new Node(*there);
                here->next=temp;

                there=there->next;
            }else if(here->next->power == there->power){
                here->next->val+=there->val;

                there=there->next;
            }else{
                //here->next->power < there->power
                here=here->next;
            }
        }
        while(there!=nullptr &&  here->power == there->power ){
            here->val+=there->val;
            there=there->next;
        }
        while(there!= nullptr){
            here=here->next=new Node(*there);
            there=there->next;
        }
    }

    // 输出单链表的内容
    void display();  

};

Linklist::Linklist()
{
    head = new Node();
    len = 0;
}

Linklist::~Linklist()
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

Node* Linklist::index(int x)
{
    if(x==-1)
        return head;
    Node* now=head->next;
    while(x &&  now->next!=nullptr)
        now=now->next,--x;
    if(x)return nullptr;
    else return now;
}     

int Linklist::get(int x)
{
    Node* now=index(x);
    return now->data; 
}             

int Linklist::insert(int x, int item)
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

int Linklist::del(int x)
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


void merge(Linklist& La, Linklist& Lb, Linklist& ret)
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

void Linklist::display()
{
    Node* now=head->next;
    while( now != nullptr ){
        cout<<now->data<<' ';
        now=now->next;
    }
}


// 循环链表类定义

/////////////////////////////////////////////////////////////////////////
//////////////////@_@////////////////////////////////////////////////////
//////////////////////////////////////////@_@////////////////////////////
///////@_@///////////////////////////////////////////////////////////////
///////////////////////////////@_@///////////////////////@_@/////////////
/////////////////////////////////////////////////////////////////////////
///////////@_@///////////////////////////////////////////////////////////


namespace circulate
{
    struct Node{
        int   data;
        Node* next;
        Node* pre;
        
        Node(int d=0)
        :data(d),next(nullptr),pre(nullptr){}

        Node(const Node& var)
        :data(var.data),next(var.next),pre(var.pre){;}

    };


    struct Circulist{
        Node* head;
        Node* rear;
        int len;

        Circulist();
        Circulist(const Circulist&var);
        ~Circulist();
        Circulist& operator=(const Circulist&var);
        
        int push_back();
        int pop_back();
        int insert();
        int earse();

        //循环链表合并
        void merge(const Circulist& var);
    };

    Circulist::Circulist(){
        head=new Node();
        len=0;
    }

    Circulist::Circulist(const Circulist&var){
        head=new Node();
        len=0;

        Node*now=head;
        Node*they=var.head->next;
        while( they!=nullptr ){
            now->next=new Node();
            now=now->next;
            now->data=they->data;
            they=they->next;
            ++len;
        }
    }

    Circulist& Circulist::operator=(const Circulist&var){
        if(&var==this)
            return *this;
        head=new Node();
        len=0;

        Node*now=head;
        Node*they=var.head->next;
        while( they!=nullptr ){
            now->next=new Node();
            now=now->next;
            now->data=they->data;
            they=they->next;
            ++len;
        }
    }

    Circulist::~Circulist(){
        Node*now=head;
        Node*pre=nullptr;
        while(now!=nullptr){
            pre=now;
            now=now->next;
            delete pre;
        }
    }
       

    void Circulist::merge(const Circulist& var){
        Node* headA=this->rear->next;
        this->rear->next=var.rear->next->next;
        delete var.rear->next;
        var.rear->next= headA;
    }


}



