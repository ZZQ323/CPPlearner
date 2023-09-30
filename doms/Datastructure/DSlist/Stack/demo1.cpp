// list是循环双向链表

#include<iostream>
#include<iterator>
#include<algorithm>
#include<list>
#include<cmath>

using namespace std;

int main(int argc,char**argv)
{
    int T;
    scanf("%d",&T);

    while(T--){
        int n,k,s;
        scanf("%d%d%d",&n,&k,&s);

        list<int> le;
        for(int i=1;i<=n;++i)
            le.push_back(i);
        
        for(int i=k+s-1;le.size();i+=k-1){
            if(i>n)i%=n;
            list<int>::iterator it=find(le.begin(),le.end(),i);
            printf("%d ",*it);
            le.erase(it++);
        }
        putchar('\n');
    }
    return 0;
}