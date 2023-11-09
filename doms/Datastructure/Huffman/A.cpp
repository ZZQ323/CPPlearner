#include<iostream>
#include<string>
#include<map>

using namespace std;

typedef pair<int ,int > pii;

const int N=1e5+100;

class Huffman{
private:

    pii _select_min(int end);
    void _build();
    void coding();
    void _destory();

public:

    void _init(int wt[],int n);

    Huffman(){
        size=leaves=0;
        Tree= nullptr;
        Code= nullptr;
    }

    ~Huffman()
    {
        _destory();
    }

    int Decode(const string codestr, char txtstr[]);

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

void Huffman::_init(int wt[],int n)
{
    _destory();
    leaves = n;
    size=(n<<1)-1;
    Tree = new Node[size+1];
    Code = new string[leaves+1]{""};
    Tree[0].weight=2147483647;
    for(int i=1;i<=leaves;++i)
        Tree[i].weight=wt[i];
    _build();
    coding();
}

void Huffman::_destory()
{
    leaves=size=0;
    delete[] Tree;
    delete[] Code;
}

// 自底向上构建一棵树，选择最小值的范围
void Huffman::_build()
{
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

void Huffman::coding()
{
    char *cd = new char[size];
    cd[size-1]=0;
    for(int i=1;i<=leaves;++i){
        int cur=i,par=Tree[cur].parent;
        int start=leaves-1;

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

#define ok 1
#define error -1

int wt[N];
char cht[N];
//输入编码串codestr，输出解码串txtstr
int Huffman::Decode(const string codestr, char txtstr[])
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


int main(int argc,char**argv)
{
    int t;
    cin >> t;
    Huffman var;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>wt[i];
        }
        var._init(wt,n);

        for(int i=1;i<=n;++i){
            cin>>cht[i];
        }

        string coding;
        int k;
        cin>>k;
        while(k--){
            cin>>coding;
            static char str[N];
            if( ~var.Decode(coding,str) ){
                cout<<str<<'\n';
            }else{
                cout<<"error\n";
            }
        }
    }

    return 0;
}

/**********************************************************************
	Problem: 1051
	User: 202200202104
	Language: C++
	Result: AC
	Time:20 ms
	Memory:2812 kb
**********************************************************************/

