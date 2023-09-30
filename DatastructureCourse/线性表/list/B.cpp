#include<iostream>

using namespace std;

#define ok 0
#define error -1

struct Seqlist{
    int* list;
    int size;
    static int maxsize;
    Seqlist(){
        size=0;
        list=new int[maxsize];   
    }
    ~Seqlist(){delete[] list;size=0;}

    int push_back(int val){
        if(size>=maxsize)return error;
        list[size++]=val;
        return ok;
    }

    int multiinsert(int x, int n, int item[])
    {
        if( size+n > maxsize || x<0 || x>size  )
            return error;
        for(int i=size-1;i>=x;--i){
            list[i+n]=list[i];
        }
        for(int i=x;i<x+n;++i){
            list[i]=item[i-x];
        }
        size+=n;
        return ok;
    }

    int multidel(int x, int n)
    {
        if( size < n  || x<0 || x>size  )
            return error;
        for(int i=x+n;i<size;++i){
            list[i-n]=list[i];
        }
        size-=n;
        return ok;
    }

    void display()
    {
        for(int i=0;i<size;++i)
        {
            cout<<list[i]<<' ';
        }
    }
    int list_size(){return size;}
};
int Seqlist::maxsize=1000;




int main(int argc,char** argv)
{
    Seqlist var;
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int x;cin>>x;
        var.push_back(x);
    }
    cout<<var.list_size()<<' ';
    var.display();
    cout<<'\n';

    int x,k;
    cin>>x>>k;
    int *item=new int[k];
    for(int i=0;i<k;++i)
        cin>>item[i];

    var.multiinsert(x-1,k,item);
    cout<<var.list_size()<<' ';
    var.display();
    cout<<'\n';

    cin>>x>>k;
    var.multidel(x-1,k);
    cout<<var.list_size()<<' ';
    var.display();
    cout<<'\n';


    return 0;
}