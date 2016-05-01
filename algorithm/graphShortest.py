def GraphShortestPath(graph, start, end , path=[]):
    path = path+[start]
    if start == end:
       return path
    if not start in graph:
       return None
    shortest=[]
    for node in graph[start]:
       if not node in path:
           newpath=GraphShortestPath(graph, node, end, path)
           if newpath:
               if not shortest or len(newpath) < len(shortest): 
                   shortest = newpath
    return shortest

def main():
    graph = {'A':['B', 'C'], 'B': ['C','D'], 'C':['D'], 'D':['c'], 'E':['F'], 'F':['c']}
    path=GraphShortestPath(graph, 'A', 'D')
    print(path)
if __name__:
    import cProfile
    cProfile.run("main()")
