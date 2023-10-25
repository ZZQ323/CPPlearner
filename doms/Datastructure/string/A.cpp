#include<iostream>
#include<queue>

using namespace std;

int main(int argc,char**argv)
{
    int n;
    scanf("%d\n",&n);
    queue<char>qe;
    for(int i=1;i<=n;++i){
        qe.push(getchar());
        getchar();
    }

    int sumA=0,sumB=0,sumC=0;
    int cntA=0,cntB=0,cntC=0;
    for(int i=1;i<=n;++i){
        int val;
        scanf("%d",&val);
        if(qe.front() == 'A'){
            sumA+=val;
            cntA++;
        }else if(qe.front()=='B'){
            sumB+=val;
            cntB++;
        }else {
            sumC+=val;
            cntC++;
        }
        qe.pop();
    }
    printf("%d\n%d\n%d",sumA/cntA,sumB/cntB,sumC/cntC);


    return 0;
}