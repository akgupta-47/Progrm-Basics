#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph{
    int v;
    list<int>* adjl;
    public:
    // constructor
    Graph(int ver){
        this->v = ver;
        adj = new list<int>[ver];
    }
}

int main()
{
    int v;
    cout<<"enter num of nodes"<<endl;
    int e;
    cout<<"num of edges"<<endl;
    Graph g(v);
    int v1,v2;
    for(i=0;i<e;i++){
        cin>>v1>>v2;
        g.addEdge(v1,v2);
    }

    return 0;
}

