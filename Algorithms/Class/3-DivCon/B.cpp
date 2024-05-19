#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

using BigBinary = vector<int>;

void check(BigBinary &x)
{
	// 去除前导0
	while( !x.empty() && x.back()==0 )x.pop_back();
	// 修正进制值
	int cur=0;
	for(int i=0;i < x.size() ;++i){
		x[i] += cur;
		cur = x[i] >> 1; // carry = x[i] / 2; 
		x[i] &= 1; // x[i] % 2
	}
	// 处理给到最高位的进位
	for(;cur;cur>>=1)x.push_back(cur&1);
}

void Print(BigBinary&x)
{
	check(x);
	for(int i=x.size()-1;i >= 0 ; --i){
		printf("%d",x[i]);
	}
	// 上面没有输出，全空行。
	if( x.empty() )printf("0");
	printf("\n");
} 

BigBinary Add(const BigBinary &a,const BigBinary &b,int neg=1){
	BigBinary c(a);
	for(int i=0;i < b.size();++i){
		c[i] += b[i]*neg;
	}return c;
}

BigBinary Minus(const BigBinary &a,const BigBinary &b){
	return Add(a,b,-1);
}

BigBinary Mul(const BigBinary&a,const BigBinary &b){
	BigBinary c;
	c.resize(a.size()*b.size()+1);
	for(int i = 0;i < a.size(); ++i){
		for(int j = 0;j < b.size();++j){
			c[i+j] += a[i]*b[j];
		}
	}
	return c;
}

// 扩大 2^(n2)倍数
void MulN2(BigBinary& a,int n2)
{
	int sizea=a.size();
	a.resize(sizea+n2);
	for(int i=a.size()-1 , j = sizea-1 ;j>=0; --i,--j){
		a[i] = a[j];
	}for(int i=n2-1;i>=0;--i)a[i]=0;
}

BigBinary FasterMul(const BigBinary&a,const BigBinary&b){
	if(a.size()<32 )return Mul(a,b);
	int n_2 = a.size() >> 1;
	// 设 a = A * 2^(n/2) + B， b = C * 2^(n/2) + D
    // a*b = AC*2^n + [(A - B)(D - C) + AC + BD] * 2^(n/2) + BD
    // 注意：a 和 b 位数不一定相同，需要额外处理边界。
	BigBinary A(a.begin()+n_2,a.end());
	BigBinary B(a.begin(),a.begin()+n_2);
	//  【STL】：iterator 可以相加，这一点可以类比指针。
	BigBinary C(b.begin()+n_2,b.end());
	BigBinary D(b.begin(),b.begin()+n_2);
	BigBinary A_C = FasterMul(A,C);
	BigBinary B_D = FasterMul(B,D);
	BigBinary ADpBC = Minus(Minus(FasterMul(Add(A,B),Add(C,D)),A_C),B_D);
	MulN2(A_C,n_2 << 1);
	MulN2(ADpBC,n_2);
	return Add(Add(A_C,ADpBC),B_D);
}

constexpr int maxn = 1e5+100;
char buf[maxn];
BigBinary a,b;

int main(int argc, char const *argv[])
{
	while(~scanf("%s",buf)){
		a.clear();
		b.clear();
		for(int i = strlen(buf)-1 ; i>=0 ; --i ){
			a.push_back(buf[i] == '1');
		}
		scanf("%s",buf);
		// 字符串从strlen-1开始，这里大意了……
		for(int i = strlen(buf)-1 ; i>=0 ; --i ){
			b.push_back(buf[i] == '1');
		}
		// 【STL】：使得a的大小调整为b.size()，多出来的部分填上0
		if( a.size() < b.size() )a.resize(b.size(),0); 
		else b.resize(a.size(),0);
		BigBinary res = FasterMul(a,b);
		Print(res);
	}
	return 0;
}
