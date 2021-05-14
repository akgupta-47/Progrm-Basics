#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// we made it a const vector as we didnot ant to change values of vector
void displayMe(const vector<int> &arr, int n){
    for(auto i:arr){
        cout<<i<<" ";
    }
}

void displayArray(int *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void revAr(int *arr, int n){
    int k;
    for(int i=0;i< n/2; i++){
        k=arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = k;
    }
    displayArray(arr, n);
}

int main()
{
    // lets reverse arrays
    int arr[] = { 1, 45, 54, 71, 76, 12 };
    int n = sizeof(arr)/sizeof(arr[0]);
    reverse(arr, arr+n);
    // displayMe(arr, n);
    
    vector<int> blue = { 1, 45, 54, 71, 76, 12 };
    reverse(blue.begin(), blue.end());
    // displayMe(blue, blue.size());
    
    revAr(arr, n);

    return 0;
}

