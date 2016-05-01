def GraphAllPath(graph, start, end , path=[]):
    path = path+[start]
    if start == end:
       return [path]
    if not start in graph:
       return []
    paths=[]
    for node in graph[start]:
       if not node in path:
           newpaths=GraphAllPath(graph, node, end, path)
           print(newpaths)
           for newpath in newpaths: 
               paths.append(newpath)
    return paths

def main():
    graph = {'A':['B', 'C'], 'B': ['C','D'], 'C':['D'], 'D':['c'], 'E':['F'], 'F':['c']}
    path=GraphAllPath(graph, 'A', 'D')
    print(path)
if __name__:
    import cProfile
    cProfile.run("main()")
