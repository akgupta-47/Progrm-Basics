//////////////////////////////////////
// stack basic funs
#include <iostream>

using namespace std;
class Stack{
    public:
    int size;
    int top;
    int *s;
};

int isEmpty(Stack st){
    if(st.top == -1){
        cout<<"stack is already empty\n";
        return 1;
    }else{
        return 0;
    }
}

int isFull(Stack st){
    if(st.top == st.size-1){
        cout<<"the stack is full\n";
        return 1;
    }else{
        return 0;
    }
}

int peek(Stack st,int pos){
    int x=-1;
    if(st.top-pos+1<0){
        cout<<"Invalid position\n";
    }else{
        x=st.s[st.top-pos+1];
    }
    return x;
}

void pop(Stack *st){
    if(st->top == -1){
        cout<<"stack is already empty\n";
    }else{
        cout<<"the value at current position "<<st->s[s->top]<<" is pooped out\n";
        st->s[st->top] = NULL;
        st->top--;
    }
}

void push(Stack *st, int x){
    if(st->top == st->size - 1){
        cout<<"the stack is full\n";
    }else{
        st->top++;
        st->s[st->top] = x;
    }
}

int main()
{
    Stack st;
    cout<<"Enter the size of the Stack : ";
    cin>>st.size;
    st.s = new int[size];
    st.top = -1;
    push(&st, n);
    pop(&st);
    return 0;
}
//////////////////////////////////////////////////
// 2
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
class Stack{
    public:
    int size;
    int top;
    char *s;
};

void Display(Stack st){
    while(st.top != st.size-1){
        cout<<st.s[++st.top];
    }
}

int main()
{
    Stack st;
    string stk;
    cout<<"enter the string\n";
    getline(cin,stk);
    st.size = stk.length();
    st.top = -1;
    for(int i=st.size; i>=0; i--){
        if(st.top == st.size - 1){
            cout<<"the stack is full\n";
        }else{
            st.top++;
            st.s[st.top] = stk[i];
        }
    }
    st.top = -1;
    Display(st);
    return 0;
}

