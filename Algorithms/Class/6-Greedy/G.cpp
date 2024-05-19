#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n, k;
constexpr int N = 1e5 + 100;
using ll = long long;
int a[N], p[N];
ll sum[N];
int ck;

inline int rev(int i) { return n - i + 1; }

bool check(int mid)
{
	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		// i - idx 满足属于要求的区间
		int idx = upper_bound(sum + i, sum + n + 1, sum[i - 1] + mid) - sum - 1;
		// 获得区间右端点
		i = idx;
		// 区间个数++
		++ret;
	}
	return ret <= k;
}

int solve(int mid)
{
	int ret = 0;
	ck = 0;
	for (int i = 1; i <= n; ++i) {
		int idx = upper_bound(sum + i, sum + n + 1, sum[i - 1] + mid) - sum - 1;
		if (idx < n)
			p[++ck] = rev(idx);
		i = idx;
		++ret;
	}
	return ret;
}

int main(int argc, char const* argv[])
{
	while (scanf("%d%d", &n, &k) != EOF) {
		int maxn = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			maxn = max(maxn, a[i]);
		}
		sum[0] = 0;
		for (int i = 1; i <= n; ++i)
			sum[i] = sum[i - 1] + a[rev(i)];
		int l = maxn, r = int(1e9);
		while (l < r) {
			int mid = l + r >> 1;
			if (check(mid))r = mid;
			else l = mid + 1;
		}
		//printf("%d\n",l);
		int c = solve(l);
		//reverse(p + 1, p + ck + 1);
		for (int i = 1, j = 1; i <= n; ++i) {
			if (i == p[ck-j+1]) {
				printf(" /");
				++j;
			}
			else if ( i > 1 && c < k) {
				printf(" /");
				++c;
			}
			printf(" %d" + (i == 1), a[i]);
		}putchar('\n');
	}
	return 0;
}

/*
9 3
10 20 30 40 50 60 70 80 90

15 3
857 744 492 228 366 860 937 433 552 438 229 276 408 475 122

一题多解:  http://t.csdnimg.cn/Og0wB 
类似题源： https://www.luogu.com.cn/record/159146646
*/
