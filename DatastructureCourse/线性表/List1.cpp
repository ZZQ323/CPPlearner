#include<iostream>

struct Node{
	int data;
	Node* nex;
	void init(int d=0){nex=nullptr;data=d;}
	Node(int d=0){init(d);}
};

// 找到第y个
Node* Find(Node*h,int y)
{
	while( h->nex  && y )
	{
		--y;
		h=h->nex;
	}

	return  (y?h:nullptr);
}

// 头部插入
void Add_head(Node*h,int v)
{
	Node*temp=new Node(v);
	temp->nex=h->nex;
	h->nex=temp;
}

// 尾部插入
void Add_Rear(Node*h,int v)
{
	while(h->nex)h=h->nex;

	h->nex = new Node(v);
}

// 插入操作的核心，优先处理插入位置节点的next指针
int Insert(Node*h,int v,int y)
{
	Node* index=Find(h,y);
	if( !index ){
		// 如果没有找到的话，插入到尾部
		Add_Rear(h,v);
		// 幽闭问题，返回错误信号
		return -1;
	}

	Node* nx=new Node();
	nx->nex=index->nex;
	index->nex=nx;
	return 0;
}

// 单个删除
int Del(Node* h,int y)
{
	Node* pre=Find(h,y-1);
	Node* now=Find(h,y);
	// 用谁，临时指针就存谁
	if( !now ){
		return -1;
	}
	pre->nex=now->nex;
	delete now;
	return 0;
}

int main(void)
{
	// 在大多数情况下，指针内部表示是无符号的，因为指针通常用于表示内存地址，而内存地址本质上是非负数
	Node*p=(Node*)-1;
	printf("%d\n",p);

	// 循环链表 
	// 防止套圈，nex是不是head
	// 头节点head ，尾节点rear
	// 头节点 rear.nex.nex

	

	return 0;
}