#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int N=1e3+100;
int g[N][N];
bool vis[N];
int n;

void BFS(int s)
{
    queue<int>qe;
    qe.push(s);
    vis[s]=1;
    while(qe.size()){
        auto now=qe.front();
        qe.pop();
        printf("%d ", now );
        for(int i=0;i<n;++i){
            if( !vis[i] && g[now][i] ){
                vis[i]=1;
                qe.push(i);
            }
        }
    }
}

int main(int argc,char*argv[])
{
    int t;
    cin>>t;
    while(t--){
        memset(g,0,sizeof(g));
        memset(vis,0,sizeof(vis));

        cin>>n;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cin>>g[i][j];     
            }
        }

        for(int i=0;i<n;++i){
            if( !vis[i] ){
                BFS(i);
            }
        }

        putchar('\n');
    }

    // system("pause");

    return 0;
}