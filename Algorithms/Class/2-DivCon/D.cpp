#include<iostream>

using namespace std;

using ll=long long ;
constexpr int mod = 1e9+7;

/*
[
    1 1
    1 0
]

[
    Fn   Fn-2
    Fn-1 Fn-3
]

*/

struct Matrix{
    int data[2][2]={
        {3,1,},
        {2,1}
    };

    Matrix(){
        ;
    }

    Matrix& operator*=(Matrix var){
        Matrix tmp;
        for(int i=0;i<2;++i){
            for(int j=0;j<2;++j){
                int ret=0;
                for(int k=0;k<2;++k){
                    ret=(ret+1ll*var[i][k]*data[k][j]%mod)%mod;
                }
                tmp[i][j]=ret;
            }
        }
        *this=tmp;
        return *this;
    }

    int* operator[](int i){return data[i];}

};

Matrix qpow(Matrix& a,int n,const int mod)
{
    Matrix ret;

    while(n){
        if( n&1 )
            ret*=a;
        a*=a;
        n>>=1;
    }return ret;
}

int main(int argc, char const *argv[])
{
    int n;
    while(~scanf("%d",&n)){
        if( n<=4){
            int a[]={0,1,1,2,3};
            printf("%d\n",a[n]);
        }else{
            Matrix one;
            one[0][0]=1;
            one[0][1]=1;
            one[1][0]=1;
            one[1][1]=0;
            printf("%d\n",qpow(one,n-4,mod).data[0][0]);
        }
    }
    return 0;
}
