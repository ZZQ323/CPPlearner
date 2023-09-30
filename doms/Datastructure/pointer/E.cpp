#include<iostream>
#include<typeinfo>
#include<cfloat>

int main(void)
{
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
        char op;
        scanf("%c",&op);

        int n;
        scanf("%d\n",&n);
        
        if(op=='F'){
            double *arr=new double[n];
            for(int i=0;i<n;++i)
            {
                scanf("%lf",arr+i);
            }
            double maxn=__DBL_MAX__;
            for(int i=0;i<n;++i)
            {
                maxn=(maxn>arr[i]?arr[i]:maxn);
            }
            printf("%G\n",maxn);
            delete arr;
        }else if(op=='I'){
            int *arr=new int[n];
            int sum=0;
            for(int i=0;i<n;++i)
            {
                scanf("%d",arr+i);
                sum+=arr[i];
            }
            printf("%d\n",sum/n);
            delete arr;
        }else{
            char *arr=new char[n];
            for(int i=0;i<n;++i)
            {
                scanf("%c",arr+i);
                if(i!=n-1)
                    getchar();
            }
            char maxn=0;
            for(int i=0;i<n;++i)
            {
                maxn=(maxn<arr[i]?arr[i]:maxn);
            }
            printf("%c\n",maxn);
            delete arr;
        }
        if(t)
            getchar();
    }
    return 0;
}