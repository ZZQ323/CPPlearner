#include<iostream>

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int** p=new int* [2];
        for(int i=0;i<2;++i){
            p[i]=new int [3];
            for(int j=0;j<3;++j)
                scanf("%d",(*(p+i)+j));
        }
        for(int j=2;j>=0;--j){
            for(int i=0;i<2;++i)
                printf("%d ",*(*(p+i)+j));
            if(j)putchar('\n');
        }
        if(t)putchar('\n');

        for(int i=0;i<3;++i)
            delete[] p[i];
        delete[] p;
    }
    
    return 0;
}