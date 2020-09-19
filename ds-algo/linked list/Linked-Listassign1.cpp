/////////////////////////////////
//insert at start
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void Display(Node *p){
    while(p!=NULL){
        cout<<p->data<<"\n";
        p=p->next;
    } 
}

int main()
{
    Node *first=new Node;
    cout<<"Enter value in first node\n";
    cin>>first->data;
    first->next = NULL;
    // create node to be inserted
    Node *t = new Node;
    cout<<"Enter value of inserted Node\n";
    cin>>t->data;
    t->next = first;
    first = t;
    // display lined list
    Display(first);
    return 0;
}
//////////////////////////////////////////
//insert at last
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void Display(Node *p){
    cout<<"now display the list\n";
    while(p!=NULL){
        cout<<p->data<<"\n";
        p=p->next;
    } 
}

void Insert(Node *first){
    Node *q = new Node;
    Node *r;
    cout<<"enter value at new inserted node\n";
    cin>>q->data;
    q->next = NULL;
    r=first;
    while(r->next!=NULL){r=r->next;}
    r->next=q;
    // display lined list
    Display(first);
}

int main()
{
    Node *first=new Node;
    Node *last= NULL;
    cout<<"Enter value in first node\n";
    cin>>first->data;
    first->next = NULL;
    last = first;
    int n,i;
    cout<<"enter no of nodes\n";
    cin>>n;
    // create nodes to be inserted
    for(i=1;i<n;i++){
        Node *t = new Node;
        cout<<"Enter value of inserted Node\n";
        cin>>t->data;
        t->next = NULL;
        last->next = t;
        last = t;
    }
    Insert(first);
    return 0;
}
////////////////////////////////////////
//insert at random 
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void Display(Node *p){
    cout<<"now display the list\n";
    while(p!=NULL){
        cout<<p->data<<"\n";
        p=p->next;
    } 
}

void Insert(Node *first,int pos){
    Node *q = new Node;
    Node *r;
    cout<<"enter value at new inserted node\n";
    cin>>q->data;
    q->next = NULL;
    r=first;
    for(int i=0;i<pos-2;i++){r=r->next;}
    q->next = r->next;
    r->next=q;
    // display lined list
    Display(first);
}

int main()
{
    Node *first=new Node;
    Node *last= NULL;
    cout<<"Enter value in first node\n";
    cin>>first->data;
    first->next = NULL;
    last = first;
    int n,i,pos;
    cout<<"enter no of nodes\n";
    cin>>n;
    // create nodes to be inserted
    for(i=1;i<n;i++){
        Node *t = new Node;
        cout<<"Enter value of inserted Node\n";
        cin>>t->data;
        t->next = NULL;
        last->next = t;
        last = t;
    }
    cout<<"enter insertion position\n";
    cin>>pos;
    Insert(first,pos);
    return 0;
}
//////////////////////////////////////////////////////
//delete from start
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void Display(Node *p){
    cout<<"now display the list\n";
    while(p!=NULL){
        cout<<p->data<<"\n";
        p=p->next;
    } 
}

void DeletBegin(Node *first){
    Node *ptr;
    if(first == NULL)  
    {  
        cout<<"\nList is empty";  
    }  
    else   
    {  
        ptr = first;  
        first = ptr->next;  
        delete ptr;
    }  
    Display(first);
}

int main()
{
    Node *first=new Node;
    Node *last= NULL;
    cout<<"Enter value in first node\n";
    cin>>first->data;
    first->next = NULL;
    last = first;
    int n,i;
    cout<<"enter no of nodes\n";
    cin>>n;
    // create nodes to be inserted
    for(i=1;i<n;i++){
        Node *t = new Node;
        cout<<"Enter value of inserted Node\n";
        cin>>t->data;
        t->next = NULL;
        last->next = t;
        last = t;
    }

    DeletBegin(first);
    return 0;
}
////////////////////////////////////////////////////
//delete end
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void Display(Node *p){
    cout<<"now display the list\n";
    while(p!=NULL){
        cout<<p->data<<"\n";
        p=p->next;
    } 
}

