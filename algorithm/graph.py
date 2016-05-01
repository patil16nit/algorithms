def GraphPath(graph, start, end , path=[]):
    path = path+[start]
    if start == end:
       return path
    if not start in graph:
       return None
    for node in graph[start]:
       if not node in path:
           newpath=GraphPath(graph, node, end, path)
           if newpath: return newpath
    return None

def main():
    graph = {'A':['B', 'C'], 'B': ['C','D'], 'C':['D'], 'D':['c'], 'E':['F'], 'F':['c']}
    path=GraphPath(graph, 'A', 'D')
    print(path)
if __name__:
    import cProfile
    cProfile.run("main()")
