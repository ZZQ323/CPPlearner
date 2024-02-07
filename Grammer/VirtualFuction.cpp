#include<bits/stdc++.h>

using namespace std;

class A{
private:
    int c;
protected:
    int b;
public:
    int a;
    void print(){cout<<"A"<<endl;}
};

// override只是一种检查，需不需函数得是基类函数virtual不virtual决定的。
// 加了virtual，<A> = {_vptr.A = 0x7ff6e09645d0 <vtable for B+16>}
// 没有virtual，$1 = {<A> = {<No data fields>}, <No data fields>}
// 这里面的问题就在于，如果我使用基类指针指向子类， 不virtual就无法实现多态
// 这一点优化，JAVA是自动做的，只要函数名一致就自动多态了。
// 至于自己的指针指向自己，那没有任何问题。

class B :public A{
public:
    void print(){cout<<"B"<<endl;}
}; 

class C:private A{
public:
    void foo(){
        a=1;
        b=1;
        // c=1;
    }
};

/* 
  * 形式：
  *     class <派生类名>:<继承方式1><基类名1>,<继承方式2><基类名2>,
  * 
  * 三种继承方式private、protected、public ；如果缺省即为private
  *     继承修饰符就是把基类中的public和protected的成员，当做自己的什么；
  * - public：基类是public，那子类也是public；是protected，子类也是
  * - protected：基类是public，是protected，子类全是protected
  * - private：基类是public，是protected，子类全是private
  * 
*/


/* 虚函数的理解
  * - 虚函数 是在基类中使用关键字 virtual 声明的函数。
  * 在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数。
  * 我们想要的是在程序中任意点可以根据所调用的对象类型来选择调用的函数，
  *     这种操作被称为动态链接，或后期绑定。
  * 
  * - 定义一个函数为虚函数，不代表函数为不被实现的函数。
  * 定义虚函数是,为了允许用基类的指针来调用子类的这个函数。
  * 定义一个函数为纯虚函数，才代表函数没有被实现。
  * 定义纯虚函数是为了实现一个接口，起到一个规范的作用，规范继承这个类的程序员必须实现这个函数。
  * 
  * - virtual int area() = 0; 
  * = 0 告诉编译器，函数没有主体，上面的虚函数是纯虚函数。
  * 
  * 1. 实现了纯虚函数的子类，该纯虚函数在子类中就变成了虚函数，子类的子类即孙子类可以覆盖该虚函数，由多态方式调用的时候动态绑定。
  * 2. 析构函数应当是虚函数，将调用相应对象类型的析构函数；如果指针指向的是子类对象，将可以调用子类的析构函数，然后自动调用基类的析构函数。
  * 3. 包含纯虚函数的类是抽象类，抽象类不能定义实例，但可以声明指向实现该抽象类的具体类的指针或引用
  * 
  * 添加override可以检查时候重写了（就是检查有没有虚函数表）
  * 添加final可以禁止重写函数
*/

template<typename T>
using Base=T;
template<typename T>
using pointer=T*;

int main(int argc, char const *argv[])
{
    // Base<B> temp;
    // pointer<A> p=&temp; 
    // pointer<B> pp=&temp; 
    // p->print();
    // pp->print();

    A temp;   //$1 = {c = 581, b = 0, a = 0}
    B temp1;   //$2 = {<A> = {c = 57, b = 0, a = -1283452096}, <No data fields>}
    printf("%d\n",sizeof(A)); // sizeof(A)=12
    printf("%d\n",sizeof(B)); // sizeof(B)=12
    
    return 0;
}