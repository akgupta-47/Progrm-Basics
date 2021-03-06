/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    list<int> node;
    node.push_back(1);
    node.push_back(2);
    node.push_back(3);
    node.push_back(4);
    node.push_back(5);
    node.push_back(6);
    
    auto it = find(node.begin(), node.end(), 3);
    // if(it != node.end()){
    //     cout<<"element found at "<<*it;
    // }
    // auto i = node.begin();
    // for (; i != it; i++) {
        
    // }
    // i++;
    // node.insert(i,5);
    auto it_3 = find(node.begin(), node.end(), 2);
    auto it_4 = find(node.begin(), node.end(), 6);
    auto it_st = it_3;
    advance(it_st, distance(it_3,it_4)/2);
    node.insert(it_st,8);
    for(auto& elm : node){
        cout<<elm<<endl;
    }
    return 0;
}

