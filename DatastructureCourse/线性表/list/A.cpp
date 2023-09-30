#include<iostream>
using namespace std;


#define ok 0
#define error -1

// 顺序表类定义
class SeqList
{
private:
    int *list;      // 元素数组
    int maxsize;    // 顺序表最大长度
    int size;       // 顺序表实际长度
public:
    // 构造函数
    SeqList();                          
    // 析构函数
    ~SeqList();                         
    // 获取顺序表实际长度
    int list_size(){return size;}
    
    // 插入一个元素，参数是插入的数值和位置                   
    int list_insert(int x, int item)
    {
        if( size>=maxsize || x<0 || x>size )
            return error;
        for(int i=size;i>x;--i)
            list[i]=list[i-1];
        list[x]=item;
        ++size;
        return ok;
    }   
    
    // 删除一个元素，参数是删除的位置
    int list_del(int x)
    {
        if( !size || x<0   || x > size-1 )
            return error;
        for(int i=x+1;i<size;++i)
            list[i-1]=list[i];
        --size;
        return ok;
    }        

    // 获取一个元素，参数是获取的位置        
    int list_get(int x)
    {
        return list[x];
    }   

    // 输出整个顺序表             
    void list_display()
    {
        for(int i=0;i<size;++i)
        {
            cout<<list[i]<<' ';
        }
    }   

};

SeqList::SeqList()
{
    maxsize = 1000;
    size = 0;
    list = new int[maxsize];
}

SeqList::~SeqList()
{
    delete []list;
}


int main(void)
{
    int n;
    cin>>n;
    SeqList var;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        var.list_insert(i,x);
    }
    cout<<var.list_size()<<' ';
    var.list_display();
    cout<<'\n';

    int pos,val;
    cin>>pos>>val;
    --pos;
    if( !(var.list_insert(pos,val)) ){
        cout<<var.list_size()<<' ';
        var.list_display();
        cout<<'\n';
    }else cout<<"error\n";

    cin>>pos>>val;
    --pos;
    if( !(var.list_insert(pos,val)) ){
        cout<<var.list_size()<<' ';
        var.list_display();
        cout<<'\n';
    }else cout<<"error\n";

    cin>>pos;
    --pos;
    if( !(var.list_del(pos)) ){
        cout<<var.list_size()<<' ';
        var.list_display();
        cout<<'\n';
    }else cout<<"error\n";

    cin>>pos;
    --pos;
    if( !(var.list_del(pos)) ){
        cout<<var.list_size()<<' ';
        var.list_display();
        cout<<'\n';
    }else cout<<"error\n";

    cin>>pos;
    --pos;
    if( pos>=0 && pos<var.list_size() ){
        cout<<var.list_get(pos);
        cout<<'\n';
    }else cout<<"error\n";

    cin>>pos;
    --pos;
    if( pos>=0 && pos<var.list_size() ){
        cout<<var.list_get(pos);
        cout<<'\n';
    }else cout<<"error\n";

    return 0;
}