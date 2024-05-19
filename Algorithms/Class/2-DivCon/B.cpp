#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int maxn = 1e5 + 10;
int a[maxn], mergeTemp[maxn], n;

int MergeSort(int l, int r)
{
    // TODO: 统计数组 a 上 [left, right] 区间的逆序对个数
    if( r-l+1<=1){
        return 0;
    }
    int mid=l+r>>1;
    int ret=0;
    ret+=MergeSort(l,mid);
    ret+=MergeSort(mid+1,r);
    int i=l-1,j=mid,k=0;
    while(i<mid && j<r){
        if(a[i+1]<=a[j+1]){
            mergeTemp[++k]=a[++i];
        }else{
            ret+=mid-i;
            mergeTemp[++k]=a[++j];
        }
    }
    while(i<mid)
        mergeTemp[++k]=a[++i];
    while(j<r)
        mergeTemp[++k]=a[++j];
    for(int i=l,j=1;i<=r;++i,++j){
        a[i]=mergeTemp[j];
    }
    return ret;
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        printf("%d\n", MergeSort(1, n));
    }
    return 0;
}