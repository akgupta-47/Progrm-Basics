#include <iostream>

using namespace std;
class Node {
    public:
    int data;
    int height;
    Node *lft;
    Node *rgt;
};
Node* root=NULL;

int NodeHeight(Node *p){
    int hl, hr;
    hl = p && p->lft ? p->lft->height : 0;
    hr = p && p->rgt ? p->rgt->height : 0;
    
    return hl > hr ? hl+1 : hr+1;
}

int BalanceFactor(Node *p){
    int hl, hr;
    hl = p && p->lft ? p->lft->height : 0;
    hr = p && p->rgt ? p->rgt->height : 0;
    
    return hl - hr;
}

Node * LLrotation(Node *p){
    Node *pl = p->lft;
    Node *plr = pl->rgt;
    
    pl->rgt = p;
    p->lft = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    
    if(root == p){
        root = pl;
    }
    
    return pl;
}

Node * LRrotation(Node *p){
    Node *pl = p->lft;
    Node *plr = pl->rgt;
    
    pl->rgt = plr->lft;
    p->lft = plr->rgt;
    
    plr->lft = pl;
    plr->rgt = p;
    
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);
    
    if(root == p){
        root = plr;
    }
    
    return plr;
}

Node * Insert(Node *p, int key){
    Node *t = NULL;
    if(p == NULL){
        t = new Node;
        t->data = key;
        t->height = 1;
        t->lft = t->rgt = NULL;
        return t;
    }
    if(key < p->data)
        p->lft = Insert(p->lft, key);
    else if(key > p->data)
        p->rgt = Insert(p->rgt, key);
        
    p->height = NodeHeight(p);
    if( BalanceFactor(p) == 2 && BalanceFactor(p->lft) == 1 )
        return LLrotation(p);
    else if( BalanceFactor(p) == 2 && BalanceFactor(p->lft) == -1 )
        return LRrotation(p);
    /*
    else if( BalanceFactor(p) == -2 && BalanceFactor(p->rgt) == -1 )
        return RRrotation(p);
    else if( BalanceFactor(p) == -2 && BalanceFactor(p->rgt) == 1 )
        return RLrotation(p);
    */
    return p;
}


Node *InOrdPreChld(Node* p){
    while(p && p->rgt != NULL){
        p = p->rgt;
    }
    return p;
}

Node *InOrdSuccChld(Node* p){
    while(p && p->lft != NULL){
        p = p->lft;
    }
    return p;
}

Node* Delete(Node *p, int key) {
    if (p == nullptr){
        return nullptr;
    }
 
    if (p->lft == nullptr && p->rgt == nullptr){
        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
 
    if (key < p->data){
        p->lft = Delete(p->lft, key);
    } else if (key > p->data){
        p->rgt = Delete(p->rgt, key);
    } else {
        Node* q;
        if (NodeHeight(p->lft) > NodeHeight(p->rgt)){
            q = InOrdPreChld(p->lft);
            p->data = q->data;
            p->lft = Delete(p->lft, q->data);
        } else {
            q = InOrdSuccChld(p->rgt);
            p->data = q->data;
            p->rgt = Delete(p->rgt, q->data);
        }
    }
 
    // Update height
    p->height = NodeHeight(p);
 
    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lft) == 1) {  // L1 Rotation
        return LLrotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lft) == -1){  // L-1 Rotation
        return LRrotation(p);
    }/*
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){  // R-1 Rotation
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){  // R1 Rotation
        return RLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0){  // L0 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0){  // R0 Rotation
        return RRRotation(p);
    }
 */
    return p;
}

void InorderTrav(Node *p){
    if(p){
        InorderTrav(p->lft);
        cout<<p->data<<" ";
        InorderTrav(p->rgt);
    }
}

int main()
{
    cout<<"Enter the number elements"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the elements"<<endl;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if( root == NULL ){
            root = Insert(root, x);
            continue;
        }
        Insert(root, x);
    }
    
    cout<<"enter node for Deletion"<<endl;
    int delKey;
    cin>>delKey;
    Delete(root, delKey);
    
    InorderTrav(root);

    return 0;
}

