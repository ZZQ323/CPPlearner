#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

// 高精度的位数
const int MAXN=1e5;
//分块读取，分块的大小
const int siz=8;
//MOD=10^siz
const long long MOD=1e8;

char ch1[MAXN],ch2[MAXN];
//0为非负，1为负,f1是第一个数，f2是第二个数，f是最终结果正负
bool f1,f2,f;
long long n;
long long a[MAXN>>2],b[MAXN>>2],s[MAXN>>2];
long long cp[MAXN>>2],lt[MAXN>>2],wsd[MAXN>>2];

//输出高精度数
void write(long long num[]);

//数组重置
void clear(long long num[]);

//>>右移一位
void r1b(long long num[]);

//<<左移一位
void l1b(long long num[]);

//num1=num2
void cpy(long long num1[],long long num2[]);

//比较 num1 and num2
int cmp(long long num1[],long long num2[]);

//plus加法
void plus(long long a[],long long b[]);

//minus减法
void minus(long long a[],long long b[]);

//multiply乘法
void multiply(long long a[],long long b[]);

//divided除法
void divide(long long a[],long long b[]);

void write(long long num[])
{
	if(f) putchar('-'),f=0;
	printf("%lld",num[num[0]]);//输出长度
	for(int i=num[0]-1;i;--i) printf("%08lld",num[i]);
	puts("");
}

void clear(long long num[])
{
	for(int i=num[0];i;--i) num[i]=0;
	num[0]=1;
}

void r1b(long long num[])
{
	for(int i=num[0];i;--i){
		//将1借到下一位
		if((num[i]&1)&&i>1) num[i-1]+=MOD;
		num[i]>>=1;
	}if(!num[num[0]]&&num[0]>1) --num[0];
}

void l1b(long long num[])
{
	++num[0];
	for(int i=1;i<=num[0];++i){
		num[i]<<=1;
		//进位，注意后效性
		if(num[i-1]>=MOD) num[i-1]-=MOD,++num[i];
	}if(!num[num[0]]&&num[0]>1) --num[0];
	return;
}

void cpy(long long num1[],long long num2[])
{
	for(int i=num1[0];i>num2[0];--i) num1[i]=0;
	for(int i=0;i<=num2[0];++i) num1[i]=num2[i];
}

int cmp(long long num1[],long long num2[])
{
	if(num1[0]>num2[0]) return 1;
	if(num1[0]<num2[0]) return -1;
	for(int i=num1[0];i;--i){
		if(num1[i]>num2[i]) return 1;
		if(num1[i]<num2[i]) return -1;
	}return 0;
}

void init()
{
	scanf("%s%s",ch1,ch2);
	if(ch1[0]=='-') ch1[0]='0',f1=1;
	if(ch2[0]=='-') ch2[0]='0',f2=1;//符号处理
	int l1=strlen(ch1),l2=strlen(ch2);
	for(int i=l1-1;i>=f1;i-=siz){
		long long pw=1;++a[0];
		for(int j=i;j>i-siz&&j>=0;--j){
			a[a[0]]+=(ch1[j]^48)*pw;
			pw=(pw<<3)+(pw<<1);
		}
	}for(int i=l2-1;i>=f2;i-=siz){
		long long pw=1;++b[0];
		for(int j=i;j>i-siz&&j>=0;--j){
			b[b[0]]+=(ch2[j]^48)*pw;
			pw=(pw<<3)+(pw<<1);
		}
	}l1-=f1,l2-=f2;
    return;//反序读入存储
}

void plus(long long a[],long long b[])
{
	// 操作过程中改变符号，操作完成后不改变符号
	if(f1^f2){
		// a+b=b-(-a)
		if(f1) f1^=1,minus(b,a),f1^=1;
		// a+b=a-(-b)
		if(f2) f2^=1,minus(a,b),f2^=1;
		return;
	}if(f1&f2){
		// 两个负数绝对值相加，符号为负
		f1=f2=0,f^=1,plus(a,b);
		f1=f2=1;return;
	}clear(s);
	//计算长度
	s[0]=max(a[0],b[0])+1;
	// 一定都得是正数
	for(int i=1;i<=s[0];++i){
		s[i]+=a[i]+b[i];
		if(s[i]>=MOD) s[i]-=MOD,++s[i+1];//进位
	}if( !s[s[0]]&&s[0]>1 ) --s[0];//去除前导零，应对没有进位的情况
	return;
}

void minus(long long a[],long long b[])
{
	if(f1^f2){
		if(f1) f1^=1,f^=1,plus(a,b);//a-b=-(-a+b)
		if(f2) f2^=1,plus(a,b);//a-b=a+(-b)
		return;
	}if(f1&f2){
		f1=f2=0,minus(b,a);//a-b=-b-(-a)
		f1=f2=1;return;
	}if(cmp(a,b)==-1) swap(a,b),f^=1;//绝对值相减，符号与绝对值大的数符号相同
	clear(s);
	s[0]=max(a[0],b[0]);
	for(int i=1;i<=s[0];++i){
		s[i]+=a[i]-b[i];
		if(s[i]<0) s[i]+=MOD,--s[i+1];//借位
	}while(!s[s[0]]&&s[0]>1) --s[0];//去除前导零
	return;
}

void multiply(long long a[],long long b[])//模拟竖式乘法
{
	if(f1^f2) f^=1;
	clear(s);
	s[0]=a[0]+b[0];
	for(int i=1;i<=a[0];++i){
		for(int j=1;j<=b[0];++j){
			s[i+j-1]+=a[i]*b[j];
			if(s[i+j-1]>=MOD) s[i+j]+=s[i+j-1]/MOD,s[i+j-1]%=MOD;//进位
		}
	}if(!s[s[0]]&&s[0]>1) --s[0];
	return;
}

void divide(long long a[],long long b[])
{
	if(f1^f2) f^=1;
	clear(cp),cp[1]=1;clear(lt);
	while(cmp(a,b)!=-1) l1b(b),l1b(cp);//将除数倍增到不小于被除数，确定商二进制最高位
	while(cp[0]>1||cp[1]){
		if(cmp(a,b)!=-1){
			minus(a,b),cpy(a,s);//a-=b
			plus(lt,cp),cpy(lt,s);//lt+=cp
		}r1b(b),r1b(cp);//b>>=1,cp>>=1
	}cpy(s,lt),cpy(lt,a);//s=lt,lt=a，此时，s是商，lt是余数
	return;
}

int main()
{
	init();
	clear(s);
	plus(a,b);
	write(s);
	minus(a,b);
	write(s);
	multiply(a,b);
	write(s);
	divide(a,b);
	write(s);
	write(lt);
	return 0;
}