#include<iostream>
#include<cmath>

using namespace std;

constexpr double eps = 1e-7;
struct Circle{
	double x,y,r;
}p[100];
int c[100];

inline int sgn(double num){return fabs(num)<eps?0:num>0?1:-1;}
inline double dis(const Circle&a,const Circle&b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}

int main(int argc, char const *argv[])
{
	int n=1;
	while (scanf("%lf%lf%lf",&p[n].x,&p[n].y,&p[n].r)!=EOF){
		++n;
	}--n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			double d = dis(p[i],p[j]);
			if( i!=j && (sgn(d  - fabs(p[i].r+p[j].r)) ==0 || sgn(d - fabs(p[i].r-p[j].r)) ==0)  ){
				++c[j];
			}
		}
	}
	for(int i=1;i<=n;++i){
		printf("c[%d] = %d\n",i,c[i]);
	}
	return 0;
}
/*
0.7	0.2	0.2
0.0	0.4	0.8
0.8	0.9	0.4
1.2	0.9	0.7
1.2	0.9	0.9
2.1	0.9	0.4
2.1	0.9	0.3
2.4	0.9	0.3
0.3	0.2	0.2
0.5	0.1	0.1
2.7	0.9	0.2
2.8	0.9	0.4
3.3	0.9	0.2
3.5	0.9	0.3
3.5	0.9	0.6
4.1	0.9	0.7
4.9	0.9	0.1
4.9	0.9	1.0
4.9	0.9	0.0
4.9	0.9	0.8
*/