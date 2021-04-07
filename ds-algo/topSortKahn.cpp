#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph{
    int v;
    list<int>* adjl;
    bool *visited;    
    int *indeg;
    public:
    // constructor
    Graph(int ver){
        this->v = ver;
        adjl = new list<int>[ver];
        indeg = new int[ver];
        visited = new bool[ver];
    }
    
    void addEdge(int v, int w);
    void topSort();
    bool check_single();
};

void Graph::addEdge(int v, int w)
{
    // we are connecting v vertex with a edge in direction of w
    adjl[v].push_back(w);
    indeg[w]++;
}

bool Graph::check_single()
{
    for (int i = 1; i < v; ++i) {
        if (indeg[0] != indeg[i]) { return false; }
    }
    return true;
}

void Graph::topSort() {
    queue<int> Q;  
    int j;
    for(int i=0;i<v;i++){
        if(visited[i] == false && indeg[i] == 0)
            Q.push(i);
    }
    while( !check_single() || !Q.empty() ){
        j = Q.front();
        cout<< j <<" ";
        visited[j] = true;
        
        for (auto k = adjl[j].begin(); k != adjl[j].end(); ++k){
            if (!visited[*k]){
                if(--indeg[*k] == 0){
                    Q.push(*k);
                    indeg[*k]--;
                }else{
                    indeg[*k]--;
                }
            }
        }
        Q.pop();
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
