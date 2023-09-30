#include<iostream>
#include<iterator>
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
        for(int i=1;i<=n;++i)le.push_back(i);

        list<int>::iterator it=le.begin();
        // 第一个人
        int cnt=s-1+k-1;
        while(cnt--){
            ++it;
            if(it==le.end())++it;
        }
        printf("%d ",*it);
        le.erase(it++);
        if(it==le.end())++it;

        // 之后的所有人
        while( le.size() ){
            cnt=k-1;
            while(cnt--){
                ++it;
                if(it==le.end())++it;
            }
            printf("%d ",*it);
            le.erase(it++);
            if(it==le.end())++it;
        }
        putchar('\n');
    }
    return 0;
}