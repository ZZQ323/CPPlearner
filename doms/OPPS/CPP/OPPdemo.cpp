#include<iostream>
#include<algorithm>
#include<string>

using std::string;

class tractor{
public:

	tractor(){;}

    void run(){;}
public:
    string brand;
private:
    int lenght;
	int width;
	int height;
};

class broom{
public:
	broom(){;}    
private:
    void __decay__()
    {life*=decay_rate;}
public:
    string brand;
private:
    double life;
    double decay_rate;
};

class new_tractor{
public:
    new_tractor()
    {;}

private:
    broom cleaner;
    tractor engine;
};

signed main(int argc,char**argv)
{

    return 0;
}