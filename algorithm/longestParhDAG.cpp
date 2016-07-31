#include<iostream>
#include<list>
#include<stack>
#include<limits.h>
#define NINF INT_MIN
using namespace std;

class adjListNode {
    int v;
    int weight;
    public:
        adjListNode(int _v, int _w){ v = _v; weight = _w;}
        int getV() { return v;}
        int getWeight() {return weight;} 
};


class Graph {
    int v;
    list<adjListNode> *adj;
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
    public:
        Graph(int v);
        // add edge
        void addEdge(int u, int v, int weight);
        void longestPath(int s);
};


Graph::Graph(int v) {
    this->v = v;
    adj = new list<adjListNode>[v];
}

void Graph::addEdge(int u, int v, int weight) {
    addListNode node(v, weight);
    adj[u].push_back(node);
}

/*
 * Graph::topologicalSortUtil
 * input  :  
 * output :
 */

void Graph::topologicalSortUtil(int u, bool visited[], stack<int> &Stack) {
    visited[u] = true;
    // Iterator for adj. list
    list<addListNode>::iterator i;

    for ( i = adj[u].begin(); i != adj[u].end(); i++) {
        addListNode node = *i;
        if (!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, Stack);
    }
    Stack.push(v);
}


/*
 * Graph::longest 
 * input  : int(s) 
 * output : null
 */
void Graph::longestPath( int s) {
    stack<int>  Stack;
    int dist[v];
    bool *visited = new bool[s];
    for (int i=0; i<v; i++) {
        visited[i] = false;
    }

    for (int u=0; u<v; u++) {
        if (visited[u] == false) {
            toplogicalSortUtil(u, visited, Stack);
        }
    }

    for ( int i=0; i<v; i++) {
        dist[i] = NINF;
    }
    dist[s] = 0;

    while ( Stack.empty() == false) {
        int u =  Stack.top();
        Stack.pop();
        list<addListNode>::iterator i;
        if ( dist[u] != NINF) {
            for ( i = adj[u].begin(); i != adj[u].end(); i++) {
                if ( dist[i->getV()] < dist[u] + i->getWeight() ) 
                    dist[i->getV()] = dist[u] + i->getweight();
            }
        }
    }

    // Print longest calculated weight
    for (int i =0; i < v; i ++) {
        (dist[i]== NINF) ? cout << "INF ": out<< dist[i] << " ";
    }

}

int main() {
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, -2);
    g.longestPath();  
}

