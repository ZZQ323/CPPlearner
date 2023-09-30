#include<bits/stdc++.h>

using namespace std;

const int N=2e5+100;
int P[N];

int main(void)
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",P+i);

	int con=1;	
	for(int i=1;i<=n;)
	{
		int j=i+1;
		while(j<=n && P[j-1]<P[j]) ++j;
		con=max(con,j-i);
		i=j;
	}
	// printf("con::%d\n",con);
	if(con<k)
		sort(P+n+1-k,P+1+n,less<int>() );

	for(int i=1;i<=n;++i)
		printf("%d ",P[i]);
	
	return 0;
}