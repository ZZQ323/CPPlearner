#include<cstdio>
#include<cstring>
#include<stack>
#include<cstddef>
#include<cstdlib>

using namespace std;

struct Node{
    int parent;
    int lson;
    int rson;
    int w;

    void init_(){
        parent=lson=rson=-1;
    }

    Node(){init_();}
};

#define lson(x) (tree[x].lson)
#define rson(x) (tree[x].rson)
#define parent(x) (tree[x].parent)

class HuffmanTree{
    using type=int;
    using pointer=int*;
    using Node_Base=Node;
    using Node_Base_pointer=Node*;
public:
    size_t size;
private:
    Node_Base_pointer tree;
    char** huffCode;
private:
    void getMaxTwo_(int end,int& Maxnid,int& secMaxnid){
        for(int i=1;i<=end;++i){
            if( tree[i].parent!=-1 )continue;
            if( tree[i].w > tree[Maxnid].w ){
                secMaxnid=Maxnid;
                Maxnid=i;
            }else if( tree[i].w > tree[secMaxnid].w ){
                secMaxnid=i;
            }
        }
    }
    void init_(int num){
        for(int i=num+1;i<=size;++i){
            int firid=i-1,secid=i-1;
            // 找到最大值和次大值
            getMaxTwo_(num-1,firid,secid);
            // 认爹
            tree[firid].parent=i;
            tree[secid].parent=i;
            // 初始化所有除了parent的字段
            tree[i].lson=secid;
            tree[i].rson=firid;
            tree[i].w=tree[firid].w+tree[secid].w;
        }
        // 先序遍历初始化huffCode
        stack<int>state;
        char* buff=new char[size];int ed=-1;
        for(int now=size; state.size() || now!=-1 ;){
            if( now!=-1 ){
                buff[++ed]='0';
                if( lson(now)==-1 && rson(now)==-1 ){
                    sprintf(buff+1,"%s",huffCode[now]);
                }
                state.push(now);
                now=tree[now].lson;
            }else if( state.size() ){
                now=state.top();state.pop();
                now=tree[now].rson;
                buff[--ed]='1';
            }
        }
    }

public:
    void Coding(int iter_bein[],int iter_end[],char buff[],int n=0x7fffffff){
        buff[0]=0;
        for(int i=0;iter_bein+i != iter_end;++i){
            sprintf(huffCode[iter_bein[i]],"%s",buff+strlen(buff));
            if( strlen(buff)>n )exit(1);
        }
    }

    void Decoding(char input[],char buff[]){
        buff[0]=0;
        int root=size;
        // huffman是完全二叉树，要么2度，要么没有
        for(int i=0;i<strlen(input);++i){
            if(input[i]=='0'){
                root=lson(root);
                if(lson(root)==-1){
                    sprintf(huffCode[root],"%s",buff+strlen(buff));
                    root=size;
                }
            }else if(input[i]=='1'){
                root=rson(root);
                if(lson(root)==-1){
                    sprintf(huffCode[root],"%s",buff+strlen(buff));
                    root=size;
                }
            }else{
                exit(1);
            }
        }
    }

    HuffmanTree(int n,int wt[]){
        size=(n<<1);
        tree=new Node_Base[size];
        huffCode=new char*[n+1];
        for(int i=1;i<=n;++i)
            tree[i].w=wt[i];
        init_(n);
    }
};

const int N=1e5+100;
int wt[N];

int main(void)
{
    int t;
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d",wt+i);
        }
        HuffmanTree hf(n,wt);
        
    }
    
    return 0;
}