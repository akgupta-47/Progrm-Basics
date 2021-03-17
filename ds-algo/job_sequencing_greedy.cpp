#include <iostream>

using namespace std;
class Greedy {
    public:
    int ddln;
    int prft;
};

void swapAr(Greedy *i,Greedy *k){
    Greedy c = *i;
    *i = *k;
    *k = c;
}

void sortOnPrft(Greedy *obs, int n){
    int i,j;
    int flag;
    // loop of repeating passes
    for(i=0 ;i<n-1 ; i++){
        flag = 0;
        // after every pass the number of comparisons should reduce 
        for(j=0; j<n-1-i ; j++){
            if(obs[j].prft > obs[j+1].prft){
                swapAr( &obs[j], &obs[j+1] );
                flag = 1;
            }
        }
        if(flag == 0) return;
    }
}

int largest(int arr[], int n)
{
    int i;
    int max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
 
    return max;
}

void findQ(Greedy *obs, int n){
    sortOnPrft(obs, n);
    int max = largest(obs, n);
    int ddln[max];
    for(int i=0;i<n;i++){
        
    }
}

int main()
{
    int n;
    cout<<"enter numbr of activities"<<endl;
    cin>>n;
    Greedy obs[n];
    cout<<"Enter activities"<<endl;
    for(int i=0;i<n;i++){
        cin>>obs[i].ddln;
        cin>>obs[i].prft;
    }
    
    findQ(obs, n);
    /*
    for(int j=0; j<n;j++){
        cout<<obs[j].fin<<" ";
    }
    */
    return 0;
}

