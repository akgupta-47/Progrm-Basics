#include <iostream>
#include <list>
#include <vector>

using namespace std;

// create graph class
class Graph
{
    int v;
    int n;
    int start;
    list<int> *adjl;

public:
    // constructor
    Graph(int ver, int st, int col)
    {
        this->v = ver;
        this->start = st;
        this->n = col;
        adjl = new list<int>[ver + 1];
    }
    void addInList(int *, int);
    void addEdge(int a, int b);
    void createAdjList();
    bool BFS(int home, int pred[]);
    void findSmallestPath(int);
    void printGraph();
};

// data about allowed movement calculation

// add edge in list
void Graph::addEdge(int a, int b)
{
    adjl[a].push_back(b);
}

// based on movement calculate possible points and add to list
void Graph::addInList(int *dir, int pos)
{
    const int movement[8] = {-n, -n + 1, 1, n + 1, n, n - 1, -1, -n - 1};
    for (int i = 0; i < 8; i++)
    {
        // if direction bit is one then the move is possible
        if (dir[i] == 1)
        {
            // calculate possible moves
            int move = pos + movement[i];
            // push back components in pixel
            addEdge(pos, move);
        }
    }
}

// input 8 bits and create list for every pixel
void Graph::createAdjList()
{
    // create list for all vertices
    for (int i = 0; i < v; i++)
    {
        // create a 8 bit temp array
        int temp[8];
        // get position
        int pos;
        cin >> pos;
        for (int j = 0; j < 8; j++)
        {
            cin >> temp[j];
        }
        // add possible verties based on bits
        addInList(temp, pos);
    }
}

void Graph::printGraph()
{
    // loop over all vertices
    for (int i = 0; i < v; i++)
    {
        // print the pixel
        cout << i + 1 << " ";
        // create a list of all pixels connected to pixel
        list<int> adjList = adjl[i + 1];
        // print to all possible pixels
        for (auto j = adjList.begin(); j != adjList.end(); j++)
        {
            cout << *j << " ";
        }
        cout << endl;
    }
}

// BFS algorithm
bool Graph::BFS(int home, int *prevNodes)
{
    // create a visited bolean array to check if vertex has been visited atleast once or not
    bool *visited = new bool[v + 1];
    // cout<<vertex<<" ";
    // set value of all visited nodes false initially and all predsecessors -1
    for (int i = 1; i <= v; i++)
    {
        visited[i] = false;
        prevNodes[i] = -1;
    }

    // create queue to perform bfs
    list<int> q;
    // visit starting index and set it to true
    visited[start] = true;
    q.push_back(start);
    int s;

    // loop thill queue is empty
    while (!q.empty())
    {
        // get first elelemtn in queue
        s = q.front();
        q.pop_front();
        // get adjacency list of particular pixel
        list<int> adjList = adjl[s];
        // for(auto t = adjList.begin(); t != adjList.end(); ++t){
        //     cout<<*t<<" ";
        // }
        // cout<<endl;
        for (auto t = adjList.begin(); t != adjList.end(); ++t)
        {
            if (!visited[*t])
            {
                // cout<<*t<<" ";
                visited[*t] = true;
                prevNodes[*t] = s;
                // cout<<*t<<" -> "<<prevNodes[*t]<<" "<<endl;
                q.push_back(*t);

                // if target is reached return back
                if (*t == home)
                {
                    return true;
                }
            }
        }
    }
    // cout<<endl;
    // if target cannot be reached send false
    return false;
}

void Graph::findSmallestPath(int target)
{
    int pred[v + 1];
    if (target == start)
    {
        cout << target << endl;
        return;
    }

    if (BFS(target, pred) == false)
    {
        // cout<<endl;
        // cout << "Bhaiya tum ghar se nikal to rahe ho par kahi pohoch nhi rahe ho" << endl;
        return;
    }
    // for(int i=1;i<=v;i++){
    //     cout<<pred[i]<<" ";
    // }
    // cout<<endl;

    vector<int> path;
    int crawl = target;
    path.push_back(crawl);
    while (pred[crawl] != -1)
    {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    // cout << "Path is::\n";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;
}

int main()
{
    // input dimensions and start point
    int row, col, start;
    cin >> row >> col >> start;
    // create Graph and call costructor
    Graph g(row * col, start, col);
    // create list
    g.createAdjList();
    // print adjecency list
    // g.printGraph();
    // define corners
    int c1 = 1, c2 = col, c3 = ((col * (row - 1)) + 1), c4 = (col * row);

    // find distance from top left corner
    g.findSmallestPath(c1);

    // find distance from top right corner
    g.findSmallestPath(c2);

    // find distance from bottom left corner
    g.findSmallestPath(c3);

    // distance from bottom right corner
    g.findSmallestPath(c4);

    // cout<<endl;
    // g.printGraph();

    return 0;
}