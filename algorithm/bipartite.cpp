#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int v;
    list<int> *adj;
    bool checkBipartiteUtil(int s, bool visites[], int color[]);
    public:
        Graph(int v);
        void addEdge(int v, int w) {
            adj[v].push_back(w);
//            adj[w].push_back(v);
        }
        void checkBipartite(int s);
        void printGraph();
};

Graph::Graph(int v) {
    this->v=v;
    adj = new list<int>[v];
}


bool Graph::checkBipartiteUtil(int s, bool visited[], int color[]) {
    visited[s] = true;

    list<int>::iterator i;

    for ( i = adj[s].begin(); i != adj[s].end(); i++) {
        cout << " " << *i;
        if (!visited[*i]) {
            color[*i] = color[s] == 1 ? 2 : 1;
            cout << "Processing " << *i << " set color = " << color[*i];
            if (checkBipartiteUtil(*i, visited, color)) {
                return true;
            } else {
                return false;
            }
        } else if (color[*i] == color[s]) {
            return false;
        }

    }
    return true;
}


void Graph::checkBipartite(int s) {
    bool *visited = new bool[v];
    /*
     * color : array<int>
     * default : 0
     * blue : 1
     * red : 2
     */
    int *color = new int[s];

    for (int i =0; i<v; i++) {
        visited[i] = false;
        color[i] = 0;
    }

    color[0] = 1;
    checkBipartiteUtil(s, visited, color) ? cout<< "Graph is bipartite " : cout<<"Graph is not bipartite"; 

    cout<< "\n Colors\n";
    for (int i =0; i<v; i++) {
       cout << " " <<color[i];
    }

}

void Graph::printGraph() {
    list<int>::iterator i; 
    for (int node=0; node<v; node++) {
        cout<< "Node [" << node << "] -> ";
        for ( i = adj[node].begin(); i != adj[node].end(); i++) {
             cout<< *i << " ";
        }
        cout<<"\n";
    }
}

int main() {
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.printGraph();
    g.checkBipartite(0);
    return 0;
}
