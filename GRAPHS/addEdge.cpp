#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>>adj;

    void addEdge(int u, int v , bool direction)
    {
        // direction = 0 -> undirected
        // direction = 1 -> directed

        // create an edge from u to v
        adj[u].push_back(v);
        if(direction == 0)
        {
            // create an edge from v to u
            adj[v].push_back(u);
        }
    }

    void printAdjList(int n)
    {
        for(int i = 0; i < n; i++)
        {
            cout << i << " -> ";
            for(auto j : adj[i])
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout<<"Enter the number of Nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges : ";
    cin>>m;

    int direction;
    cout<<"Enter 0 for undirected, 1 for directed: ";
    cin>>direction;

    Graph g;
    for(int i = 0 ; i < m ; i++)
    {
        int u , v;
        cin>>u>>v;
        g.addEdge(u,v,direction);
    }

    // Printing graph
    g.printAdjList(n);
    return 0;
}

