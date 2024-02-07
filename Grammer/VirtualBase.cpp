#include<iostream>

class A
{
private:
    int a;
public:
    A() {}
    ~A() {}
};

class B:public A
{
private:
    int a;
public:
    B() {}
    ~B() {}
};

class C:public A
{
private:
    int a;
public:
    C() {}
    ~C() {}
};

class D:public B,C{
private:
    int a;
public:
    D() {}
    ~D() {}
};

int main(int argc, char const *argv[])
{
        
    return 0;
}
