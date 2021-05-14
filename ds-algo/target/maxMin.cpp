#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // lets reverse arrays
    int arr[] = { 1, 45, 54, 71, 76, 12 };
    int n = sizeof(arr)/sizeof(arr[0]);
    // cout<<*min_element(arr, arr+n);
    // cout<<*max_element(arr, arr+n);
    //cout<<distance(arr, max_element(arr, arr + n));
    
    vector<int> blue = { 1, 45, 54, 71, 76, 12 };
    cout<< *max_element(blue.begin(), blue.end());
    cout<<distance(blue.begin(), max_element(blue.begin(), blue.end()));

    return 0;
}

