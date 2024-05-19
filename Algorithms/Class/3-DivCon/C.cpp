#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

constexpr int N=1e5+100;
struct Point{
	int x,y,idx;

	bool operator<(const Point &a)const 
	{return x<a.x;}
}p[N],tmp[N];

inline int Sqr(int x){return x*x;}
inline int Dis(const Point&a,const Point&b)
{return Sqr(a.x-b.x)+Sqr(a.y-b.y);}

int ansa,ansb,ansdis;

int update(const Point&a,const Point&b)
{
	int na = a.idx;
	int nb = b.idx;
	int dis = Dis(a,b);
	if(na > nb){swap(na,nb);}
	if( ansdis == -1 || dis < ansdis || dis == ansdis && (na<ansa || na==ansa && nb < ansb) ){
		ansa = na,ansb = nb, ansdis = dis;
	}return dis;
}

bool cmp(const Point&a,const Point& b){return a.y<b.y;}

void JudgeNearby(int l,int mid,int r,Point& c)
{
	vector<Point> pl,pr;
	for(int i=l;i<mid;++i)
		if( Sqr(c.x-p[i].x) <= ansdis)pl.push_back(p[i]);
	for(int i=mid;i<r;++i)
		if( Sqr(c.x-p[i].x) <= ansdis)pr.push_back(p[i]);
	for(int i=0,j=0 ; i < pl.size(); ++i){
		while(j < pr.size() && pl[i].y > pr[j].y && Sqr(pl[i].y - pr[j].y) > ansdis )
			++j;
		for(int k = j;k < pr.size() && Sqr(pl[i].y - pr[k].y) <=ansdis ; ++k){
			update(pl[i],pr[k]);
		}
	}
}

void Merge(int l, int r, int mid) 
{
    int i = l, j = mid, k = l;
    while(i < mid && j < r)
    {
		// 为什么这里同y的情况下，不先放i的？
		// 其实是一样的，因为左边相对远了中线，而右边又相对近了 —— 无所谓。
        if(p[i].y < p[j].y) tmp[k ++] = p[i ++];
        else tmp[k ++] = p[j ++];
    }
    while(i < mid) tmp[k ++] = p[i ++];
    while(j < r) tmp[k ++] = p[j ++];
    memcpy(p + l, tmp + l, sizeof(Point) * (r - l));
}

int MinDis(int l,int r)
{
	if( r - l <=1)return 0x3f3f3f3f;
	int mid = l+r >>1;
	Point midp = p[mid];
	MinDis(l,mid);
	MinDis(mid,r);
	JudgeNearby(l,mid,r,midp);
	Merge(l, r, mid);
	// merge(p+l,p+mid+1,p+mid+1,p+r+1,tmp,cmp);
	// copy(tmp,tmp+(r-l+1),p+l+1);
	return ansdis;
}

int main(int argc, char const *argv[])
{
	int n;
	while( ~scanf("%d",&n) ){
		ansa = ansb = ansdis = 0x3f3f3f3f;
		for(int i=0;i<n;++i){
			scanf("%d%d",&p[i].x,&p[i].y);
			p[i].idx=i;
		}
		sort(p,p+n); // x递增排序
		MinDis(0,n);
		printf("%d %d\n",ansa,ansb);
	}
	return 0;
}
