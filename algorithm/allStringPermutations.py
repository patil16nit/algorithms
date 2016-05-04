def toString(str):
    return ''.join(str)

def allPermutations(str,l,r):
    if(l==r):
        print(toString(str))
    else:
        for i in range(l,r):
            str[l],str[i]= str[i], str[l]
            allPermutations(str,l+1,r)
            str[l],str[i]= str[i], str[l]

def main():
    s= input("Enter a string: ")
    n=len(s)
    a=list(s)
    allPermutations(a, 0, n)

if __name__:
    import cProfile
    cProfile.run("main()")
