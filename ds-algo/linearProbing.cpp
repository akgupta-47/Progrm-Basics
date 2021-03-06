#include <iostream>
using namespace std;
#define SIZE 10

int hashFun(int key){
    return key%SIZE;
}

int probe(int H[],int key){
    int index=hashFun(key);
    int i=0;
    while(H[(index+i)%SIZE]!=0)        
        i++;
    
    return (index+i)%SIZE;
}

void Insert(int H[],int key){
    int index=hashFun(key);
    if(H[index]!=0)        
        index=probe(H,key);    
    
    H[index]=key;
}

int Search(int H[],int key){
    int index=hashFun(key);
    int i=0;
    while(H[(index+i)%SIZE]!=key)        
        i++;
        
    return (index+i)%SIZE;
}

int main(){
    int HT[10]={0};
    int i,x,j;
    cout<<"Enter how many elements you want"<<endl;
    cin>>j;
    cout<<"Enter elements"<<endl;
    for(i = 0; i< j;i++){
        cin>>x;
        Insert(HT, x);
    }
    printf("\nKey found at %d\n",Search(HT,35));
    return 0;
}