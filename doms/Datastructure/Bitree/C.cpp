#include<iostream>
#include<stack>
#include<vector>

using namespace std;

const int N=1e5+100;
char str[N];

struct Bitree{

    struct Node{
        char val;
        Node *lchild,*rchild;

        Node(char v)
        :val(v),lchild(nullptr),rchild(nullptr)
        {;}

    }*head;

    void init(Node*&now ,char* &s)
    {
        if(*s!='0'){
            now=new Node(*s);
            init(now->lchild,++s);
            init(now->rchild,++s);
        }
    }

    Bitree(char* s)
    :head(nullptr){;init(head,s);}

    void del(Node*now)
    {
        if(now){
            del(now->lchild);
            del(now->rchild);
            delete now;
        }
    }

    ~Bitree(){
        del(head);
        head=nullptr;
    }

};

int main(int argc,char**argv)
{
    int t;
    scanf("%d",&t);
    vector<char> ve;
    ve.resize(N);
    while(t--){
        ve.clear();
        scanf("%s",str);
        stack<Bitree::Node*>st;
        Bitree var(str);
        Bitree::Node*root=var.head;
        while(st.size() || root!=nullptr){
            while(root){
                st.push(root);
                if(root->lchild)
                    root=root->lchild;
                else 
                    root=root->rchild;
            }
            ve.push_back((root=st.top())->val);
            st.pop();
            if( st.size() && st.top()->lchild==root)
                root=root->rchild;
            else 
                root=nullptr;
        }
        for(auto it : ve)
            cout<<it;
        cout<<'\n';
    }

    // system("pause");

    return 0;
}