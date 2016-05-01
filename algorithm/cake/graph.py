class graph:

    def __init__(self, g={}):
        self.__g = g

    def vertices(self):
        return list(self.__g.keys())

    def edges(self):
        return self.__generate_edges()

    def add_vertex(self, vertex):
        if vertex not in self.__g:
            self.__g[vertex]=[]

    def add_edge(self, edge):
        (vertex1, vertex2) = tuple(edge)
        if vertex1 in self.__g:
            self.__g[vertex1].append(vertex2)
        else:
            self.__g[vertex1] = [vertex2]


    def __generate_edges(self):
        edge = []
        for vertex in self.__g:
            for node in self.__g[vertex]:
                if {vertex, node} not in edge:
                     edge.append({vertex, node})
        return edge

    def __str__(self):
        res = "Vertices : "
        for k in self.__g:
            res+= str(k) + " "
        res += "\nedges: "
        for edge in self.__generate_edges():
            res += str(edge) + " "
        return res

    def vertex_degree(self, vertex):
        adj_vertex = self.__g[vertex]
        return len(adj_vertex) + adj_vertex.count(vertex)

    def graph_density(self):
        v = len(self.__g.keys())
        #e = len(self.edge)
        #return 2*e/v*(v-1)

    def find_all_paths(self, start_vertex, end_vertex,path=[]):
        graph = self.__g
        path += [start_vertex]
        if start_vertex == end_vertex:
            return [path]
        if start_vertex not in graph:
            return []
        paths=[]
        for vertex in graph[start_vertex]:
            if vertex not in path:
                extended_path= self.find_all_paths(vertex, end_vertex, path)
                for p in extended_path:
                     paths.append(p)
        return paths
	    
    def shortest_path(self, start_vertex, end_vertex):
         path= []
         graph = self__g
         vertices = graph.keys()
         for node in vertices:
             if node not in path:
                  extended_path = self.shortest_path(node, end_node,path + [node])
                  for i in extended_path:
                     path.append(i)
         return path
                  

if __name__ == "__main__":
    g = { "a" : ["d"],
          "b" : ["c"],
          "c" : ["b", "c", "d", "e"],
          "d" : ["a", "c"],
          "e" : ["c"],
          "f" : []
        }
    graph = graph(g)
    print(graph)
    print(graph.vertices())

    graph.add_vertex('g')
    print(graph.vertices())

    graph.add_edge({'f','g'})
    print(graph.vertices())
    print(graph.edges())

    print('Degree of C : ')
    print(graph.vertex_degree('c'))

    print('Graph Density')
    print(graph.graph_density())

    print('Graph all paths :')
    print(graph.find_all_paths('a', 'e'))

