///////////////////////////////////
// insert circular
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void Display(Node *head){
    Node *p = head;
    cout<<"now display the list\n";
    do{
        cout<<p->data<<"\t";
        p=p->next;}
    while(p!=head);
}

void Insert(Node *head,int n){
    Node *p = head;
    Node *t = new Node;
    cout<<"enter the new node to be inserted\n";
    cin>>t->data;
    t->next = NULL;
    if(n==1){
        while(p->next!=head){
            p=p->next;
        }
        p->next=t;
        t->next = head;
        head=t;
    }else{
       for(int i=0;i<n-1;i++){
           p=p->next;
       }
       t->next = p->next;
       p->next = t;
    }
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
    last->next = first;
    cout<<"Enter the position to be inserted\n";
    cin>>pos;
    Insert(first,pos);
    return 0;
}
/////////////////////////////////////////////////////////
// insert doubly
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;
};

void Display(Node *head){
    Node *p = head;
    cout<<"now display the list\n";
    while(p!=NULL){
        cout<<p->data<<"\t";
        p=p->next;
    }
}

void Insert(Node *head,int n){
    Node *p = head;
    Node *t = new Node;
    cout<<"enter the new node to be inserted\n";
    cin>>t->data;
    t->next = NULL;
    t->prev = NULL;
    if(n==1){
        t->next=head;
        head->prev=t;
        head=t;
    }else{
       for(int i=0;i<n-1;i++){
           p=p->next;
       }
       t->next = p->next;
       t->prev = p;
       p->next = t;
    }
    Display(head);
}

int main()
{
    Node *first=new Node;
    Node *last= NULL;
    cout<<"Enter value in first node\n";
    cin>>first->data;
    first->next = NULL;
    first->prev = NULL;
    last = first;
    Node *iter=first;
    int n,i,pos;
    cout<<"enter no of nodes\n";
    cin>>n;
    // create nodes to be inserted
    for(i=1;i<n;i++){
        Node *t = new Node;
        t->prev = iter;
        iter=t;
        cout<<"Enter value of inserted Node\n";
        cin>>t->data;
        t->next = NULL;
        last->next = t;
        last = t;
    }
    cout<<"Enter the position to be inserted\n";
    cin>>pos;
    Insert(first,pos);
    return 0;
}
/////////////////////////////////////////////////////////////
// delete circular
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void Display(Node *head){
    Node *p = head;
    cout<<"now display the list\n";
    do{
        cout<<p->data<<"\t";
        p=p->next;}
    while(p!=head);
}

void Delete(Node *head,int n){
    Node *p = head;
    Node *t = NULL;
    if(n==1){
        while(p->next!=head){
            p=p->next;
        }
        p->next=head->next;
        delete head;
        head=p->next;
    }else{
       for(int i=0;i<n-2;i++){
           p=p->next;
       }
       t = p->next;
       p->next = t->next;
       delete t;
    }
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
    last->next = first;
    cout<<"Enter the position to be deleted\n";
    cin>>pos;
    Delete(first,pos);
    return 0;
}
//////////////////////////////////////////////////////////////
// delete doubly
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;
};

void Display(Node *head){
    Node *p = head;
    cout<<"now display the list\n";
    while(p!=NULL){
        cout<<p->data<<"\t";
        p=p->next;
    }
}

void Delete(Node *head,int n){
    Node *p = head;
    Node *t = NULL;
    if(n==1){
        p=p->next;
        head->next=NULL;
        p->prev=NULL;
        delete head;
        head=p;
    }else{
        for (int i=0; i<n-1; i++){
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next){
            p->next->prev = p->prev;
        }
        delete p;
    }
    Display(head);
}

