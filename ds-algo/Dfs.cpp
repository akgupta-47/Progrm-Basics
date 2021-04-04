#include <iostream>
#include <list>

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
    void DFS(int vertex);
};

void Graph::addEdge(int v, int w)
{
    // there we are connecting v vertex with a edge in direction of w
    adjl[v].push_back(w);
}

// DFS algorithm
void Graph::DFS(int vertex) {
  visited[vertex] = true;
  list<int> adjList = adjl[vertex];
  /*
  for (int x: adjList){
      cout<<x<<" ";
  }
  */
  cout << vertex << " ";

  auto i = adjList.begin();
  for (; i != adjList.end(); ++i)
    if (!visited[*i])
      DFS(*i);
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
    g.DFS(0);

    return 0;
}

