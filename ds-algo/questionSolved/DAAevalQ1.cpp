#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// declare global vars
int minMarks;
int totStuds;
int totQs;

// Marks is a class of score, subParts and array ids
class Marks{
    public:
    int maxScore;
    int subParts;
    int initId;
};

// swap 2 Marks objects
void swapAr(Marks *i,Marks *k){
    Marks c = *i;
    *i = *k;
    *k = c;
}
// to sort array of objects 
void selectionSort(Marks *sortAr){
    int i,j,k;
    for(i=0 ;i<totQs-1 ; i++){
        for(j=k=i; j<totQs; j++){
            if(sortAr[j].subParts > sortAr[k].subParts){
                k=j;
            }
        }
        swapAr(&sortAr[i], &sortAr[k]);
    }
}

// sort based on ratio
void bubbleRatioSort(Marks *ar, int a,int b){
    int i,j;
    int flag;
    // loop of repeating passes
    for(i=0 ;i<(b-a) ; i++){
        flag = 0;
        // after every pass the number of comparisons should reduce 
        for(j=a; j<b-i ; j++){
            float x = ar[j].maxScore/ar[j].subParts;
            float y = ar[j+1].maxScore/ar[j+1].subParts;
            if(x > y){
                swapAr( &ar[j], &ar[j+1] );
                flag = 1;
            }
        }
        if(flag == 0) return;
    }
}

// sort whole object array based on all requirements
void sortQSetArray(Marks *arr){
    selectionSort(arr);
    for(int j=0;j<totQs;j++){
        if(arr[j].subParts == arr[j+1].subParts){
            for(int k =j;k<totQs;k++){
                if(arr[k].subParts == arr[k+1].subParts){
                    continue;
                }else{
                    // cout<<k;
                    bubbleRatioSort(arr, j,k);
                    j=k;
                    break;
                }
            }
        }
    }
    for(int a=0;a<totQs;a++){
        cout<<arr[a].maxScore<<" ";
    }
    cout<<endl;
}

// calute the question set based on threshold and print it
void calcQSet(Marks *arr, int *marks, int thresh){
    vector<int> seq;
    int sum;
    for(int a=0;a<totStuds;a++){
        sum=marks[a];
        for(int i=0;i<totQs;i++){
            if(sum > thresh){
                break;
            }else{
                sum = sum + arr[i].maxScore;
                seq.push_back(arr[i].initId);
            }
        }
        sum=0;
        cout<<seq.size()<<" ";
        sort(seq.begin(),seq.end());
        for(auto x : seq)
            cout<<x<<" ";
        cout<<endl;
        seq.clear();
    }
}

// main driver funcion
int main()
{
    // input minimum marks, total students and total assignments
    cin>>minMarks>>totStuds>>totQs;
    int sesMarks[totStuds];
    // decalre a aobject array og assigments
    Marks qSet[totQs];
    int i;
    for (i=0; i<totStuds; i++){
        cin>>sesMarks[i];
    }
    for (i=0;i<totQs;i++){
        cin>>qSet[i].maxScore>>qSet[i].subParts;
        qSet[i].initId=i+1;
    }
    
    sortQSetArray(qSet);
    calcQSet(qSet, sesMarks, minMarks);
    
    return 0;
}

