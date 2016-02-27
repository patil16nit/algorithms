class Node:
    def __init__(self, val):
        self.lchild=None
        self.rchild=None
        self.data=val

    def __str__(self):
        return str(self.data)

def insert_node(root, newNode):
    if not root:
        return
    else:
        if newNode.data < root.data:
            if root.lchild is None:
                root.lchild=newNode
            else:
                insert_node(root.lchild, newNode)
        else:
            if root.rchild is None:
                root.rchild=newNode
            else:
                insert_node(root.rchild, newNode)



def in_order(root):
    if not root:
        return
    print(root.data)
    in_order(root.lchild)
    in_order(root.rchild)

"""
def pre_order(root):
    if not root:
        return
    print(root.data)
    pre_order(root.lchild)
    pre_order(root.rchild)

def post_order(root):
    if not root:
        return()
    print(root.rchild.data)
    post_order(root.rchild)
    post_order(root.lchild)
"""
def main():
    r=Node(8)
    insert_node(r, Node(4))
    insert_node(r, Node(10))
    insert_node(r, Node(2))
    in_order(r)
if __name__:
    import cProfile
    cProfile.run("main()") 
