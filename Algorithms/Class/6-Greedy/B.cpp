#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int N;
int val[]={0,100,50,20,10,5,2,1};
int record[8];

int main(int argc, char const *argv[])
{
	while(scanf("%d",&N)!=EOF){
		memset(record,0,sizeof(record));
		int cnt=0;
		int n=N;
		for(int i=1;i<=7;++i){
			if(val[i]>n)continue;
			cnt += n/val[i];
			record[i] = n/val[i];
			n%=val[i];
		}
		printf("%d ",cnt);
		bool flag=1;
		for(int i=1;i<=7;++i){
			if( record[i] ){
				printf("+%d"+flag,val[i]);
				if( record[i]>1 ){
					printf("*%d",record[i]);
				}
				flag = 0;
			}
		}
		printf("=%d\n",N);
	}
	return 0;
}
