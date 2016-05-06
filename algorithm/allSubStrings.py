def printSubs(pre,res):
    if len(res)==0:
        print(pre)
    else:
        printSubs(pre+res[:1], res[1:])
        printSubs(pre, res[1:])

def allSubStrings(str):
    if len(str)!=0 or str!="":
        printSubs("", str)

def main():
    allSubStrings("ABC")

if __name__:
    import cProfile
    cProfile.run("main()")
