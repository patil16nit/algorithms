#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
const int N = 4;
using namespace std;

class Graph {
    int nodes, edges;
    //vector<pair<int, int> > adj[nodes];
};

void dijkstra(int start,int nodes, vector<list<pair<int, int > > > &graph) {

    cout<< "Inside Dijkshra"<<endl;
    int *min_dist = new int[nodes]; 
    bool *visited = new bool[nodes];
    
    vector<int> min_distance(nodes);
   
     

    for (int k=1; k<= nodes; k++) {
        min_dist[k] = 1024;
        min_distance[k] = 1024;
        visited[k] = false;
    }

    //min_distance[start] = 0;
    min_dist[start] = 0;
    visited[start]= true;
    
    list<int> queue;

    queue.push_back(start);

    while( !queue.empty()) {

        start = queue.front();
        queue.pop_front();
        visited[start] = true;

        cout<<endl<< "Tracking elements of the node["<<start<<"]"<<endl;
        // Update neighbours of the start 
        for (list< pair<int, int> >::iterator itr = graph[start].begin(); itr != graph[start].end(); ++itr) {
            cout<< "min_dist[start]" << min_dist[start] <<  " neightbour -> [" << itr->first << " ] weight start and item node " << itr->second;

            if (min_dist[start] + itr->second < min_dist[itr->first]  && !visited[itr->first]) {
                min_dist[itr->first] = min_dist[start] + itr->second;
            }
        }

        // select min edge element
        list< pair<int, int> >::iterator itr = min_element( graph[start].begin(),  graph[start].end());
        if (! visited[itr->first]) { 
            queue.push_back(itr->first);
        }

    }
    cout<<endl;
//    for (vector<int>::iterator it = min_distance.begin(); it != min_distance.end(); it++) {
    for (int i=1; i<=nodes; i++){
        cout << min_dist[i] << " ";
    }

}






void printGraph(int n, vector< list< pair<int, int> > > &graph) {
    std::cout << "Printing graph "<<endl;

    for (int j=1; j<=n; j++) {
        std:cout << "Node " << j << " & its adj list is ->" << endl;
        list< pair<int, int> >::iterator itr = graph[j].begin(); 
        while (itr != graph[j].end() ) {
            std::cout << itr->first <<" "<< itr->second << endl;
            ++itr;
        }
    }
}



int main() {
    int nodes, edges, start;

    std::cout << "Enter Number of nodes and edge for graphs"<<endl;
    std::cin >> nodes >> edges;

    vector< list< pair< int, int> > > adj(nodes+1);

    std::cout << "Enter " << edges <<" edges"<<endl;

    for (int i=0; i<edges; i++) {
        std::cout << "Enter edge " << i+1 <<endl;
        int s, e, w;
        std::cin >> s >> e >> w;
        adj[s].push_back(make_pair(e,w));
        adj[e].push_back(make_pair(s,w));
    }

    std::cout << "Enter start node of the graph"<<endl;
    std::cin >> start;

    cout<<"end";
    dijkstra(start, nodes, adj);

    // Print graph
    //printGraph(nodes, adj);

    return 0;
}