void Delete(Node *first, int pos){
    Node *p = first;
    Node *q = NULL;
    for(int i=0;i<pos-1;i++){
        q=p;
        p=p->next;
    }
    q->next = p->next;
    delete p;
    Display(first);
}

int main()
{
    Node *first=new Node;
    Node *last= NULL;
    cout<<"Enter value in first node\n";
    cin>>first->data;
    first->next = NULL;
    last = first;
    int n,i,pos;
    cout<<"enter no of nodes\n";
    cin>>n;
    // create nodes to be inserted
    for(i=1;i<n;i++){
        Node *t = new Node;
        cout<<"Enter value of inserted Node\n";
        cin>>t->data;
        t->next = NULL;
        last->next = t;
        last = t;
    }
    cout<<"enter position to be deleted\n";
    cin>>pos;
    Delete(first,n);
    return 0;
}
///////////////////////////////////////////////////////
//delete random
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void Display(Node *p){
    cout<<"now display the list\n";
    while(p!=NULL){
        cout<<p->data<<"\n";
        p=p->next;
    } 
}

void Delete(Node *first, int pos){
    Node *p = first;
    Node *q = NULL;
    for(int i=0;i<pos-1;i++){
        q=p;
        p=p->next;
    }
    q->next = p->next;
    delete p;
    Display(first);
}

int main()
{
    Node *first=new Node;
    Node *last= NULL;
    cout<<"Enter value in first node\n";
    cin>>first->data;
    first->next = NULL;
    last = first;
    int n,i,pos;
    cout<<"enter no of nodes\n";
    cin>>n;
    // create nodes to be inserted
    for(i=1;i<n;i++){
        Node *t = new Node;
        cout<<"Enter value of inserted Node\n";
        cin>>t->data;
        t->next = NULL;
        last->next = t;
        last = t;
    }
    cout<<"enter position to be deleted\n";
    cin>>pos;
    Delete(first,pos);
    return 0;
}
////////////////////////////////////////////////////////////////
//search a value
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void Display(Node *p){
    cout<<"now display the list\n";
    while(p!=NULL){
        cout<<p->data<<"\n";
        p=p->next;
    } 
}

void Search(Node *first, int key){
    Node *p=first;
    int count = 1;
    while(p!=NULL){
        if(p->data == key) cout<<"The element is fount at : "<<count<<" considering position of head : 1\n";
        count++;
        p=p->next;
    }
    //Display(first);
}

