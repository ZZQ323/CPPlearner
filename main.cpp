#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=110;
int M[N][N];

int n,m;
bool flag;

void print();

void UP(int x,int y)
{  
    auto clean=[](int col)-> void {
        int l=1,r=1;
        while(true){
            while(r<=n && M[r][col])++r;
            l=r;
            while(l<=n && !M[l][col])++l;
            if(l==n+1 || r==n+1)break;
            swap(M[l][col],M[r][col]);
        }
    };

    for(int i=1;i<=n;++i){
        clean(i);
        for(int j=1;j<n;++j){
            if(M[j][i]==M[j+1][i]){
                M[j][i]+=M[j+1][i];
                M[j+1][i]=0;
                if(M[j][i]==2048){
                    flag=1;
                }
            }
        }
        clean(i);
    }

    if(!M[x][y])
        M[x][y]=2;
    
}

void DOWN(int x,int y)
{
    auto clean=[](int col)-> void {
        int l=n,r=n;
        while(true){
            while(r && M[r][col])--r;
            l=r;
            while(l && !M[l][col])--l;
            if( !l ||  !r)break;
            swap(M[l][col],M[r][col]);
        }
    };

    for(int i=1;i<=n;++i){
        clean(i);
        for(int j=n-1;j;--j){
            if(M[j+1][i]==M[j][i]){
                M[j+1][i]+=M[j][i];
                M[j][i]=0;
                if(M[j+1][i]==2048){
                    flag=1;
                }
            }
        }
        clean(i);
    }

    if(!M[x][y])
        M[x][y]=2;
}

void LEFT(int x,int y)
{
    auto clean=[](int row)-> void {
        int l=1,r=1;
        while(true){
            while(r<=n && M[row][r])++r;
            l=r;
            while(l<=n && !M[row][l])++l;
            if( l==n+1 ||  r==n+1)break;
            swap(M[row][l],M[row][r]);
        }
    };

    for(int i=1;i<=n;++i){
        clean(i);
        for(int j=1;j<n;++j){
            if(M[i][j]==M[i][j+1]){
                M[i][j]+=M[i][j+1];
                M[i][j+1]=0;
                if( M[i][j]==2048 ){
                    flag=1;
                }
            }
        }
        clean(i);
    }

    if(!M[x][y])
        M[x][y]=2;
}

void RIGHT(int x,int y)
{
    auto clean=[](int row)-> void {
        int l=n,r=n;
        while(true){
            while(r && M[row][r])--r;
            l=r;
            while(l && !M[row][l])--l;
            if( !l || !r)break;
            swap(M[row][l],M[row][r]);
        }
    };

    for(int i=1;i<=n;++i){
        clean(i);
        for(int j=n-1;j;--j){
            if(M[i][j+1]==M[i][j]){
                M[i][j+1]+=M[i][j];
                M[i][j]=0;
                if(M[i][j+1]==2048){
                    flag=1;
                }
            }
        }
        clean(i);
    }

    if(!M[x][y])
        M[x][y]=2;
}

void print()
{
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            printf(" %d"+(j==1),M[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            scanf("%d",M[i]+j);
        }
    }

    while(m--){
        char op;
        int x,y;
        scanf("\n%c",&op);
        scanf("%d%d",&x,&y);
        // printf("%c %d %d\n",op,x,y);

        switch (op){
        case 'U':
            UP(x,y);
            break;
        case 'D':
            DOWN(x,y);
            break;
        case 'L':
            LEFT(x,y);
            break;
        case 'R':
            RIGHT(x,y);
            break;
        }

        // puts("-------------------");
        // print();
        // puts("-------------------");

        if(flag){
            puts("Yes");
            print();
            break;
        }
    }

    if(!flag){
        puts("No");
        print();
    }

    return 0;
}


/*
4 100
0 0 2 4
4 4 8 4
8 8 2 4
2 2 2 2
U 4 2
D 1 1
L 3 3
*/
