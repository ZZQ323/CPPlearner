#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int x, y;
    // printf("%#X\n",((-1)>>24));
    // printf("%d\n",((-1)>>24)<<1>>1);
    // for(int i=0;i<32;++i){
    //     printf("%d::%#X\n",i,(~0)>>i);
    // }

    // printf("%d\n",-1<<1);
    // printf("%d\n",(-1)<<1>>);

    // printf("%#X\n",INT_MIN>>31);
    // printf("%#X\n",INT_MAX>>31);
    // printf("%#X\n",1<<31);
    // printf("%#X\n",~(1<<31));
    // printf("%d\n",1<<31);
    // printf("%d\n",2147483648);
    // printf("%d\n",2147483648==-2147483648);
    // printf("%#X\n", true);
    // printf("%#X\n", false);
    // printf("%#X\n",2147483647/2+2147483648/2);
    // printf("%d\n",2147483647/2+2147483648/2);

    auto half=[](int n)->int {return (n&(~(1<<30)));};
    auto minus=[](int a,int b)->int {return (a+( (~b) + 1 ));};

    printf("%d\n",-2147483647/2==half(-2147483647));
    // printf("%d\n",3-4==minus(3,4));

    while (~scanf("%d%d", &x, &y))
    {
        // printf("x:%d y:%d\n",x,y);
        // 2147483648,10000000000000 :: x-> 2147483647
        printf("%d\n", (!(!((x >> 31) & 1) & (y >> 31)) & !((x >> 30) & !((y >> 30) & 1))) & !(( ((y&(~(1<<30))) + (~((x&(~(1<<30)))+ 1)) )>>31)&1) );

        // (!(!((x>>31)&1) & (y>>31) ) & !( (x>>30) & !((y>>30)&1) )) | (( !(((y+(~x)+1)>>31)&1) ) >> (( (x>>30) & !((y>>30)&1) ) )) ;
        printf("::%d\n",!(!((x>>31)&1) & (y>>31) ) );
        printf("::%d\n",!( (x>>30) & !((y>>30)&1) ) );
        printf("::%d\n",!(( ((y&(~(1<<30))) + (~( (x&(~(1<<30))))) + 1 )>>31) &1) );
    }

    return 0;
}
// 2147483648