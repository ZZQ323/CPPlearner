#include<iostream>
#include<algorithm>

using namespace std;

constexpr int N=40;
using array1d_t = int[N];
using array2d_t = int[N][N];

int n,b;
array2d_t var;

inline int lowbit(int x){return x&(-x);}

inline int log(int a,int b=2)
{
    int ret=0;
    while( a>>=1 )ret++;
    return ret;
}

auto print1darray = [](array1d_t a,int n)-> void {
	for(int i=1;i<=n;++i){
		printf(" %d"+(i==1),var[i]);
	}putchar('\n');
};

auto print2darray = [](array2d_t a,int n)-> void {
	for(int i=1;i<=n;++i){
		for(int j=2;j<=n;++j){
			printf(" %d"+(j==2),var[i][j]);
		}putchar('\n');
	}
};

void brute(int x,int y,int len,int dep ,int cur)
{
	if( dep < 0  ){
		var[x][y]=cur+1;
		return ;
	}
	brute(x,y,len>>1,dep-1,cur | 0);
	brute(x-len,y-len,len>>1,dep-1,cur | 0);
	brute(x,y-len,len>>1,dep-1, cur | (1<<dep) );
	brute(x-len,y,len>>1,dep-1, cur | (1<<dep) );
}

int main(int argc, char const *argv[])
{
	// printf("%d",8&(-8));
	scanf("%d",&n);
	b=log(n);
	brute(n,n,n/2,log(n)-1,0);
	print2darray(var,n);
	return 0;
}


/*

1 2 3 4 5 6 7 8
2 1 4 3 6 5 8 7
3 4 1 2 7 8 5 6
4 3 2 1 8 7 6 5
5 6 7 8 1 2 3 4
6 5 8 7 2 1 4 3
7 8 5 6 3 4 1 2
8 7 6 5 4 3 2 1

*/