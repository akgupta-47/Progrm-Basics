//////////////////////////////////////
// all funs od queuue
#include <iostream>

using namespace std;
class Queue{
    public:
    int size;
    int front;
    int rear;
    int *qu;
    Queue(){
        front = -1;
        rear = -1;
    }
};

bool isEmpty(Queue *q){
    if(q->front == q->rear){
        return true;
    }else{
        return false;
    }
}

bool isFull(Queue *q){
    if(q->rear == q->size -1){
        return true;
    }else{
        return false;
    }
}

void Display(Queue q){
    for(int i=q.front + 1; i <= q.rear; i++){
        cout<<q.qu[i]<<" ";
    }
}

int dequeue(Queue *q){
    int x = -1;
    if( isEmpty(q) ){
        cout<<"Queue is empty\n";
    }else{
        x = q->qu[++q->front];
    }
    return x;
}

void enqueue(Queue *q){
    if( isFull(q) ){
        cout<<"Queue is full"<<endl;
        return;
    }else{
    	cout<<"enter the element to be inserted\n";
        int x;
        cin>>x;
        q->qu[++q->rear] = x;
    }
}

int main() {
  Queue que;
  cout<<"enter the size"<<endl;
  cin>> que.size;
  que.qu = new int[que.size];
  // insert 
  for(int i=0;i<4;i++){
      enqueue(&que);
  }
  // delete 
  dequeue(&que);
  //display
  Display(que);
}
//////////////////////////////////////////////////////////
// circular version
//////////////////////////////////////
// all funs od queuue
#include <iostream>

using namespace std;
class circQueue{
    public:
    int size;
    int front;
    int rear;
    int *qu;
    circQueue(){
        front = 0;
        rear = 0;
    }
};

bool isEmpty(circQueue *q){
    if(q->front == q->rear){
        return true;
    }else{
        return false;
    }
}

bool isFull(circQueue *q){
    if(( q->rear+1 )%( q->size ) == q->front){
        return true;
    }else{
        return false;
    }
}

void Display(circQueue q){
    for(int i=0 ; i < q.size; i++){
        cout<<q.qu[i]<<" ";
    }
}

int circDequeue(circQueue *q){
    int x = -1;
    if( isEmpty(q) ){
        cout<<"Queue is empty\n";
    }else{
        q->front = (q->front + 1)%(q->size);
        x = q->qu[q->front];
    }
    return x;
}

void circEnqueue(circQueue *q){
    if( isFull(q) ){
        cout<<"Queue is full"<<endl;
        return;
    }else{
    	cout<<"enter the element to be inserted\n";
        int x;
        cin>>x;
        q->rear = (q->rear + 1)%( q->size );
        q->qu[q->rear] = x;
    }
}

int main() {
  circQueue que;
  cout<<"enter the size"<<endl;
  cin>> que.size;
  que.qu = new int[que.size];
  // insert 
  for(int i=0;i<4;i++){
      circEnqueue(&que);
  }
  // delete 
  circDequeue(&que);
  circDequeue(&que);
  circDequeue(&que);
  
  circEnqueue(&que);
  circEnqueue(&que);
  circEnqueue(&que);
  circEnqueue(&que);
  //display
  Display(que);
}
/////////////////////////////////////////////////////////////
// to interleave right and left side of queue
// currently incomplete
#include <iostream>
#include <stack>
using namespace std;
class Queue{
    public:
    int size;
    int front;
    int rear;
    int *qu;
    Queue(){
        front = -1;
        rear = -1;
    }
};

bool isEmpty(Queue *q){
    if(q->front == q->rear){
        return true;
    }else{
        return false;
    }
}

bool isFull(Queue *q){
    if(q->rear == q->size -1){
        return true;
    }else{
        return false;
    }
}

void Display(Queue q){
    for(int i=0 ; i < q.size; i++){
        cout<<q.qu[i]<<" ";
    }
}

int dequeue(Queue *q){
    int x = -1;
    if( isEmpty(q) ){
        cout<<"Queue is empty\n";
    }else{
        x = q->qu[++q->front];
    }
    return x;
}

void enqueue(Queue *q, int red, int x){
    if( isFull(q) ){
        cout<<"Queue is full"<<endl;
        return;
    }else{
        if(red == 0){
            q->qu[++q->rear] = x;
        }else if(red == 1){
            q->qu[--q->rear] = x;
        }
    }
}

int main() {
  Queue que;
  int x;
  
  cout<<"enter the size"<<endl;
  cin>> que.size;
  if(que.size % 2 != 0){
      cout<<"choose an even number";
      return 0;
  }
  que.qu = new int[que.size];
  // insert 
  for(int i=0;i<que.size;i++){
      cout<<"enter the element to be inserted\n";
      cin>>x;
      enqueue(&que, 0, x);
  }
  
  //display
  Display(que);
  cout<<endl;
  // bring 2 stacks
  stack<int> st_1;
  stack<int> st_2;
  
  for(int i=0; i<que.size/2 ; i++){
      st_1.push(dequeue(&que));
  }
  for(int j=0; j<que.size/2 ; j++){
      st_2.push(dequeue(&que));
  }

//   que.front = -1;
  while(!st_1.empty()){
      enqueue(&que, 1, st_2.top());
      st_2.pop();
      
      enqueue(&que, 1, st_1.top());
      st_1.pop();
  }
  cout<<endl;
  Display(que);
  
}
/////////////////////////////////////
// string repeat try
#include <iostream>

using namespace std;
class Queue{
    public:
    int size;
    int front;
    int rear;
    char *qu;
    Queue(){
        front = -1;
        rear = -1;
    }
};

bool isEmpty(Queue *q){
    if(q->front == q->rear){
        return true;
    }else{
        return false;
    }
}

bool isFull(Queue *q){
    if(q->rear == q->size -1){
        return true;
    }else{
        return false;
    }
}

void Display(Queue q){
    for(int i=q.front + 1; i <= q.rear; i++){
        cout<<q.qu[i]<<" ";
    }
}

int dequeue(Queue *q){
    int x = -1;
    if( isEmpty(q) ){
        cout<<"Queue is empty\n";
    }else{
        x = q->qu[++q->front];
    }
    return x;
}

void enqueue(Queue *q){
    if( isFull(q) ){
        cout<<"Queue is full"<<endl;
        return;
    }else{
    	cout<<"enter the element to be inserted\n";
        char x;
        cin>>x;
        q->qu[++q->rear] = x;
    }
}

int main() {
  Queue que;
  cout<<"enter the size"<<endl;
  cin>> que.size;
  que.qu = new int[que.size];
  // insert 
  cout<<"enter the element to be inserted\n";
    char x;
    cin>>x;
  que.qu[++que.rear] = x;
  
  for(int i=1 ;i<que.size ;i++){
      enqueue(&que, x);
  }
  //display
  Display(que);
}
