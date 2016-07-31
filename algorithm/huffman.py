class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def insert(self, data):
        if self.data:
            if data < self.data:
                 if self.left is None:
                     self.left = Node(data)
                 else:
        
    def __str__(self):
        return str(self.data)

def traverse(tree):
    if tree == None:
        return
    tree.left
    print(tree.data)
    tree.right


def huffman(codes): 
    freq=list(codes['frequency'])
    freq.sort()
    print(freq)

def main():
    codes= {'frequency' : set([
        (15,4),
        (20,5),
        (7,7),
        (10,3),
        (5,1),
        (45,6)])
    }
    huffman(codes)
    left = node(2)
    right= node(3)
    tree = node(1,left,right)
    traverse(tree)
    
if __name__:
    import cProfile
    cProfile.run("main()")
