////////////////////////////////////////////////////////////////
// unmodified selction sort
/*
comparisons = n(n-1)/2 ,so complexicity = n^2
passes = n ,so complexicity = n
*/
#include <iostream>

using namespace std;

void swapAr(int *i,int *k){
    int c = *i;
    *i = *k;
    *k = c;
}

void selectionSort(int *sortAr, int n){
    int i,j,k;
    for(i=0 ;i<n-1 ; i++){
        for(j=k=i; j<n; j++){
            if(sortAr[j]<sortAr[k]){
                k=j;
            }
        }
        swapAr(&sortAr[i], &sortAr[k]);
    }
}

int main()
{
    cout<<"enter num of elements"<<endl;
    int n;
    cin>>n;
    cout<<"enter an integer array"<<endl;
    int arr[n];
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    selectionSort(arr, n);

    cout<<"sorted integer array :-"<<endl;  
    for(int j=0; j<n; j++){
        cout<<arr[j]<<" ";
    }

    return 0;
}
////////////////////////////////////////////////////////////
// unmodified insertion sort
/*
comparisons = n(n-1)/2 ,so complexicity = n^2
passes = n-1 ,so complexicity = n
swaps = n(n-1)/2 ,so swaps = n^2
Insertion sort is Adaptive and stable considering the case of already sorted list or a list with duplicate elements
minimum time = n and max = n2
min swap = 1 and max swap = n2
*/
#include <iostream>

using namespace std;

void insertionSort(int *sortAr, int n){
    int i,j,x;
    // loop of repeating passes
    for(i=1 ;i<n ; i++){
        j = i-1;
        x = sortAr[i];
        while(j>-1 && sortAr[j]>x){
            sortAr[j+1] = sortAr[j];
            j--;
        }
        sortAr[j+1] = x;
    }
}

int main()
{
    cout<<"enter num of elements"<<endl;
    int n;
    cin>>n;
    cout<<"enter an integer array"<<endl;
    int arr[n];
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    insertionSort(arr, n);

    cout<<"sorted integer array :-"<<endl;  
    for(int j=0; j<n; j++){
        cout<<arr[j]<<" ";
    }

    return 0;
}
/*Unmodified Bubble Sort
passes = n-1
comparisons = 1+2+3... = n(n-1)/2 = O(n2)
swaps = O(n2) (logic same as comparisons) 
if u want to find largest elemnt do one pass and end element will be the largest element
min time if list already sorted = n
max time = n2
bubble sort is only adaptive with flag condition
*/
#include <iostream>

using namespace std;

void swapAr(int *i,int *k){
    int c = *i;
    *i = *k;
    *k = c;
}

void bubbleSort(int *sortAr, int n){
    int i,j;
    int flag;
    // loop of repeating passes
    for(i=0 ;i<n-1 ; i++){
        flag = 0;
        // after every pass the number of comparisons should reduce 
        for(j=0; j<n-1-i ; j++){
            if(sortAr[j] > sortAr[j+1]){
                swapAr( &sortAr[j], &sortAr[j+1] );
                flag = 1;
            }
        }
        if(flag == 0) return;
    }
}

int main()
{
    cout<<"enter num of elements"<<endl;
    int n;
    cin>>n;
    cout<<"enter an integer array"<<endl;
    int arr[n];
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    bubbleSort(arr, n);

    cout<<"sorted integer array :-"<<endl;  
    for(int j=0; j<n; j++){
        cout<<arr[j]<<" ";
    }

    return 0;
}
/*Quic sort
idea = if all elements before are smaller than it and all elements after it is bigger than it
*/
#include <iostream>

using namespace std;

void swapAr(int *i,int *k){
    int c = *i;
    *i = *k;
    *k = c;
}

int partition(int *sortAr, int l, int h){
    int i = l,j = h;
    int pivot = sortAr[l];
    do{
        do{i++;} while ( sortAr[i]<=pivot );
        do{j--;} while ( sortAr[j]>pivot );
        
        if(i<j){
            swapAr(&sortAr[i], &sortAr[j]);
        }
    }while(i<j);
    swapAr(&sortAr[l], &sortAr[j]);
    return j;
}

void quickSort(int *Arr, int l, int h){
    int j;
    if(l<h){
        j=partition(Arr, l,h);
        quickSort(Arr,l,j);
        quickSort(Arr,j+1,h);
    }
}

// l=0, h=0
// 10(l) 30 20 40(j) 50 80 90 60 70

int main()
{
    cout<<"enter num of elements"<<endl;
    int n;
    cin>>n;
    cout<<"enter an integer array"<<endl;
    int arr[n];
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    
    quickSort(arr, 0, n);

    cout<<"sorted integer array :-"<<endl;  
    for(int j=0; j<n; j++){
        cout<<arr[j]<<" ";
    }

    return 0;
}
/*Merge sort*/
#include <iostream>

using namespace std;

