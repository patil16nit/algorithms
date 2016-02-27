class Node:
    def __init__(self, data, next=None):
        self.data=data
        self.next=next
    
    def __str__(self):
        return str(self.data)

class LinkedList(object):
    def __init__(self):
        self.head=None
    def insert(self, data):
        if not self.head:
            n = Node(data)
            self.head = n
            return
        else:
            n = self.head
            while n.next != None:
                n = n.next
            new_node = Node(data)
            n.next = new_node
            return
    def print_list(self):
        n = self.head
        while n:
            print(n.data)
            n = n.next


def main():
     ll=[6,7,2,3,5]
     linklist= LinkedList();
     for i in ll:
         linklist.insert(i)
     linklist.print_list()


if __name__:
     import cProfile
     cProfile.run("main()")

