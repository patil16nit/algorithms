parent={}

def dfs_visit(graph,start): 
    print(graph[start])
    for adj_node in graph[start]:
        if adj_node not in parent:
            parent[adj_node]=start
            dfs_visit(graph,adj_node)

def dfs(graph):
     for s in graph:
         if s not in parent:
             parent[s]=None
             dfs_visit(graph,s)

def main():
    g = {0:[1,2], 1:[1], 2:[0,3],3:[3]}
    dfs(g)
    print(parent)

if __name__:
    import cProfile
    cProfile.run("main()")
