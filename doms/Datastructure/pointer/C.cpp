#include<iostream>

class Date {
    int year, month, day;
public:
    Date();                             // 缺省构造函数，给year、month、day分别赋值为1900、1、1
    Date(int y, int m, int d);          // 带参构造函数，给year、month、day分别赋参数的值
    int getYear();                      // 返回当前日期的年份
    int getMonth();                     // 返回当前日期的月份
    int getDay();                       // 返回当前日期的日
    void setDate(int y, int m, int d);  // 按参数重设日期的值
    void print();                       
    void addOneDay();                   // 在当前日期上加一天
};

Date::Date()
:year(1900), month(1), day(1)
{

}

Date::Date(int y, int m, int d)
:year(y), month(m), day(d)
{

}

int Date::getYear()
{
    return year ;
}

int Date::getMonth()
{
    return month ;
}

int Date::getDay()
{
    return day ;

}

void Date::setDate(int y, int m, int d)
{
    year=y;
    month=m;
    day=d;
}

void Date::print()
{
    printf("%04d/%02d/%02d",year,month,day);
}

void Date::addOneDay()
{
    int& y=year;
    int& m=month;
    int& d=day;
    int days[]={
        0,31,28,31,30,31,30,31,31,30,31,30,31,
    };

    if( [](int n)->bool {
        return  !(n%4) && (n%100) || !(n%400);
    }(y) )
        ++days[2];

    d=d%days[m]+1;
    if(d==1)
    {
        m=m%12+1;
        if(m==1)
            ++y;
    }
}


int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int y;
        int m;
        int d;
        if(t&1){
            scanf("%d %d %d",&y,&m,&d);
            Date var(y,m,d);

            printf("Today is "),var.print(),putchar('\n');
            var.addOneDay();
            printf("Tomorrow is "),var.print();
        }else{
            scanf("%d %d %d",&y,&m,&d);
            Date var;
            var.setDate(y,m,d);
            printf("Today is "),var.print(),putchar('\n');
            var.addOneDay();
            printf("Tomorrow is "),var.print();
        }
        if(t)
            putchar('\n');
    }
    return 0;
}