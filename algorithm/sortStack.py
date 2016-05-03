def sortStack(stack):
    if len(stack) != 0:
        temp= stack.pop()
        sortStack(stack)
        sortIndex(stack, temp)
        print("after sortIndex :", stack)


def sortIndex(stack, element):
     if len(stack)==0 or element > stack[-1:][0]:
         stack.append(element)
     else:
        temp = stack.pop()
        sortIndex(stack,element)
        stack.append(temp)

def main():
    #s = input("enter array element")
    stack=[]
    for i in s.split(" "):
        stack.append(int(i))
    sortedS = sortStack(stack)

if __name__:
    import cProfile
    cProfile.run("main()")
