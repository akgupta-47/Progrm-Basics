/* Binary Search Tree 
No duplicates
In order ges sorted order 
2nCn/n+1 trees can be generated
time needed depends on height of tree
max compariosns for searching depend on height of the tress
log(n) <= h <= n
unsucessful search = height of tree comparisons*/

//////////////////////////////////////////////////////////////////
// Insert - Search - Delete
#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node *lft;
    Node *rgt;
};
Node *root = NULL;

void Insert(int key)
{
    // initialise a temp for node traversal
    Node *temp = root;
    // r, p are initilised and p always creates the node
    // r is always following temp and actually updating new nodes
    Node *r, *p;

    // insert if root is first node
    if (root == NULL)
    {
        p = new Node;
        p->data = key;
        p->lft = p->rgt = NULL;
        root = p;
        return;
    }
    // bring the temp to last node level
    while (temp != NULL)
    {
        // keepin r always one node above
        r = temp;
        if (key < temp->data)
            temp = temp->lft;
        else if (key > temp->data)
            temp = temp->rgt;
        else
            return;
    }
    // make a new node
    p = new Node;
    p->data = key;
    p->lft = p->rgt = NULL;

    // assign the node to r's left or right
    if (key < r->data)
        r->lft = p;
    else
        r->rgt = p;
}

void InorderTrav(Node *p)
{
    if (p)
    {
        InorderTrav(p->lft);
        cout << p->data << " ";
        InorderTrav(p->rgt);
    }
}
int search(int key)
{
    int pos = 1;
    Node *t = root;
    while (t != NULL)
    {
        if (t->data == key)
        {
            return pos;
        }
        else if (t->data < key)
        {
            pos++;
            t = t->rgt;
        }
        else
        {
            pos++;
            t = t->lft;
        }
    }
    return -1;
}

int Height(Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = Height(p->lft);
    y = Height(p->rgt);
    return x > y ? x + 1 : y + 1;
}

Node *InOrdPreChld(Node *p)
{
    while (p && p->rgt != NULL)
    {
        p = p->rgt;
    }
    return p;
}

Node *InOrdSuccChld(Node *p)
{
    while (p && p->lft != NULL)
    {
        p = p->lft;
    }
    return p;
}

Node *Delete(Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->lft == NULL && p->rgt == NULL)
    {
        if (p == root)
            root = NULL;
        delete (p);
        return NULL;
    }

    Node *q;
    if (key < p->data)
    {
        p->lft = Delete(p->lft, key);
    }
    else if (key > p->data)
    {
        p->rgt = Delete(p->rgt, key);
    }
    else
    {
        if (Height(p->lft) > Height(p->rgt))
        {
            q = InOrdPreChld(p->lft);
            p->data = q->data;
            p->lft = Delete(p->lft, q->data);
        }
        else
        {
            q = InOrdSuccChld(p->rgt);
            p->data = q->data;
            p->rgt = Delete(p->rgt, q->data);
        }
    }
    return p;
}

int main()
{
    cout << "enter total numbers to be inserted : " << endl;
    int n, val;
    cin >> n;

    cout << "enter the value to be inserted" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        Insert(val);
    }

    int delVal;
    cout << "enter the value to be deleted " << endl;
    cin >> delVal;
    Delete(root, delVal);

    cout << "the values are in sorted order " << endl;
    InorderTrav(root);

    /*
    int find;
    cout<<"\nenter value to find"<<endl;
    cin>>find;
    int x = search(find);
    if(x != -1){
        cout<<"key found at height below root : "<<x;
    }else{
        cout<<"key not found";
    }
    */

    return 0;
}
/////////////////////////////////////////////////////////////
// preorder
// time is O(n)
#include <iostream>
#include <stack>

using namespace std;
class Node
{
public:
    int data;
    Node *lft;
    Node *rgt;
};
Node *root = NULL;

void createPre(int pre[], int n)
{
    int i = 0;
    root = new Node;
    root->data = pre[i++];
    root->lft = root->rgt = NULL;

    Node *t;
    Node *p = root;
    stack<Node *> stk;

    while (i < n)
    {
        if (pre[i] < p->data)
        {
            t = new Node;
            t->data = pre[i++];
            t->lft = t->rgt = NULL;
            p->lft = t;
            stk.push(p);
            p = t;
        }
        else
        {
            if (pre[i] > p->data && pre[i] < stk.empty() ? 32767 : stk.top()->data)
            {
                t = new Node;
                t->data = pre[i++];
                t->lft = t->rgt = NULL;
                p->rgt = t;
                p = t;
            }
            else
            {
                p = stk.top();
                stk.pop();
            }
        }
    }
}

void InorderTrav(Node *p)
{
    if (p)
    {
        InorderTrav(p->lft);
        cout << p->data << " ";
        InorderTrav(p->rgt);
    }
}

int main()
{
    cout << "enter total numbers to be inserted : " << endl;
    int n;
    cin >> n;
    int pre[n];

    cout << "enter the value to be inserted" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    createPre(pre, n);

    InorderTrav(root);

    return 0;
}
// the drawback of BST is that its height depends on arrangements of keys and can be small as log2N or N
