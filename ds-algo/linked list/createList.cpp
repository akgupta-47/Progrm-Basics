#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};
Node *Head = NULL;

void createList(int x){
    Node *p, *t = new Node;
    t->data = x;
    t->next = NULL;
    
    if(Head == NULL){
        Head = t;
        return;
    }
    p=Head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = t;
}

void Display(Node *p){
    while(p!=NULL){
        cout<<p->data<<"\n";
        p=p->next;
    } 
}

int main()
{
    cout<<"Enter number of elements"<<endl;
    int noe;
    cin>>noe;
    cout<<"Enter elements"<<endl;
    int x,i;
    for(i=0; i<noe; i++){
        cin>>x;
        createList(x);
    }
    Display(Head);
    return 0;
}
