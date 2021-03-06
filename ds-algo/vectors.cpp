#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int fun(int x,int y){
        return x>y;
    }
    
int multi(int x, int y){
    return x*y;
}

int main()
{
    vector<int> A= {3,4,1,2};
    bool present  = binary_search(A.begin(), A.end(), 5);
    if(present){
        cout<<"eureka";
    }
    for(int x:A){
        cout<<x<<" ";
    }
    cout<<endl;
    sort(A.begin(), A.end(), fun);
    
    for(int z:A){
        cout<<z<<" ";
    }
    cout<<endl;
    auto it2 = A.begin();
    cout<<*it2 <<endl;
    
    // inserts 3 at front 
    auto it = A.insert(A.begin(), 9); 
    // inserts 2 at front 
    A.insert(it, 8); 
    
    A.push_back(10);
    int i = 3; 
    // inserts 7 at i-th index 
    it = A.insert(A.begin() + i, 7); 
    for(int z:A){
        cout<<z<<" ";
    }
    
    cout<<endl<<A.front()<<endl<<A.back()<<endl;
    
    /*
    vector<int> v = {1,2,3,4};
    for(int i=0;i<v.size();i++){
        v[i]++;
    }
    for(int x:v){
        cout<<x<<" ";
    }
    */
    
    // sum and multiplication of all elements (also try partial_sum() a diffrent variant which offers step by step accumulation)
    // here we used numeric library
    int initializer = 0;
    int allSum =  accumulate(A.begin(), A.end(), initializer);
    cout<<allSum<<endl;
    
    int init_1 = 1;
    int mult = accumulate(A.begin(), A.end(), init_1, multi);
    cout<< mult;
    // research to use regex stl
    
    // max element
    int it = max_element(A.begin(), A.end()) - A.begin();
    //use min for minimum element
    
    int num = distance(A.begin(),A.end()); // this excludes last element and includes first element
    
    // remove all unique
    sort(A.begin(), A.end());
    auto ip = unique(A.begin(), A.end());
    v.resize(distance(A.begin(), ip));
    
    vector<int> myv = {4,4,4,4,4};
    //check all equal
    if ( adjacent_find( myv.begin(), myv.end(), not_equal_to<>() ) == myv.end() )
	{
    		cout << "All elements are equal each other" << endl;
	}else{
    		cout<<" not_equal"<<endl;
    		for(int x:myv){
        		cout<<x<<" ";
    		}
	}
	
// auto ip_2 = adjacent_find(vect.begin(), vect.end()); this will find first repeating element or find if not return the last element
    
    return 0;
}
