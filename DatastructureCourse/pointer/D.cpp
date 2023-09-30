#include<iostream>
#include<cmath>

class Point
{
    double x, y;
public:
    Point();
    Point(double x_value, double y_value);      // 缺省构造函数，给 x, y 分别赋值为0
    ~Point();                                   // 析构函数
    double getX();                              // 返回x的值
    double getY();                              // 返回y的值
    void setXY(double x1, double y1){x = x1; y = y1;}
    void setX(double x_value);                  // 设置x的值
    void setY(double y_value);                  // 设置y的值
    double getDisTo(Point &p);                  // 计算当前点到参数点p的距离
};

Point::Point(){x=y=0;printf("Constructor.\n");}

Point::Point(double x_value, double y_value)
:x(x_value),y(y_value){printf("Constructor.\n");}

Point::~Point()
{
    printf("Distructor.\n");
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}


void Point::setX(double x_value)
{
    x=x_value;
}

void Point::setY(double y_value)
{
    y=y_value;
}

#define sqr(x) ((x)*(x))
double Point::getDisTo(Point &p)
{
    return sqrt(sqr(x-p.x)+sqr(y-p.y));
}
#undef sqr(x)

const double eps=1e-8;
inline int sgn(double num){return fabs(num)<eps?0:(num>0?1:-1) ;}


int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        Point var[n];
        for(int i=0;i<n;++i)
        {
            double x,y;
            scanf("%lf %lf",&x,&y);
            var[i].setXY(x,y);
        }

        int ai=0,aj=0;
        double maxn=0;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if( sgn( maxn-var[i].getDisTo(var[j]) ) < 0 )
                {
                    maxn=var[i].getDisTo(var[j]);
                    ai=i;
                    aj=j;
                }
            }
        }
        printf("The longeset distance is %.2f,between p[%d] and p[%d].\n",maxn,ai,aj);
    }

    return 0;
}