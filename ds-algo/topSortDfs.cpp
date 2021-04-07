#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph{
    int v;
    list<int>* adjl;
    bool *visited;    
    public:
    // constructor
    Graph(int ver){
        this->v = ver;
        adjl = new list<int>[ver];
        visited = new bool[ver];
    }
    void addEdge(int v, int w);
    void topologicalSortUtil(int ver, stack<int>& Stack );
    void topSort();
};

void Graph::addEdge(int v, int w)
{
    // there we are connecting v vertex with a edge in direction of w
    adjl[v].push_back(w);
}

// DFS algorithm
void Graph::topologicalSortUtil(int ver, stack<int>& Stack)
{
    visited[ver] = true;

    auto i = adjl[ver].begin();
    for (; i != adjl[ver].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, Stack);

    Stack.push(ver);
}

void Graph::topSort() {
  stack<int> stk;
  for(int i=0; i<v; i++){
      if(visited[i] == false){
          topologicalSortUtil(i, stk);
      }
  }
  
  while (stk.empty() == false) {
    cout << stk.top() << " ";
    stk.pop();
  }
}

int main()
{
    int v;
    cout<<"enter num of nodes"<<endl;
    cin>>v;
    int e;
    cout<<"num of edges"<<endl;
    cin>>e;
    Graph g(v);
    int v1,v2;
    for(int i=0;i<e;i++){
        cin>>v1>>v2;
        g.addEdge(v1,v2);
    }
    g.topSort();

    return 0;
}
