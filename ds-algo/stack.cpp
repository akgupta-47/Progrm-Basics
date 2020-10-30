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
///////////////////////////////////////////////////
// parenthesis

#include <iostream>
#include <cstring>
using namespace std;
class Stack{
    public:
    int size;
    int top;
    char *s;
};

int isEmpty(Stack st){
    if(st.top == -1){
        return 1;
    }else{
        return 0;
    }
}

void pop(Stack *st){
    if(st->top == -1){
        cout<<"stack is already empty\n";
    }else{
        st->s[st->top] = NULL;
        st->top--;
    }
}

void push(Stack *st, char x){
    if(st->top == st->size - 1){
        cout<<"the stack is full\n";
    }else{
        st->top++;
        st->s[st->top] = x;
    }
}

// if there are multiple type of brackets likr { [ ( then u can use ascii approach where ()-40,41 and 92,93 [] and above hundred for{}
bool isBalanced(char *pt){
    Stack st;
    st.size = strlen(pt);
    st.top = -1;
    st.s = new char[st.size];
    
    for(int i=0; pt[i]!='\0';i++){
        if(pt[i] == '('){
            push(&st, pt[i]);
        }
        else if(pt[i] == ')'){
            if(isEmpty(st)) return false;
            pop(&st);
        }
    }
    
    return isEmpty(st) ? true : false;
}

int main()
{
    string str;
    cout<<"Enter the string\n";
    getline(cin,str);

    char strk[str.length()]; 
    strcpy(strk, str.c_str()); 

    if(isBalanced(strk)){
        cout<<"the string is balanced\n";
    }else{
        cout<<"the string is not balanced\n";
    }

    return 0;
}
//////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
using namespace std;
class Stack{
    public:
    int size;
    int top;
    char *s;
};

void Display(Stack str){
    while(str.top != str.size-1){
        cout<<str.s[++str.top];
    }
}

void pop(Stack *st){
    if(st->top == -1){
        cout<<"stack is already empty\n";
    }else{
        st->s[st->top] = NULL;
        st->top--;
    }
}

void push(Stack *st, char x){
    if(st->top == st->size - 1){
        cout<<"the stack is full\n";
    }else{
        st->top++;
        st->s[st->top] = x;
    }
}

void reverse(char *pt){
    Stack st;
    st.size = strlen(pt);
    st.top = -1;
    st.s = new char[st.size];
    int count=0;
    for(int i=0; i<st.size;i++){
        if(pt[i] == ' '){
            continue;
            st.size--;
        }
        else{
            push(&st, pt[i]);
            count++;
        }
    }
    // cout<<count;
    Stack stk;
    stk.size = count;
    stk.top = -1;
    stk.s = new char[stk.size];
    
    for(int j=stk.size; j>0; j--){
        push(&stk, st.s[j-1]);
        pop(&st);
    }
    
    stk.top=-1;
    Display(stk);
}

int main()
{
    string str;
    cout<<"Enter the string\n";
    getline(cin,str);

    char strk[str.length()]; 
    strcpy(strk, str.c_str()); 

    reverse(strk);

    return 0;
}
////////////////////////////////////////////////////
//infix and postfix
#include <iostream>
#include <cstring>

using namespace std;
class Stack{
    public:
    int size;
    int top;
    char *s;
    Stack(){
        top=-1;
    }
};

int isOprnd(char oprnd){
    if(oprnd == '+' || oprnd == '-' || oprnd == '/' || oprnd == '*' )
        return 0;
    else
        return 1;
}

int prsdnc(char oprtr){
    if(oprtr == '+' || oprtr == '-'){
        return 1;
    }else if(oprtr == '/' || oprtr == '*'){
        return 2;
    }
    return 0;
}

int isEmpty(Stack st){
    if(st.top == -1){
        return 1;
    }else{
        return 0;
    }
}

void pop(Stack *st){
    if(st->top == -1){
        cout<<"stack is already empty\n";
    }else{
        st->s[st->top] = '\0';
        st->top--;
    }
}

void push(Stack *st, char x){
    if(st->top == st->size - 1){
        cout<<"the stack is full\n";
    }else{
        st->top++;
        st->s[st->top] = x;
    }
}

char* calculator(char *infix){
    Stack st;
    char* postfix = new char[strlen(infix)+1];
    int i=0, j=0;
    while(infix[i] != '\0'){
        if(isOprnd(infix[i])){
            postfix[j++] = infix[i++];
        }else{
            if(prsdnc(infix[i]) > prsdnc(st.s[st.top])){
                push(&st, infix[i++]);
            }else{
                postfix[j++] = st.s[st.top];
                pop(&st);
            }
        }
    }
    while(!isEmpty(st)){
        postfix[j++] = st.s[st.top];
        pop(&st);
    }
    postfix[j] ='\0';
    return postfix;
}

int main()
{
    string str;
    // cout<<"Enter the string\n";
    getline(cin,str);

    char strk[str.length()]; 
    strcpy(strk, str.c_str()); 

    char* inpo = calculator(strk);
    for(int i=0;i<strlen(strk);i++){
        cout<<inpo[i];
    }

    return 0;
}
/////////////////////////////////
//evaluation
#include <iostream>
#include <cstring>

using namespace std;
class Stack{
    public:
    int size;
    int top;
    int *s;
    Stack(){
        top=-1;
    }
};

int isOprnd(char oprnd){
    if(oprnd == '+' || oprnd == '-' || oprnd == '/' || oprnd == '*' )
        return 0;
    else
        return 1;
}

int isEmpty(Stack st){
    if(st.top == -1){
        return 1;
    }else{
        return 0;
    }
}

int pop(Stack *st){
    int x = -1;
    if(st->top == -1){
        cout<<"stack is already empty\n";
    }else{
        x = st->s[st->top];
        st->s[st->top] = NULL;
        st->top--;
    }
    return x;
}

void push(Stack *st, int x){
    if(st->top == st->size - 1){
        cout<<"the stack is full\n";
    }else{
        st->top++;
        st->s[st->top] = x;
    }
}

int calculator(char *postfix){
    Stack stk;
    int i,a,b,r;
    for(i=0 ;postfix[i] != '\0'; i++){
        if(isOprnd(postfix[i])){
            push(&stk, postfix[i] - '0');
        }else{
            b = pop(&stk);
            a = pop(&stk);
            switch(postfix[i]){
                case '+':{
                    r= a+b;
                    push(&stk, r);
                    break;
                } 
                case '-':{
                    r= a-b;
                    push(&stk, r);
                    break;
                }
                case '*':{
                    r= a*b;
                    push(&stk, r);
                    break;
                }
                case '/':{
                    r= a/b;
                    push(&stk, r);
                    break;
                }
            }
        }
    }
    return pop(&stk);
}

int main()
{
    string str;
    // cout<<"Enter the string\n";
    getline(cin,str);

    char strk[str.length()]; 
    strcpy(strk, str.c_str());
    
    int eval = calculator(strk);
    cout<< eval;

    return 0;
}