int main()
{
    Node *first=new Node;
    Node *last= NULL;
    cout<<"Enter value in first node\n";
    cin>>first->data;
    first->next = NULL;
    first->prev = NULL;
    last = first;
    Node *iter=first;
    int n,i,pos;
    cout<<"enter no of nodes\n";
    cin>>n;
    // create nodes to be inserted
    for(i=1;i<n;i++){
        Node *t = new Node;
        t->prev = iter;
        iter=t;
        cout<<"Enter value of inserted Node\n";
        cin>>t->data;
        t->next = NULL;
        last->next = t;
        last = t;
    }
    cout<<"Enter the position to be deleted\n";
    cin>>pos;
    Delete(first,pos);
    return 0;
}
//////////////////////////////////////////////////////
// search circular
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

int Search(Node *head,int n){
    Node *p = head;
    int count=0;
    do{
        count = count+1;
        if(p->data == n){
            return count;
        };
        p=p->next;}
    while(p!=head);
    return -1;
}

int main()
{
    Node *first=new Node;
    Node *last= NULL;
    cout<<"Enter value in first node\n";
    cin>>first->data;
    first->next = NULL;
    last = first;
    int n,i,value;
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
    last->next = first;
    cout<<"Enter the value to be found\n";
    cin>>value;
    if(Search(first,value) != -1){
        cout<<"The value was found at position : "<<Search(first,value);
    }else{
        cout<<"Value not found";
    }
    return 0;
}
//////////////////////////////////////////////////////////////
// search doubly
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;
};

int Search(Node *head,int n){
    Node *p = head;
    int count = 0;
    while(p!=NULL){
        count++;
        if(p->data == n){
            return count;
        }else{
            p=p->next;
        }
    }
    return -1;
}

int main()
{
    Node *first=new Node;
    Node *last= NULL;
    cout<<"Enter value in first node\n";
    cin>>first->data;
    first->next = NULL;
    first->prev = NULL;
    last = first;
    Node *iter=first;
    int n,i,value;
    cout<<"enter no of nodes\n";
    cin>>n;
    // create nodes to be inserted
    for(i=1;i<n;i++){
        Node *t = new Node;
        t->prev = iter;
        iter=t;
        cout<<"Enter value of inserted Node\n";
        cin>>t->data;
        t->next = NULL;
        last->next = t;
        last = t;
    }    
    cout<<"Enter the value to be found\n";
    cin>>value;
    if(Search(first,value) != -1){
        cout<<"The value was found at position : "<<Search(first,value);
    }else{
        cout<<"Value not found";
    }
    return 0;
}
///////////////////////////////////////////
// display head twice
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

int DisplayHead(Node *head){
    Node *p = head;
    cout<<"now display the list\n";
    cout<<p->data<<"\t";
    p=p->next;
    while(p!=NULL){
        cout<<p->data<<"\t";
        p=p->next;
        if(p->next == head){
            cout<<p->data<<"\t"<<head->data;
            break;
        }
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
    last->next = first;
    DisplayHead(first);
    return 0;
}
/////////////////////////////////////////////
// count nodes doubly
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;
};

int CountNodes(Node *head){
    Node *p = head;
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count; 
}

int main()
{
    Node *first=new Node;
    Node *last= NULL;
    cout<<"Enter value in first node\n";
    cin>>first->data;
    first->next = NULL;
    first->prev = NULL;
    last = first;
    Node *iter=first;
    int n,i;
    cout<<"enter no of nodes\n";
    cin>>n;
    // create nodes to be inserted
    for(i=1;i<n;i++){
        Node *t = new Node;
        t->prev = iter;
        iter=t;
        cout<<"Enter value of inserted Node\n";
        cin>>t->data;
        t->next = NULL;
        last->next = t;
        last = t;
    }    
    cout<<"The number of nodes are : "<<CountNodes(first);
    return 0;
}
////////////////////////////////////
// count nodes circular
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

int CountNodes(Node *head){
    Node *p = head;
    int count = 0;
    do{
        count++;
        p=p->next;}
    while(p!=head);
    return count;
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
    last->next = first;
    cout<<"The number of nodes are : "<<CountNodes(first);
    return 0;
}
///////////////////////////////////////
// doubly palindrome list
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;
};

