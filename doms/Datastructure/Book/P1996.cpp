#include<iostream>
#include<list>

using namespace std;

int main(void )
{
    list<int> ls;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        ls.push_back(i);
    list<int>::iterator it=ls.begin();
    for(int i=0;n=ls.size();){
        int j=(i+m-1)%n;
        advance(it,j-i);
        printf("%d ",*it);
        it=ls.erase(it);
        i=j;
    }   

    return 0;
}