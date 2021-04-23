#include <iostream>
#include <vector>
#define NOT_IN_STACK 0
#define IN_STACK 1

using namespace std;

class Graph{
    int v;
    int *label;   
    int **adj;
    public:
    // constructor
    Graph(int ver){
        this->v = ver;
        label = new int[ver];
        adj = new int*[ver];
        for(int i=0;i< ver;i++){
            adj[i] = new int[ver];
        }
    }
    void addEdge(int , int );
    bool dfs(int , int );
    bool check_using_dfs();
};

void Graph::addEdge(int v, int w)
{
    // there we are connecting v vertex with a edge in direction of w
    adj[v][w] = 1;
    adj[w][v] = 1;
}

bool Graph::dfs(int t, int instack_count){
    if(instack_count == v)
        return true;
    for(int i=0; i<v; i++)
        if(adj[t][i] && label[i] == NOT_IN_STACK){
            label[i]=IN_STACK;
            cout<<i<<" ";
            if(dfs(i, instack_count+1))
                return true;
            label[i]=NOT_IN_STACK;
        }
    return false;
}
bool Graph::check_using_dfs(){
    /*
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
 
            // Assign values to the
            // memory blocks created
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    for(int i=0; i<v; i++)
        label[i]=NOT_IN_STACK;
    for(int i=0; i<v; i++){
        label[i]=IN_STACK;
        cout<<i<<" ";
        if(dfs(i, 1))
            return true;
        label[i]=NOT_IN_STACK;
    }
    return false;
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
    g.check_using_dfs();

    return 0;
}
