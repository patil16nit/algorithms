#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#define MAX_NODES 10
const int INFINITY = std::numeric_limits<unsigned int>::max();

using namespace std;

class Graph {
    int V, E;
    vector< pair< int, int> >nodes[MAX_NODES];
    //vector < pair <int, int> > *nodes; 
    public:
        Graph(int V);
        void addEdge(int src, int dest, int weight);
        void printGraph();
        void sortWt(); 

};

Graph::Graph(int v) {
    this->V = v;
//    nodes =  new vector<pair <int, int> >(v);
}

void Graph::addEdge(int src, int dest, int weight) {
    nodes[src].push_back(make_pair(dest, weight));
    nodes[dest].push_back(make_pair(src, weight));
}

void Graph::printGraph() {
    for(int i=0; i< this->V; i++) {
        cout<<endl<< "Adjecent edges of node ["<< i<< "] -> ";
        vector< pair< int, int> >::iterator it;
        for (it = nodes[i].begin(); it != nodes[i].end(); ++it) {
            cout << "("<<it->first << "," << it->second<< ") "; 
        } 
    }
}

void Graph::sortWt() {
    for(int i=0; i< this->V; i++) {
        cout<<endl<< "Adjecent edges of node ["<< i<< "] -> ";
        vector< pair< int, int> >::iterator it;
        //for (it = nodes[i].begin(); it != nodes[i].end(); ++it) {
            //sort(nodes[i].begin(), nodes[i].end(),this->Graph::compare_no2);
            sort(nodes[i].begin(), nodes[i].end(),[](auto &left, auto &right){
                return left.second > right.second;
            });
            //cout << "("<<it->first << "," << it->second<< ") ";
        //}
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
    return 0;
}