void mergeSort(int *ar1, int *ar2, int m, int n){
    int i,j,k;
    i=j=k=0;
    int ar3[m+n];
    
    while(i<m && j<n){
        if(ar1[i] < ar2[j]){
            ar3[k++] = ar1[i++];
        }else{
            ar3[k++] = ar2[j++];
        }
    }
    
    for(; i<m ; i++){
        ar3[k++] = ar1[i];
    }
    for(; j<n ; j++){
        ar3[k++] = ar2[j];
    }
    
    cout<<"sorted integer array :-"<<endl;  
    for(int j=0; j<(m+n); j++){
        cout<<ar3[j]<<" ";
    }
}

int main()
{
    cout<<"enter num of elements for both arrays"<<endl;
    int n,m;
    cin>>m>>n;
    cout<<"enter an integer array"<<endl;
    int arr[m];
    int brr[n];
    cout<<"Enter for A"<<endl;
    for(int i=0; i<m ;i++){
        cin>>arr[i];
    }
    cout<<"Enter for B"<<endl;
    for(int i=0; i<m ;i++){
        cin>>brr[i];
    }
    
    mergeSort(arr, brr, m, n);

    return 0;
}
/////////////////////////
// incomplete
#include <iostream>
#include <math.h>

using namespace std;

void Merge(int *A, int l,int mid, int h ){
    int i,j,k;
    int B[h++];
    i=l;    j=mid+1;    k=l;
    while(i<=mid && j<=h){
        if(A[i] < A[j]){
            B[k++] = A[i++];
        }else{
            B[k++] = A[j++];
        }
        for(; i<=mid ; i++){
            B[k++]=A[i];
        }
        for(; j<=mid ; j++){
            B[k++]=A[j];
        }
        
        for(i=l ; i<=h; i++) A[i] = B[i];
    }
}

void mergeSort(int *ar1, int n){
    int p,i,mid,l,h;
    
    for(p=2; p<=n; p=p*2){
        for(i=0; i+p-1<n; i=i+p){
            l=i;
            h=i+p-1;
            mid = floor((l+h)/2);
            Merge(ar1, l,mid, h);
        }
    }
    if((p/2) < n){
    Merge(ar1, 0,p/2, n-1);
    }
}

int main()
{
    cout<<"enter num of elements for array"<<endl;
    int n;
    cin>>n;
    cout<<"enter an integer array"<<endl;
    int arr[n];
    cout<<"Enter for A"<<endl;
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    
    mergeSort(arr, n);
    
    cout<<"sorted integer array :-"<<endl;  
    for(int j=0; j<n; j++){
        cout<<arr[j]<<" ";
    }

    return 0;
}

/////////////////////////////////////////////////////
//Count sort
// O(n) takes least time but a lot of memory
#include <iostream>

using namespace std;

int findMax(int *maxAr, int n){
    int max=maxAr[0];
    for(int i=0;i<n;i++){
        if(maxAr[i]>max){
            max=maxAr[i];
        }
    }
    return max;
}

void counrSort(int *sortAr, int n){
    int max=findMax(sortAr,n);
    int *c=new int[max+1];
    int i,j;
    for(i=0;i<max+1;i++){
        c[i]=0;
    }
    for(i=0;i<n;i++){
        c[sortAr[i]]++;
    }
    i=j=0;
    while(i<max+1){
        if(c[i]>0){
            sortAr[j++]=i;
            c[i]--;
        }else{
            i++;
        }
    }
}

int main()
{
    cout<<"enter num of elements"<<endl;
    int n;
    cin>>n;
    cout<<"enter an integer array"<<endl;
    int arr[n];
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    counrSort(arr, n);

    cout<<"sorted integer array :-"<<endl;  
    for(int j=0; j<n; j++){
        cout<<arr[j]<<" ";
    }

    return 0;
}
///////////////////////////////////////////
#include <iostream>
#include <math.h>
using namespace std;

void Merge(int *A, int l,int mid, int h ){
    int i,j,k;
    int B[mid++];
    /*
    int m=0;
    for(int z=mid+1;z<=h;z++){
        B[m++] = A[z];
    }
    */
    i=l;    j=mid+1;    k=l;
    while(i<=mid && j<=h){
        if(A[i] < A[j]){
            B[k++] = A[i++];
        }else{
            B[k++] = A[j++];
        }
        for(; i<=mid ; i++){
            B[k++]=A[i];
        }
        for(; j<=mid ; j++){
            B[k++]=A[j];
        }
        
        for(i=l ; i<=h; i++) A[i] = B[i];
    }
}

void mergerSort(int* ar, int n){
    int p,i,mid,l,h;
    
    for(p=2; p<=n; p=p*2){
        for(i=0; i+p-1<n; i=i+p){
            l=i;
            h=i+p-1;
            mid = floor((l+h)/2);
            Merge(ar, l,mid, h);
        }
    }
    if((p/2) < n){
    Merge(ar, 0,p/2, n-1);
    } 
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    mergerSort(arr, n);
    
    for(int j=0; j<n;j++){
        cout<<arr[j]<<" ";
    }

    return 0;
}

