#include<iostream>
#include<list>

using namespace std;

class Graph{
    int v;
    list<int> *adj;
    bool verifyCyclesUtil(int s, bool visited[]);
    public:
        Graph(int v);
        void addEdge(int s, int w);
        bool verifyCycles(int s);
};

Graph::Graph(int v) {
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int s, int w)  {
    adj[s].push_back(w); // add edge s->w 
}

bool Graph::verifyCyclesUtil(int s, bool visited[]) {
    bool flag;
    list<int>::iterator i;

    for (i=adj[s].begin(); i != adj[s].end(); ++i) {
         if (s == *i || visited[*i] == true) {
             return true;
         }
         visited[*i] = true;
         if (verifyCyclesUtil(*i, visited) == true) {
             return true;
         }
    }
    return false;
}

bool Graph::verifyCycles(int s) {
    bool *visited = new bool[v];
    for (int i=0; i<v; i++) {
        visited[i] = false;
    }
    visited[s] = true;
    return verifyCyclesUtil(s, visited);
}

int main() {
    int vertices = 4;
    Graph g(vertices);
    //g.addEdge(0,2);
    g.addEdge(0,1);
    //g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    //g.addEdge(3,3);
    g.verifyCycles(2) ? cout<<"There is cycle in this graph": cout<<"No cycle in this graph";
    return 0;
}
