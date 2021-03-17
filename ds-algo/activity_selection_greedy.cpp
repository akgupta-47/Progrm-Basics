#include <iostream>

using namespace std;
class Greedy {
    public:
    int sta;
    int fin;
};

void swapAr(Greedy *i,Greedy *k){
    Greedy c = *i;
    *i = *k;
    *k = c;
}

void sortOnFin(Greedy *obs, int n){
    int i,j;
    int flag;
    // loop of repeating passes
    for(i=0 ;i<n-1 ; i++){
        flag = 0;
        // after every pass the number of comparisons should reduce 
        for(j=0; j<n-1-i ; j++){
            if(obs[j].fin > obs[j+1].fin){
                swapAr( &obs[j], &obs[j+1] );
                flag = 1;
            }
        }
        if(flag == 0) return;
    }
}

void findQ(Greedy *obs, int n){
    sortOnFin(obs, n);
    int i=0;
    cout << obs[0].fin<<" ";
    cout<<i<<" "<<endl;
    for (int j = 1; j < n; j++)
    {
      if (obs[j].sta >= obs[i].fin)
      {
          cout << obs[j].fin<<" ";
          cout <<j<<" "<<endl;
          i = j;
      }
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
        cin>>obs[i].sta;
        cin>>obs[i].fin;
    }
    
    findQ(obs, n);
    /*
    for(int j=0; j<n;j++){
        cout<<obs[j].fin<<" ";
    }
    */
    return 0;
}

