#include <iostream>
#include <cmath>
#include <forward_list>

using namespace std;

int foo(int x)
{
    return 1>>((( (x & ((~x)+1) & (~(1<<31)))  | (x>>31)&1 )<<1)-1);
}

int main()
{
    // printf("%d\n",1>>32);
    // printf("%d\n",(2147483616 & (-2147483616)));
    // printf("%d\n",(2147483616 & ((~2147483616)+1) & (~(1<<31)) ) );
    // printf("%d\n",foo(2147483616) );
    // printf("%#X\n",2147483616);
    int x;
    scanf("%d",&x);
    printf("%d\n",(x)&((-x)<<1));


    // for(int i=INT_MIN;i<INT_MAX;++i){
    //     if( (i & (-i))==0  ){
    //         printf("%d\n",i);
    //     }
    // }

    system("pause");

    return 0;
}