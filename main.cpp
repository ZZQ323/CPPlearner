#include <iostream>
#include <forward_list>
//#include "include/forward_list.hpp"

using std::cin;
using std::cout;
using std::forward_list;
//using ZZQ323::forward_list;

int main()
{
    std::cout << "Hello, World!" << std::endl;
    forward_list<int> var;
    int n;cin>>n;
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        var.push_front(x);
    }




    return 0;
}