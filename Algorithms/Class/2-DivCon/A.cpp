#include<iostream>

using namespace std;

int n;

void Hannoi(const char&a,const char&b,const char&c,int len)
{
    if(len>0){
        Hannoi(a,c,b,len-1);
        printf("Move disk %d from %c to %c\n",len,a,c);
        Hannoi(b,a,c,len-1);
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    Hannoi('A','B','C',n);
    return 0;
}
