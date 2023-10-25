#include<iostream>

using namespace std;

const int Maxlen=1000;

struct static_queue{
    int front,back,len;
    int *data;

    static_queue(size_t l,int a[]=nullptr)
    :len(l),data(nullptr)
    {
        data=new int[l];
        front=back=0;
    }

    bool empty()
    {}

    bool full()
    {}
};

int main(void)
{

    return 0;
}