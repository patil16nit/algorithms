def toString(t):
    out=""
    for k,l in enumerate(t):
        out+=''.join(l)
    return out

def zigZag(str, n):
    g=[[] for dy in range(n)] 
    for i,j in enumerate(str):
        g[i%n].append(j)
    print(g)
    print(toString(g))

def main():
    s=input("enter string  : ")
    n=int(input("Enter rows :"))
    zigZag(s, n)

if __name__:
    import cProfile
    cProfile.run("main()")
