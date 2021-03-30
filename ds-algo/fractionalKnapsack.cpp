#include <iostream>
#include <iomanip> 

using namespace std;
class Greedy {
    public:
    int prof;
    int wght;
    float fr;
    
    void insert(int profit, int weight){
        this->prof = profit;
        this->wght = weight;
        this->fr = (float)profit / weight;
    }
};

void swapAr(Greedy *i,Greedy *k){
    Greedy c = *i;
    *i = *k;
    *k = c;
}

void sortOnFr(Greedy *obs, int n){
    int i,j;
    int flag;
    // loop of repeating passes
    for(i=0 ;i<n-1 ; i++){
        flag = 0;
        // after every pass the number of comparisons should reduce 
        for(j=0; j<n-1-i ; j++){
            if(obs[j].fr < obs[j+1].fr){
                swapAr( &obs[j], &obs[j+1] );
                flag = 1;
            }
        }
        if(flag == 0) return;
    }
}

void findQ(Greedy *obs, int n,int aw){
    sortOnFr(obs, n);
    float totalPrft;
    int i=0;
    cout << obs[i].fr<<" ";
    aw -= obs[i].wght;
    totalPrft = obs[i].prof;
    cout<< i++ <<" "<<endl;
    
    while(aw != 0){
        if(aw >= obs[i].wght){
            aw -= obs[i].wght;
            totalPrft += obs[i].prof;
        }else{
            totalPrft += (float)(obs[i].prof * aw)/obs[i].wght;
            aw = 0;
        }
        cout << obs[i].fr<<" ";
        cout<<i<<" "<<endl;
            
        i++;
    }
    cout<< totalPrft<<endl;
    
}


int main()
{
    int n;
    cout<<"enter numbr of objects"<<endl;
    cin>>n;
    int allowedWt;
    cout<<"enter allowed weight"<<endl;
    cin>>allowedWt;
    
    Greedy obs[n];
    cout<<"Enter objects"<<endl;
    int profit,wt;
    for(int i=0;i<n;i++){
        cin>>profit>>wt;
        obs[i].insert(profit, wt);
    }
    
    findQ(obs, n, allowedWt);
    /*
    for(int j=0; j<n;j++){
        cout<<setprecision(3)<<obs[j].fr<<" ";
    }
    */
    return 0;
}
