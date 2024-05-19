
#include<iostream>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

// 开 2e6+100 好像会 TLE、WA，数组越界
constexpr int N = 3e6+100;
const double Pi = acos(-1);
struct complex {
	double real;
	double img;

	complex(double r = 0, double i = 0)
		:real(r), img(i) {
		;
	}

	friend complex operator+(const complex& a, const complex& b) { return complex(a.real + b.real, a.img + b.img); }
	friend complex operator-(const complex& a, const complex& b) { return complex(a.real - b.real, a.img - b.img); }
	friend complex operator*(const complex& a, const complex& b) { return complex(a.real * b.real - a.img * b.img, a.real * b.img + a.img * b.real); }
};


inline int read()
{
	bool f = 0;
	char x = getchar();
	while (!isdigit(x)) { if (x == '-')f = 1; x = getchar(); }
	int ret = 0;
	while (isdigit(x)) { ret = ret * 10 + (x - '0'); x = getchar(); }
	if (f) ret = -ret;
	return ret;
}

inline int read(complex* var)
{
	static char s[N];
	if (scanf("%s", s) == -1)return -1;
	int len = strlen(s);
	for (int i = len - 1; i >= 0; --i) {
		var[len - i - 1].real = (s[i] - '0');
	}
	return len;
}

int r[N], ans[N];
int n, l, l1, l2;

void FFT(complex* Ak, int type)
{
	// 位置重设
	for (int i = 0; i < n; ++i)
		if (i < r[i])swap(Ak[i], Ak[r[i]]);
	for (int curl = 1; curl < n; curl <<= 1) {
		complex Wn(cos(Pi / curl), type * sin( Pi / curl));
		for (int nextl = curl << 1, lbeg = 0; lbeg < n; lbeg += nextl) {
			complex wk(1, 0);
			int rbeg = lbeg + curl;
			for (int k = 0; k < curl; ++k, wk = wk * Wn) {
				complex Ak1 = Ak[lbeg + k], wAk2 = wk * Ak[rbeg + k];
				Ak[lbeg + k] = Ak1 + wAk2;
				Ak[rbeg + k] = Ak1 - wAk2;
			}
		}
	}
	// IFFT
	if (type == -1) {
		for (int i = 0; i < n; ++i) {
			Ak[i].real /= n;
		}
	}
}

complex A[N], B[N];

int main()
{
	while (true) {
		memset(ans, 0, sizeof(ans));
		l1 = read(A);
		l2 = read(B);
		if (l1 == -1 || l2 == -1)break;
		n = 1, l = 0;
		while (n <= l1 + l2 ) n <<= 1, ++l;
		for (int i = 0; i < n; ++i) {
			//重映射下标
			r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
		}
		FFT(A, 1);
		FFT(B, 1);
		for (int i = 0; i <= n; ++i) {
			A[i] = A[i] * B[i];
		}
		FFT(A, -1);
		for (int i = 0; i <= n; ++i) {
			ans[i] += (int)(A[i].real + 0.5);
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
		while (!ans[n] && n > -1)--n;
		if (n == -1)printf("0");
		else {
			for (int i = n; i >= 0; --i) {
				printf("%d", ans[i]);
			}
		}
		putchar('\n');
	}
	return 0;
}

// link：https://www.luogu.com.cn/problem/P1919