int checkPalindrome(Node *head){
    Node *p = head;
    Node *q = head;
    while(q->next!=NULL){
        q=q->next;
    }
    while(p!=NULL){
        if(p->data == q->data){
            p=p->next;
            q=q->prev;
        }else{
            return -1;
        }
    }
    return 1;
}

int main()
{
    Node *first=new Node;
    Node *last= NULL;
    cout<<"Enter value in first node\n";
    cin>>first->data;
    first->next = NULL;
    first->prev = NULL;
    last = first;
    Node *iter=first;
    int n,i;
    cout<<"enter no of nodes\n";
    cin>>n;
    // create nodes to be inserted
    for(i=1;i<n;i++){
        Node *t = new Node;
        t->prev = iter;
        iter=t;
        cout<<"Enter value of inserted Node\n";
        cin>>t->data;
        t->next = NULL;
        last->next = t;
        last = t;
    } 
    if(checkPalindrome(first) != -1){
        cout<<"The list is palindrome ";
    }else{
        cout<<"the list is not palindrome";
    }
    return 0;
}
//////////////////////////////
// check list circular
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

int checkCircular(Node *head){
    Node *p = head->next;
    while(p!=NULL){
        if(p->next == head){
            return 1;
        }
        p=p->next;
    }
    return -1;
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
    last->next = first;
    if(checkCircular(first) != -1){
        cout<<"The list is Circular ";
    }else{
        cout<<"the list is not Circular";
    }
    return 0;
}
/////////////////////////////////////////////
// split linked list
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void Display(Node *head){
    Node *p = head;
    cout<<"now display the list\n";
    do{
        cout<<p->data<<"\t";
        p=p->next;}
    while(p!=head);
}

void splitCircular(Node *head){
    Node *p = head;
    Node *slow=head;
    Node *fast=head;
    
    do{
        fast=fast->next->next;
        slow=slow->next;
    }while(fast->next->next!=head);
    fast=fast->next;
    p=slow->next;
    fast->next=p;
    slow->next = head;
    cout<<"The first half is \n";
    Display(head);
    cout<<"\nThe Second half is\n";
    Display(p);
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
    last->next = first;
    splitCircular(first);
    return 0;
}
//////////////////////////////
// reverse random
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next, *prev;
};

void Display(Node *head){
    Node *p = head;
    cout<<"now display the list\n";
    while(p!=NULL){
        cout<<p->data<<"\t";
        p=p->next;
    }
}

void reverseSection(Node *head, int n){
    Node *newHd = head;
    Node *p = NULL;
    Node *prevHd = NULL;
    Node *q=NULL;
    for(int i=1; i<n;i++){
        newHd=newHd->next;
    }

    p = newHd;
    q=newHd->next;
    newHd->next->prev = NULL;
    newHd->next = NULL;
    while(p->prev!=NULL){
        p->next = p->prev;
        p->prev = prevHd;
        prevHd = p;
        p = p->next;
    }
    
    head->next = q;
    q->prev = head;
    head = newHd;
    Display(head);
}

int main()
{
    Node *first=new Node;
    Node *last= NULL;
    cout<<"Enter value in first node\n";
    cin>>first->data;
    first->next = NULL;
    first->prev = NULL;
    last = first;
    Node *iter=first;
    int n,i,pos;
    cout<<"enter no of nodes\n";
    cin>>n;
    // create nodes to be inserted
    for(i=1;i<n;i++){
        Node *t = new Node;
        t->prev = iter;
        iter=t;
        cout<<"Enter value of inserted Node\n";
        cin>>t->data;
        t->next = NULL;
        last->next = t;
        last = t;
    }
    cout<<"enter position from where reverse occurs :\t";
    cin>>pos;
    reverseSection(first, pos);
    return 0;
}
