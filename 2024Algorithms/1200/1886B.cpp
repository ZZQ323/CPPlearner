#include<iostream>
#include<cmath>

using namespace std;

/**
 * 简单计算几何：两个灯，
 *  要么是离着OP很近，一个罩着
 *  要么是分别离一个灯很近，一个灯罩着
 *  要么是和灯平行，都挺远的
 * 为什么有答案给二分？
 *  这种题确实可以用二分三分搜出来，但是有更好的办法
 * 
*/

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d",&t);
    while( t-- ){
        int px,py,ax,ay,bx,by;
        scanf("%d%d%d%d%d%d",&px,&py,&ax,&ay,&bx,&by);
        double w,a1=0,a2=0,b1=0,b2=0;
        a1=(1.0*(ax-0)*(ax-0)+(ay-0)*(ay-0));
        a2=(1.0*(ax-px)*(ax-px)+(ay-py)*(ay-py));

        b1=(1.0*(bx-0)*(bx-0)+(by-0)*(by-0));
        b2=(1.0*(bx-px)*(bx-px)+(by-py)*(by-py));

        if( a1<b1 && a2<b2 ){
            w=max(a1,a2);
        }else if( a1>b1 && a2>b2 ){
            w=max(b1,b2);
        }else{
            w=(1.0*(bx-ax)*(bx-ax)+(by-ay)*(by-ay))/4;
            w=max(w,min(b2,a2));
            w=max(w,min(b1,a1));
        }
        w=sqrt(w);
        printf("%.10f\n",w);
    }
    return 0;
}
