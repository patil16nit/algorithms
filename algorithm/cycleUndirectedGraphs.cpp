#include<iostream>
#include<list>
#include <limits.h>

using namespace std;

class Graph {
    int v;
    list<int> *edges; 
    bool isCycleUtil(int s, bool visited[], int parent);
    public:
        Graph(int v);
        void addEdge(int s, int w);
        bool isCyclic();
};

Graph::Graph(int v) {
    this->v = v;
    edges = new list<int>[v];
}

void Graph::addEdge(int s, int w) {
    edges[s].push_back(w);
    edges[w].push_back(s);
}

bool Graph::isCycleUtil(int s, bool visited[], int parent) {
    visited[s] = true;
    list<int>::iterator i;
    for (i = edges[s].begin(); i != edges[s].end(); ++i) {
        if (!visited[*i]) {
            if (isCycleUtil(*i, visited, s)) return true;
        } else if (*i != parent) {
            return true;
        }
    }
   return false;
}

bool Graph::isCyclic() {
    bool *visited = new bool[v];

    for (int i=0; i<v; i++) {
        visited[i] = false;
    }
    
    // Iterate over each vertices to detect the cycle in the graph
    for ( int u = 0; u < v; u++){
        if (!visited[u]) {
            if (isCycleUtil(u, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int vert = 5;
    Graph g(vert);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,0);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.isCyclic() ? cout<<endl<<"there is cycle in this graph\n" : cout<<endl<<"There is no graph\n";
    return 0;
}
