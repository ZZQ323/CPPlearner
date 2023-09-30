#include<iostream>

const int maxsize=100;

struct SLNode
{
	int value;
	int nex;	
}slist[maxsize];

void InitspaceSL(SLNode s[])
{
	for(int i=1;i<maxsize;++i)
		s[i].nex=i+1;
	s[maxsize-1].nex=0;
}

// 头删法，取走节点
int MallocSL(SLNode s[])
{
	//s[0] is head
	int temp=s[0].nex;
	if(!temp)return -1;

	s[0].nex=s[temp].nex;
	return temp;
}

// 头插法，返回（删除别的地方的）节点
void RecallSL(SLNode s[],int k)
{
	s[k].nex=s[0].nex;
	s[0].nex=k;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int temp;
		scanf("%d",&temp);
		
	}
	return 0;
}