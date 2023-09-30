#include<iostream>
#include<iterator>
#include<algorithm>
#include<list>
#include<cmath>

using namespace std;

class List : public list<int> {
public:
    int& operator[](int index) {
        if (index < 0 || index >= size()) {
            throw std::out_of_range("Index out of range");
        }
        auto it = begin();
        std::advance(it, index);
        return *it;
    }
};

int main(int argc,char**argv)
{
    int T;
    scanf("%d",&T);

    while(T--){
        int n,k,s;
        scanf("%d%d%d",&n,&k,&s);

        List le;
        for(int i=1;i<=n;++i)
            le.push_back(i);
        for(int i=s-1+k-1; n=le.size() ;i+=k-1){
            i%=n;
            printf("%d ",le[i]);
            auto it = le.begin();
            std::advance(it, i);
            le.erase(it);                               
        }
        putchar('\n');
    }
    return 0;
}