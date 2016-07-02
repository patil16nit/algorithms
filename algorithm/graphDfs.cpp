#include<iostream>
#include<list>

using namespace std;

class Graph {
    int V;
    list<int> *adj;
    void dfsUtil(int v, bool visited[]); 
    public:
        Graph(int v);
        void addEdge(int s, int w);
        void dfs(int s);
};

Graph::Graph(int v) {
    this->V = v;
    adj = new list<int>[V];
}

void Graph::addEdge(int s, int w) {
    adj[s].push_back(w);
}

void Graph::dfsUtil(int s, bool visited[]) {
    visited[s] = true;
    cout<<s<<" ";
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i) {
        if (!visited[*i]) {
            dfsUtil(*i, visited);
        }
    }
}

void Graph::dfs(int s){
    bool *visited = new bool[V];
    for (int i=0; i<V; i++) {
        visited[i] = false;
    }
    dfsUtil(s, visited);
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.dfs(2);
    return 0;
}
