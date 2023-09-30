#include<bits/stdc++.h>

using namespace std;

#define ll long long 


int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);

		auto check1=[](int num)-> bool {
			for(int i=2;1ll*i*i<=num;++i)
			{
				if(num%i==0)
					return false;
			}
			return true;
		};

		auto check2=[](int num)-> bool {
			for(int i=2; i<=num ;++i)
			{
				if(num%i==0){
					while(num%i==0)
						num/=i;
					break;
				}
			}
			return num>1;
		};


		if(n>4 && !check1(n) && check2(n) )puts("Yes");
		else puts("No");
	}
	return 0;
}