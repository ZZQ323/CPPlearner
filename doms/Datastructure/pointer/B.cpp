#include<iostream>
#include<iostream>

using namespace std;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        int id;
        int offset=(id-((n+1)>>1));
        scanf("%d",&n);
        int arr[n+1];
        for(int i=1;i<=n;++i)
        {
            scanf("%d",arr+i);
        }
        int* p=arr+((n+1)>>1)+!(n&1);
        --p;
        printf("%d ",*p);
        ++p;
        ++p;
        printf("%d\n",*p);
        --p;
        scanf("%d",&id);
        offset=id-(((n+1)>>1)+!(n&1));
        printf("%d\n",*(p+offset));
    }
    return 0;
}