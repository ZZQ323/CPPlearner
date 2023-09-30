#include<iostream>
using namespace std;
#define ok 0
#define error -1

// 链表结点定义
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int d=0) {next = NULL,data=d;}

    ListNode(const ListNode& var) {
        next = var.next;
        data=var.data;
    }
};

// 带头结点的单链表类定义
class LinkList
{
public:
    ListNode *head;
    int len;
    // 操作定义
    LinkList();
    ~LinkList();

    // 返回第x个结点的指针，如果不存在返回NULL
    ListNode* LL_index(int x)
    {
        if(x==-1)
            return head;
        ListNode* now=head->next;
        while(x &&  now->next!=nullptr)
            now=now->next,--x;
        if(x)return nullptr;
        else return now;
    }     

    // 获取第x个元素的数据
    int LL_get(int x)
    {
        ListNode* now=LL_index(x);
        return now->data; 
    }             

    // 把数值item插入第x个位置
    int LL_insert(int x, int item)
    {
        ListNode* now=LL_index(x-1);
        if(   now==nullptr  )
            return error;
        ListNode* nx=new ListNode(item);
        nx->next=now->next;
        now->next=nx;
        ++len;
        return ok;
    }

    // 删除第x个结点
    int LL_del(int x)
    {
        ListNode* pre=LL_index(x-1);
        if ( pre==nullptr  )
            return error;
        ListNode* now=pre->next;
        pre->next=now->next;
        delete now;
        --len;
        return ok;
    }             

    // 输出单链表的内容
    void LL_display()
    {
        ListNode* now=head->next;
        while( now != nullptr ){
            cout<<now->data<<' ';
            now=now->next;
        }
    }             

};

LinkList::LinkList()
{
    head = new ListNode();
    len = 0;
}

LinkList::~LinkList()
{
    ListNode *now, *pre;
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


signed main(int argc,char**argv)
{
    int n;
    cin>>n;
    LinkList var;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        var.LL_insert(i,x);
    }

    var.LL_display();
    cout<<'\n';

    int pos,val;

    cin>>pos>>val;
    --pos;
    if( var.LL_insert(pos,val)==ok ){
        var.LL_display();
        cout<<'\n';
    }else cout<<"error\n";

    cin>>pos>>val;
    --pos;
    if( var.LL_insert(pos,val)==ok ){
        var.LL_display();
        cout<<'\n';
    }else cout<<"error\n";


    cin>>pos;
    --pos;
    if( var.LL_del(pos)==ok ){
        var.LL_display();
        cout<<'\n';
    }else cout<<"error\n";

    cin>>pos;
    --pos;
    if( var.LL_del(pos)==ok ){
        var.LL_display();
        cout<<'\n';
    }else cout<<"error\n";

    cin>>pos;
    --pos;
    if( pos>=0 && pos<var.len ){
        cout<<var.LL_get(pos);
        cout<<'\n';
    }else cout<<"error\n";

    cin>>pos;
    --pos;
    if( pos>=0 && pos<var.len ){
        cout<<var.LL_get(pos);
        cout<<'\n';
    }else cout<<"error\n";

    return  0;
}

