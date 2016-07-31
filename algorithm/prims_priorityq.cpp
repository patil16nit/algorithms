#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <limits>
#define MAX_NODES 10
const int INFINITY = std::numeric_limits<unsigned int>::max();

using namespace std;

typedef pair<int, int> iPair;

class Graph {
    int V;
    list< pair<int, int> > *adj;
    public:
        Graph(int V);
        void addEdge(int src, int dest, int weight);
        void printGraph();
        void primsMST();
};

Graph::Graph(int v) {
    this->V = v;
    adj =  new list<iPair> [v];
}

void Graph::addEdge(int src, int dest, int weight) {
    adj[src].push_back(make_pair(dest, weight));
    adj[dest].push_back(make_pair(src, weight));
}

void Graph::printGraph() {
    for(int i=0; i< this->V; i++) {
        cout<<endl<< "Adjecent edges of node ["<< i<< "] -> ";
        list< pair< int, int> >::iterator it;
        for (it = adj[i].begin(); it != adj[i].end(); ++it) {
            cout << "("<<it->first << "," << it->second<< ") "; 
        } 
    }
}

void Graph::primsMST() {
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    int src = 0;
    vector<int> key(V, INFINITY);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push(make_pair(0, src));
    key[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u]= true;
        list< pair<int, int> >::iterator it;
        for (it = adj[u].begin(); it != adj[u].end(); it++) {
            int v = (*it).first;
            int wt = (*it).second;
        
            if (inMST[v] == false && key[v] > wt) {
                key[v] = wt;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    for (int i=0; i< V; i++) {
        cout<< parent[i] <<" "<<  i;
    }
}

int main () {
    Graph g(6);
    g.addEdge(0,1,10);
    g.addEdge(0,2,3);
    g.addEdge(0,3,20);
    g.addEdge(1,2,2);
    g.addEdge(1,3,5);
    g.addEdge(2,4,15);
    g.addEdge(3,4,11);
    g.addEdge(2,0,6);
    g.printGraph();
    cout<<endl<< "Prims" <<endl;
    g.primsMST();
    return 0;
}
