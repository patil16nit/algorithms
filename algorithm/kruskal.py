parent=dict()
rank=dict()

def make_set(v):
    parent[v]=v
    rank[v]=0

def find(vertice):
    if parent[vertice] != vertice:
        parent[vertice]=find(parent[vertice])
    return parent[vertice]

def union(v1,v2):
    root1=find(v1)
    root2=find(v2)
    if root1!=root2:
        if rank[root1]> rank[root2]:
            parent[root2]=root1
        else:
            parent[root1]=root2
            if rank[root1]==rank[root2]: rank[root2]+=1


def kruskal(graph):
    for vertices in graph['vertices']:
        make_set(vertices)

    min_spanning_tree=set()
    edges= list(graph['edges'])
    edges.sort()
    for edge in edges:
        wt,v1,v2=edge
        if find(v1)!=find(v2):
            union(v1,v2)
            min_spanning_tree.add(edge)
    return min_spanning_tree



def main():
    graph = {
            'vertices': ['A', 'B', 'C', 'D', 'E', 'F'],
            'edges': set([
                (1, 'A', 'B'),
                (5, 'A', 'C'),
                (3, 'A', 'D'),
                (4, 'B', 'C'),
                (2, 'B', 'D'),
                (1, 'C', 'D'),
                ])
            }

    print(kruskal(graph))

if __name__:
    import cProfile
    cProfile.run("main()")

