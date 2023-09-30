#include<iostream>

using std::cin;
using std::cout;
using std::endl;

#define error -1
#define ok 0

class Seqlist{
private:
    int* list;
    int size;
    static int maxsize;
public:

    Seqlist(){size=0;list = new int[maxsize];}

    Seqlist(const Seqlist& var){
        size=0;
        list = new int[maxsize];
        for(int i=0;i<var.size;++i)
            list[i]=var.list[i];
    }

    ~Seqlist(){delete[] list;}

    int push_back(int val)
    {
        if( size>=maxsize )
            return  error;
        list[size++]=val;
        return ok;
    }

    // 有序表合并
    friend int merge(Seqlist& itemA,Seqlist& itemB,Seqlist& ret)
    {
        if(itemB.size+itemA.size>maxsize)
            return error;
        int i=0,j=0,k=0;
        ret.size=itemB.size+itemA.size;
        while( i<itemA.size &&  j<itemB.size )
        {
            if( itemA.list[i] < itemB.list[j] )
                ret.list[k++]=itemA.list[i++];
            else
                ret.list[k++]=itemB.list[j++];
        }
        while( i<itemA.size)
            ret.list[k++]=itemA.list[i++];
        while( j<itemB.size)
            ret.list[k++]=itemB.list[j++];

        return ok;
    }

    int list_size(){return size;}

    void display()
    {
        for(int i=0;i<size;++i)
        {
            cout<<list[i]<<' ';
        }
    }

};
int Seqlist::maxsize=1000;


int main(int argc,char** argv)
{
    // std::ios::sync_with_stdio(false);

    int n;

    cin>>n;
    Seqlist var1;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        var1.push_back(x);
    }

    cin>>n;
    Seqlist var2;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        var2.push_back(x);
    }

    Seqlist ans;
    merge(var1,var2,ans);
    cout<<ans.list_size()<<' ';
    ans.display();
    cout<<endl;

    return 0;
}