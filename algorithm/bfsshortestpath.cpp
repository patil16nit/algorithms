#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;


vector<int> out;

class Graph {
    int node;
    list<int>*adj;
    public:
        Graph(int node);
        void addEdges(int start, int end);
        void bfs(int s);
};

Graph::Graph(int node) {
    this->node = node;
    adj = new list<int>[node];
}

void Graph::addEdges(int start, int end) {
    adj[start].push_back(end);
    adj[end].push_back(start);
}

void Graph::bfs(int s) {
    int start = s;
    bool *visited = new bool[node];
    int *data = new int[node];
    for (int i=0; i<node; i++) {
        visited[i] = false;
        data[i] = 1024;
    }
    
    list<int> queue;
    visited[s] = true;
    data[s] = 0;
    queue.push_back(s);
    
    list<int>::iterator i;
    
    while(!queue.empty()) {
        s = queue.front();
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); i++) {
            if ( data[s] + 6 < data[*i]) {
                data[*i] = data[s] + 6;
            }
            if ( !visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
  
    for (int i=0;i<node; i++) {
        if ( data[i] == 0) {
            continue;
        } else if (data[i] == 1024) {
            out.push_back(-1);
        } else {

            out.push_back(data[i]);
        }
    }
    out.push_back(999);
    //free(adj);
    //free(visited);
    //free(data);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int testcases,nodes, edges, start;
    cin>>testcases;  
    
    for (int j=1; j<=testcases; j++) {
        cin>>nodes>>edges;
        Graph g(nodes);
        for(int i=1; i<=edges ;i++) {
            int s,e;
            cin>>s>>e;
            g.addEdges(s-1,e-1);
        }
        cin>>start;
        //cout<<"Test g.bfs start()";
        g.bfs(start-1);
        //cout<<"Test g.bfs end()";
    }
    //cout<<"Free";
    
    vector<int>::iterator i;
    for (i = out.begin(); i != out.end(); i++) {
        if (*i == 999) {
            cout<<endl;
            continue;
        }
        cout<<*i<<" ";
    }    
    cout<<"Size of out"<< out.size();
    return 0;
}