int main()
{
    Node *first=new Node;
    Node *last= NULL;
    cout<<"Enter value in first node\n";
    cin>>first->data;
    first->next = NULL;
    last = first;
    int n,i,key;
    cout<<"enter no of nodes\n";
    cin>>n;
    // create nodes to be inserted
    for(i=1;i<n;i++){
        Node *t = new Node;
        cout<<"Enter value of inserted Node\n";
        cin>>t->data;
        t->next = NULL;
        last->next = t;
        last = t;
    }
    cout<<"enter value to be found\n";
    cin>>key;
    Search(first,key);
    return 0;
}
//////////////////////////////////////////////
// remove particular duplicates
#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
};
Node *head, *prevNode, *temp;
void deleteParticular(Node *head, int n){
    temp = head;
    prevNode = NULL;
    int c = 0;
    while(temp!=NULL)
    {
        if(temp->data == n)
        {
            c++;
            if(prevNode == NULL)
            {
                head = temp->next;
                delete temp;
                temp = head;
                continue;
            }
            else if(temp->next == NULL)
            {
                prevNode->next = NULL;
                delete temp;
                break;
            }
            else 
            {
                prevNode->next = temp->next;
                delete temp;
                temp = prevNode->next;
                continue;
            }
        }
        prevNode = temp;
        temp = temp->next;
    }
    cout<<"There were "<<c<<" number of "<<n<<" in the linked list. After deletion of all occurrences of "<<n<<", the linked list is: ";
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main()
{
    int n;
    cout<<"Enter the number of nodes in the linked list: ";
    cin>>n;
    cout<<"Enter the elements of the linked list:\n";
    for(int i=0; i<n; i++)
    {
        Node *newNode = new Node();
        cin>>newNode->data;
        if(i==0)
            head = newNode;
        else
        prevNode->next = newNode;
        prevNode = newNode;
    }
    temp = head;
    cout<<"The linked-list entered is: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\nEnter the element whose occurrences are to be counted and deleted from the linked-list: ";
    cin>>n;
    deleteParticular(head, n);
    delete head,temp,prevNode;
    return 0;
}
////////////////////////////////////////////////////////////////
//find middle
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void printMiddle(Node *head)
{
    Node *slow=head;
    Node *fast=head;
 
    if (head!=NULL)
    {
        while (fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        cout<<"The middle element is : \n"<<slow->data;
    }
}

int main()
{
    Node *first=new Node;
    Node *last= NULL;
    cout<<"Enter value in first node\n";
    cin>>first->data;
    first->next = NULL;
    last = first;
    int n,i,key;
    cout<<"enter no of nodes\n";
    cin>>n;
    // create nodes to be inserted
    for(i=1;i<n;i++){
        Node *t = new Node;
        cout<<"Enter value of inserted Node\n";
        cin>>t->data;
        t->next = NULL;
        last->next = t;
        last = t;
    }

    printMiddle(first);
    return 0;
} 
/////////////////////////////////////////////
//reverse list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void Display(Node *p)
{
    cout << "now display the list\n";
    while (p != NULL)
    {
        cout << p->data << "\n";
        p = p->next;
    }
}

void reverse(Node *head)
{
    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
    Display(head);
}

int main()
{
    Node *first = new Node;
    Node *last = new Node;
    cout << "Enter value in first node\n";
    cin >> first->data;
    first->next = NULL;
    last = first;
    int n, i;
    cout << "enter no of nodes\n";
    cin >> n;
    // create nodes to be inserted
    for (i = 1; i < n; i++)
    {
        Node *t = new Node;
        cout << "Enter value of inserted Node\n";
        cin >> t->data;
        t->next = NULL;
        last->next = t;
        last = t;
    }

    reverse(first);
    return 0;
}
/////////////////////////////////////////////////////
//check sorted list
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void checkSort(Node *head){
    int x=0;
    int flag = 1;
    while(head!=NULL){
        if(head->data>=x){
            x=head->data;
            head = head->next;
        }else{
            cout<<"list is unsorted";
            flag=0;
            return;
        }
    }
    if(flag == 1){
        cout<<"list is sorted\n";
    }
}

int main()
{
    Node *first=new Node;
    Node *last= NULL;
    cout<<"Enter value in first node\n";
    cin>>first->data;
    first->next = NULL;
    last = first;
    int n,i,pos;
    cout<<"enter no of nodes\n";
    cin>>n;
    // create nodes to be inserted
    for(i=1;i<n;i++){
        Node *t = new Node;
        cout<<"Enter value of inserted Node\n";
        cin>>t->data;
        t->next = NULL;
        last->next = t;
        last = t;
    }
    cout<<"lets check if list is sorted\n";
    checkSort(first);
    return 0;
}
//////////////////////////////////////////////////////
//try 1 Q5
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void Display(Node *p)
{
    cout << "now display the list\n";
    while (p != NULL)
    {
        cout << p->data << "\n";
        p = p->next;
    }
}

void randomReverse(Node *head,int m,int n){
    Node *p,*store1,*store2,*currentLast;
    p=head;
    currentLast = head;
    int i;
    for(i=1;i<m;i++){
        p=p->next;
    }
    for(i=1;i<n;i++){
        currentLast=currentLast->next;
    }
    store1 = p;
    p=p->next;
    store2 = p;
    Node *q = NULL;
    Node *r = NULL;
    for(i=m+1;i<n-1;i++){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    p->next = store1;
    store2->next = currentLast;
    Display(head);
}

int main()
{
    Node *first=new Node;
    Node *last= NULL;
    cout<<"Enter value in first node\n";
    cin>>first->data;
    first->next = NULL;
    last = first;
    int z,i;
    cout<<"enter no of nodes\n";
    cin>>z;
    // create nodes to be inserted
    for(i=1;i<z;i++){
        Node *t = new Node;
        cout<<"Enter value of inserted Node\n";
        cin>>t->data;
        t->next = NULL;
        last->next = t;
        last = t;
    }
    cout<<"enter m and n\n";
    int m,n;
    cin>>m>>n;
    if(1 <= m <= n <= z){
        randomReverse(first,m,n);   
    }
    return 0;
}
////////////////////////////////////////////////////////
// rotate list
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void Display(Node *p)
{
    cout << "now display the list\n";
    while (p != NULL)
    {
        cout << p->data << "\n";
        p = p->next;
    }
}

void randomRotate(Node *head,int k){
    int i;
    Node *p=head;
    Node *q=head;
    for(i=1;i<k;i++){
        p=p->next;
    }
    while(q->next!=NULL){
        q=q->next;
    }
    Node *newHead= p->next;
    p->next = NULL; 
    q->next = head;
    Display(newHead);
}

int main()
{
    Node *first=new Node;
    Node *last= NULL;
    cout<<"Enter value in first node\n";
    cin>>first->data;
    first->next = NULL;
    last = first;
    int z,i;
    cout<<"enter no of nodes\n";
    cin>>z;
    // create nodes to be inserted
    for(i=1;i<z;i++){
        Node *t = new Node;
        cout<<"Enter value of inserted Node\n";
        cin>>t->data;
        t->next = NULL;
        last->next = t;
        last = t;
    }
    cout<<"enter k\n";
    int k;
    cin>>k;
    randomRotate(first,m,n);  
    return 0;
}
/////////////////////////////////////////////////
//add polynomials
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    int power;
};

void Display(Node *p)
{
    cout << "now display the list\n";
    while (p != NULL)
    {
        cout << p->data << "x" <<p->power<< " ";
        p = p->next;
    }
    cout<<endl;
}

void polyAdd(Node *first,Node *second,int a[]){
    int i=0;
    while(first!=NULL){
        while(second!=NULL){
            if(first->power = second->power){
                a[i]= first->data + second->data;
                i++;
            }
            second = second->next;
        }
        first = first->next;
    }
}

int createPoly(Node *polyNode){
    Node *last= NULL;
    cout<<"Enter value in first node of this poly\n";
    cin>>polyNode->data;
    polyNode->next = NULL;
    last = polyNode;
    int z,i,powr;
    polyNode->power=0;
    cout<<"enter highest power\n";
    cin>>z;
    // create nodes to be inserted
    for(i=1;i<z;i++){
        Node *t = new Node;
        t->power = 0;
        cout<<"Enter value of power "<<(t->power + i)<<" Node\n";
        cin>>t->data;
        t->next = NULL;
        last->next = t;
        last = t;
        powr = t->power;
    }
    return powr;
}

int main()
{
    Node *first=new Node;
    Node *second=new Node;
    cout<<"create first polynomial\n";
    int prio1=createPoly(first);
    cout<<"create second polynomial\n";
    int prio2=createPoly(second);
    cout<<prio1<<endl<<prio2;
    Display(first);
    Display(second);
    if(prio1>=prio2){
        int arr[prio1];
        polyAdd(first,second,arr); 
    }else{
        int arr[prio2];
        polyAdd(second,first,arr);
    }
    return 0;
}
