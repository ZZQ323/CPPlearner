#include<iostream>
#include<string>
#include<map>
#include <climits>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

typedef pair<int ,int > pii;

const int N=1e5+100;

struct Table{
    unsigned char ch=CHAR_MAX+1;
    int wt=0;

    bool operator<(const Table&x)const{
        return ch<x.ch;
    }

    static void zero(Table p[],int size){
        for(int i=1;i<=size;++i){
            p[i].ch=CHAR_MAX+1;
            p[i].wt=0;
        }
    }

    bool operator==(const Table&x)const{
        return ch==x.ch;
    }
    static int getid(char tar,Table p[],int size){
        for(int i=1;i<=size;++i){
            if(p[i].ch==tar)return i;
        }
        return -2147483648;
    }
}tt[60];

class Huffman{
private:

    pii _select_min(int end);
    void _build();
    void _destory();
    void _coding();

public:

    void init(Table t[],int n);

    Huffman(){
        size=leaves=0;
        Tree= nullptr;
        Code= nullptr;
    }

    ~Huffman(){_destory();}

    int Decode(const string codestr, char txtstr[],char cht[]);


public:
    struct Node{
        int lchild,rchild;
        int weight;
        int parent;

        Node()
        {weight=parent=lchild=rchild=0;}
    };

    int size,leaves;
    Node* Tree;
    string* Code;
};

void Huffman::init(Table t[],int n)
{
    _destory();

    leaves = n;size=(n<<1)-1;
    Tree = new Node[size+1];

    Tree[0].weight=2147483647;
    for(int i=1;i<=leaves;++i)
        Tree[i].weight=t[i].wt;

    Code = new string[leaves+1];

    _build();
    _coding();
}

void Huffman::_destory()
{
    leaves=size=0;
    delete[] Tree;
    delete[] Code;
    Tree= nullptr;
    Code= nullptr;
}

// 自底向上构建一棵树，选择最小值的范围
void Huffman::_build()
{
//    建树
    for(int i=leaves+1;i<=size;++i){
        auto [s1,s2]=_select_min(i-1);

        Tree[s1].parent=i;
        Tree[s2].parent=i;

        Tree[i].lchild=s1;
        Tree[i].rchild=s2;

        Tree[i].weight  = Tree[s1].weight + Tree[s2].weight;
    }

}

pii Huffman::_select_min(int end)
{
    int minn=0,mixn=0;
    for(int i=1;i<=end;++i){
        if( Tree[i].weight < Tree[minn].weight && !Tree[i].parent ){
            mixn=minn;
            minn=i;
        }else if( Tree[i].weight < Tree[mixn].weight && !Tree[i].parent ){
            mixn=i;
        }
    }
    return pii(minn,mixn);
}

#define ok 1
#define error -1

void Huffman::_coding()
{
    char *cd = new char[size];
    cd[size-1]=0;
    for(int i=1;i<=leaves;++i){
        int cur=i,par=Tree[cur].parent;
        int start=size-1;

        while( par ){
            if( Tree[par].lchild==cur ) cd[--start]='0';
            else cd[--start]='1';
            cur=par;
            par=Tree[cur].parent;
        }
        Code[i].assign( &cd[start] );
    }
    delete []cd;
}

//输入编码串codestr，输出解码串txtstr
int Huffman::Decode(const string codestr, char txtstr[],char cht[])
{
    int cur=size;
    int k=-1;
    char ch;
    for(int i=0;i<codestr.size();++i){
//    for(int i=codestr.size()-1;i>=0;--i){
        ch=codestr[i];
        if(ch=='0') cur=Tree[cur].lchild;
        else if(ch=='1') cur=Tree[cur].rchild;
        else return error;

        if( !Tree[cur].lchild && !Tree[cur].rchild ){
            txtstr[++k]=cht[cur];
            cur=size;
        }else{
            ch=0;
        }
    }

    if( ch==0 )return error;
    else txtstr[++k]=0;
    return ok;
}


// dsalfjkahqeoiuryzczcnmzxvbalksjfhqwieouyr
// abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ
int main(int argc,char**argv)
{
    int t;
    cin >> t;
    Huffman var;
    while(t--){
        string str;
        cin>>str;
        int tp=0;
        Table::zero(tt,52);
        for(auto it:str){
            if(isupper(it)){
                tt[it-'A'+1].wt++==0?++tp:0;
                tt[it-'A'+1].ch=it;
            }else if(islower(it)){
                tt[it-'a'+27].wt++==0?++tp:0;
                tt[it-'a'+27].ch=it;
            }
        }

//        for(auto it:tt)cout<<it.wt<<' '<<it.ch<<' ';cout<<'\n';
        sort(tt+1,tt+53);
//        for(auto it:tt)cout<<it.wt<<' '<<it.ch<<' ';
        var.init(tt,tp);

        int ans=0;
        for(auto it:str){
            if(isupper(it))
                ans+=var.Code[ Table::getid(it,tt,tp) ].size();
            else if(islower(it))
                ans+=var.Code[ Table::getid(it,tt,tp) ].size();
        }
        cout<<ans<<'\n';
    }

    return 0;
}
