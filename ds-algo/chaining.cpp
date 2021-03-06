#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void SortedInsert(Node **H, int x)
{
    Node *t, *q = NULL, *p = *H;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if (*H == NULL)
        *H = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
    }
}

int hashFun(int key)
{
    return key % 10;
}

// i am currently stuck at problem of inserting in chain and inserting at first or last position in chain
// use vs code to debug every step
void InsertChain(Node *H[], int key)
{
    int index = hashFun(key);
    Node *t, *q = NULL, *p = H[index];
    t = new Node;
    t->data = key;
    t->next = NULL;

    if (H[index] == NULL)
        H[index] = t;
    else
    {
    }
}

int main()
{
    Node *HT[10];
    int i;

    for (i = 0; i < 10; i++)
        HT[i] = NULL;

    return 0;
}
