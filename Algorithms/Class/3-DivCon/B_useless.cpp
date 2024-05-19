#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct Binary{
	static int radix;
};
int Binary::radix=2;

struct Decimal{
	static int radix;
};
int Decimal::radix=10;

// 整数位乘
template<class _r,class T=int>
struct Integer{
    vector<T> x;     // 由低位到高位保存二进制位
    bool neg;               // 标记数的正负
    void Init(){x.clear(); neg = false;}
    Integer(){Init();}

    void Print()
    {
        if(neg && !x.empty()) printf("-");
        for(int i = x.size() - 1; i >= 0; i --)
            printf("%d", x[i]);
        if(x.empty()) printf("0");
        printf("\n");
    }

	Integer& rev_sign(){neg=!neg;return *this;}
	size_t size(){return x.size();}
	T& operator[](int idx){return x[idx];}
	void push_back(const T& val){x.push_back(val);}
};

Integer<Binary> Add(Integer<Binary> &a, Integer<Binary> &b);
Integer<Binary> Minus(Integer<Binary> &a, Integer<Binary> &b);
Integer<Binary> Mul(Integer<Binary> &a, Integer<Binary> &b);
void MulN2(Integer<Binary> &a, int n_2);
Integer<Binary> FasterMul(Integer<Binary> &a, Integer<Binary> &b);


Integer<Binary> Add(Integer<Binary> &a, Integer<Binary> &b)
{
	if( a.neg && !b.neg){
		a.rev_sign();
		return Minus(b,a);
	}
	if( !a.neg && b.neg){
		b.rev_sign();
		return Minus(a,b);
	}
	if( a.neg && b.neg){
		a.rev_sign();
		b.rev_sign();
		return Add(a,b).rev_sign();
	}
	if( a.size() < b.size() ){
		return Add(b,a);
	}
    // TODO: 返回 a + b 的结果，小心两数异号情况
	int carry=0;
	Integer<Binary> ret;
	for(int i=0;i < b.size();++i){
		ret.push_back(a[i] + b[i] + carry);
		if(ret[i]>=Binary::radix){
			carry = ret[i]/Binary::radix;
			ret[i] = ret[i]%Binary::radix;
		}
	}
	for(int i=b.size();carry && i < a.size() ; ++i ){
		ret[i] = a[i] + carry%Binary::radix;
		carry /= Binary::radix;
	}
	return ret;
}

Integer<Binary> Minus(Integer<Binary> &a, Integer<Binary> &b)
{
	if( a.neg && !b.neg){
		a.rev_sign();
		return Add(a,b).rev_sign();
	}
	if( !a.neg && b.neg){
		b.rev_sign();
		return Add(a,b);
	}
	if( a.neg && b.neg){
		a.rev_sign();
		b.rev_sign();
		return Minus(b,a);
	}
	if( a.size() < b.size() )
		return Minus(b,a).rev_sign();
    // TODO: 返回 a - b 的结果，注意正负号
	int borrow=0;
	Integer<Binary> ret;
	for(int i=0;i < b.size() ;++i){
		ret.push_back(a[i] - b[i] + borrow);
		if(ret[i]<0){
			borrow = ret[i]/Binary::radix + 1;
			ret[i] = (ret[i]+borrow)%Binary::radix;
		}
	}
	for(int i=b.size() ;borrow && i < a.size() ; ++i){
		ret[i] =a[i] + borrow%Binary::radix;
		borrow/=Binary::radix;
	}
	return ret;
}

Integer<Binary> Mul(Integer<Binary> &a, Integer<Binary> &b)
{
    // TODO: 模拟竖式计算两数相乘
	if( a.neg && !b.neg){
		return Mul(a,b).rev_sign();
	}
	if( !a.neg && b.neg){
		b.rev_sign();
		return Mul(a,b).rev_sign();
	}
	if( a.neg && b.neg){
		a.rev_sign();
		b.rev_sign();
		return Mul(b,a);
	}
	if( a.size() < b.size() )
		return Minus(b,a).rev_sign();
	Integer<Binary> ret;
	int carry=0;
	for(int i=0;i<a.size();++i){
		int tmp=0;
		for(int j=0;j<=i;++j){
			tmp+=a[i]*b[i-j];
		}
		ret[i]=tmp + carry;
		if( ret[i] > Binary::radix ){
			carry = ret[i]/Binary::radix;
			ret[i] %= Binary::radix;
		}
	}
}

void MulN2(Integer<Binary> &a, int n_2)
{
    // TODO: 为 a 添加 n_2 个二进制0，即乘以 2^(n_2)
	
}

Integer<Binary> FasterMul(Integer<Binary> &a, Integer<Binary> &b)
{
    // TODO: 分治优化位乘
    // 设 a = A * 2^(n/2) + B， b = C * 2^(n/2) + D
    // a*b = AC*2^n + [(A - B)(D - C) + AC + BD] * 2^(n/2) + BD
    // 注意：a 和 b 位数不一定相同，需要额外处理边界。
}

int main(int argc, char const *argv[])
{

	return 0;
}

