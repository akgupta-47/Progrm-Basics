// stack approach
#include <iostream>
#include <stack>
using namespace std;

int countSubEqual01(string sub){
    stack<char> stk;
    int count = 0;
    int i,k;
    int push,pop;
    for(i=0; i<sub.length(); i++){
        stk.push(sub[i]);
        k=i+1;
        push = 1;
        pop = 0;
        while(!stk.empty() && k < sub.length()){
            if(sub[k] == sub[i]){
                stk.push(sub[k]);
                push++;
            }else{
                stk.pop();
                pop++;
            }
            if(push == pop){
                count++;
                break;
            }
            k++;
        }
    }
    return count;
}

int main()
{
    string test;
    cin>>test;
    
    cout<<"there are "<<countSubEqual01(test);

    return 0;
}

// vector approach
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int countSubEqual01(string sub){
    vector<char> stk;
    int count = 0;
    int i,k;
    int push,pop;
    for(i=0; i<sub.length(); i++){
        stk.push_back(sub[i]);
        k=i+1;
        push = 1;
        pop = 0;
        while(!stk.empty() && k < sub.length()){
            if(sub[k] == sub[i]){
                stk.push_back(sub[k]);
                push++;
            }else{
                stk.pop_back();
                pop++;
            }
            if(push == pop){
                count++;
                break;
            }
            k++;
        }
        //stk.clear();
    }
    return count;
}

int main()
{
    string test;
    cin>>test;
    
    cout<<"there are "<<countSubEqual01(test);

    return 0;
}
 /////
 // vector approach
#include <bits/stdc++.h>
using namespace std;
//000 11100 100  1 flag=0
int countSubEqual01(string s){
  int prev = 0;
  int last = 0;
  int count = 0;
  char ch = s[0];
  // generally auto i copies values in list one by one
  // but to modify the value we need to use refrence that will share the same memory of list under diffrent name
  for(auto i : s){
    cout << &i << " " << i << " " << typeid(&i).name() << endl;
	if(ch != i){
	  count += min(prev,last);
	  prev = last;
	  last = 1;
	  ch = i;
	}
	else last++;
  }
  count += min(prev,last);
  return count;
}

int main()
{
    string test;
    cin>>test;
    
    cout<<"there are "<<countSubEqual01(test);

    return 0;
}

