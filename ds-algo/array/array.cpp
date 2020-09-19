#include <iostream>
using namespace std;

int main()
{
    int arr1[10];
    int i,z;
    int n=sizeof(arr)/sizeof(arr[0]);
    int arr[11]={2,3,4,5,6,7,8,9,12,13,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"enter your choice"<<endl;
    cin>>z;
    
    switch(z)
    {
    
    case 1: //add element
    for(i=0;i<n;i++){
        cin>>arr1[i];
    }
    break;
    
    case 2: //display array
    for(i=0;i<n;i++){
        cout<<arr1[i];
    }
    break;
    
    case 3://insert in array
    cout<<"enter index and value to be inserted"<<endl;
    int index,value;
    cin>>index>>value;
    for(i=n;i>index;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=value;
    for(i=0;i<n;i++){
        cout<<arr[i]<<' ';
}
    break;

    case 4: // Delete array 
    cout<<"enter index to be deleted"<<endl;
    int index;
    cin>>index;
    for(i=index;i<n;i++){
        arr[i]=arr[i+1];
        arr[n-1]= NULL;
    }
    n--;
    for(i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    break;
    
    case 5: //search in array
    int u,count=0;
    cout<<"enter the value to be searched \n";
    cin>>u;
    for(i=0;i<10;i++){
        count++;
        if(arr[i]==u){
            cout<<"the position is "<<i+1<<" and value is "<<arr[i]<<endl;
            break;
        }
	    else if(count==n){
	    cout<<"element not found";
	    }
    }
    break;
    
    default: cout<<"invalid choice";
    break;
}
    return 0;
}
------------------------------------------------------
#include <iostream>

using namespace std;

int main()
{
    int arr[11]={2,3,4,5,6,7,8,9,12,13,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i,x;
    x=7;
    for(i=0;i<n/2;i++){
        if(arr[i]==x || arr[n-i]==x ||arr[n/2]==x){
            cout<<"found";
            break;
        }
    }
    return 0;
}
----------------------------------------------------
Question 2
#include <iostream>

using namespace std;

int main()
{
  int arr[13]={1,5,7,5,8,10,7,2,3,11,4,5,11};
  int n=sizeof(arr)/sizeof(arr[0]);
  int k,i=0;
  while(i<n)
  {
     int j=i+1;
     while(j<n)
     {
       if(arr[i]==arr[j])
       {
          for(k = j;k<n-1;k++)
             arr[k]=arr[k+1];
          n=n-1;
       }
     else 
        j=j+1;
     }
   i=i+1;
  }
  for(i=0;i<n;i++){
      cout<<arr[i]<<" ";
  }

    return 0;
}
------------------------------------------------
reversing an array

#include <iostream>

using namespace std;

int swap(int &x,int &y){
    int c;
    c=x;
    x=y;
    y=c;
}

int main()
{
  int arr[13]={1,5,7,5,8,10,7,2,3,11,4,5,11};
  int n=sizeof(arr)/sizeof(arr[0]);
  int i = 0;
  for(;i<n/2;i++){
    swap(arr[i],arr[n-1-i]);
  }
  for(i=0;i<n;i++){
      cout<<arr[i]<<" ";
  }

    return 0;
}
---------------------------------------------------
multiply matrices
#include <iostream>

using namespace std;

int main()
{
    int n,m,k,z;
    cout<<"enter the size of matrix\n";
    cin>>m>>n>>z;
    int m1[m][n], m2[n][z], final[m][z];
    cout<<"enter the elements of matrix 1\n";
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>m1[i][j];
        }
    }
    cout<<"enter the elements of matrix 2\n";
    for(i=0;i<n;i++){
        for(j=0;j<z;j++){
            cin>>m2[i][j];
        }
    }
    
    for(i=0;i<m;i++) 
    {
        for(j=0;j<z;j++) 
        { 
            final[i][j]=0; 
            for (k=0;k<n;k++) 
                final[i][j]+=m1[i][k]*m2[k][j]; 
        } 
    } 
    
    cout<<"Display multiplied matrix\n";
    for(i=0;i<m;i++){
        for(j=0;j<z;j++){
            cout<<final[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
-------------------------------------------
transpose of a matrix
#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cout<<"enter the size of matrix\n";
    cin>>m>>n;
    int matrix[m][n];
    cout<<"enter the elements of matrix \n";
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    
    cout<<"Display transposed matrix\n";
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<matrix[j][i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
-----------------------------------------
binary search
#include <iostream>

using namespace std;

int BinarySearch(int arr[],int n,int element){
    int l,mid,h;
    l=0;
    h=n-1;
    while(l<=h){
        mid=(l+h)/2;
        if(element==arr[mid]){
            return mid;
        }
        else if(element<arr[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"enter element to be found\n";
    int element;
    cin>>element;
    if(BinarySearch(arr,n,element)!= -1){
        cout<<"element found";
    }
    else{
        cout<<"element not found";
    }
    return 0;
}
-----------------------------------------------
find missing num in sorted array
#include <iostream>

using namespace std;

int main()
{
    int arr[9]={1,2,3,4,6,7,8,10,11};
    int i,n=sizeof(arr)/sizeof(arr[0]);
    int z=arr[0];
    int step=(arr[n-1]-arr[0])/n;
    for(i=1;i<n;i++){
        z+=step;
        if(arr[i]!=z){
            cout<<"the missing number is "<<(arr[i]+arr[i-1])/2<<endl;
            z+=step;
        }
    }
    return 0;
}
-----------------------------------------------
bubble sort
#include <iostream>

using namespace std;

int main()
{
    int arr[5]={6,9,3,7,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i,j,c;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(arr[i]>arr[j]){
                c=arr[i];
                arr[i]=arr[j];
                arr[j]=c;
            }
        }
    }
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
