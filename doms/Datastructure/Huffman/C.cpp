#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

const int N=1e5+100;

template<class U>
struct Node{
    Node*nex;
    U info;

    Node(U i=U())
    :info(i){nex=nullptr;}

    static int getid(Node<U> p[],int n,char tar)
    {
        for(int i=0;i<n;++i){
            if( p[i].info.name==tar ){
                return i;
            }
        }
        return -2147483648;
    }

};

struct info{
    char name;
    int val;

    info(char n=0,int d=0)
    :name(n),val(d){}
};

Node<info> header[N];

int main(int argc,char**argv)
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;++i){
            cin>>header[i].info.name;
        }

        for(int i=0;i<m;++i){
            char temp,etemp;
            cin>>temp>>etemp;
            for(int j=0;j<n;++j){
                if(header[j].info.name==temp){
                    Node<info>*now= &header[j];
                    while( now->nex ){
                        now=now->nex;
                    }
                    now->nex=new Node<info>(etemp);
                    break;
                }
            }

        }
        for(int i=0;i<n;++i){
            printf("%d %c",i,header[i].info.name);
            Node<info>*  now=header[i].nex;
            while( now ){
                printf("-%d",Node<info>::
                        getid(header,n,now->info.name));
                now=now->nex;
            }
            printf("-^\n");
        }
    }
    return 0;
}