#include<iostream>
#include<cstring>

using namespace std;

const int N=1e3+100;
int g[N][N];
bool vis[N];
int n;

void DFS(int cur)
{
    vis[cur]=1;
    printf("%d ",cur);
    for(int i=0;i<n;++i){
        if( !vis[i] && g[cur][i] ){
            DFS(i);
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
                DFS(i);
            }
        }

        putchar('\n');
    }

    // system("pause");

    return 0;
}