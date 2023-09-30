#include <iostream>
#include "include/forward_list.hpp"

using std::cin;
using std::cout;
using ZZQ323::forward_list;

int main()
{
    std::cout << "Hello, World!" << std::endl;
    forward_list var;
    int n;cin>>>n;
    for(int i=1;i<=n;++i){
        int x;cin>>x;var.push_back(var);
    }



    return 0;
}