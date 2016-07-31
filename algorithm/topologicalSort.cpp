#include<iostream>
#include<list>
#include<stack>

using namespace std;

class Graph {
    int v;
    list<int> *adj;
    void topologicalSortUtil(int s, bool visited[], stack<int> &Stack);
    public:
        Graph(int v);
        void addEdge(int v, int w);
        void topologicalSort( );
};

Graph::Graph(int v) {
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); 
}

void Graph::topologicalSortUtil(int s, bool visited[], stack<int> &Stack) {
    visited[s] = true;
    list<int>::iterator i;
    for (i=adj[s].begin(); i != adj[s].end(); i++) {
        if (!visited[*i]) {
            topologicalSortUtil(*i, visited, Stack);
        }
    }

    Stack.push(s);
}


void Graph::topologicalSort() {
    stack<int> Stack;
    bool *visited =  new bool[v];
    for (int i=0; i<v; i++) {
        visited[i] = false;
    }

    list<int>::iterator i;
    for( int i=0; i<v; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, Stack);
        }
    }

    while(Stack.empty() == false) {
        cout<< Stack.top() << " ";
        Stack.pop();
    }

}

int main() {
    Graph g(5);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,3);

    g.topologicalSort();

    return 0;
}
