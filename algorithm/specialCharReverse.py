def checkAlphabet(x):
    return x.isalpha()

def createList(p):
    List=[]
    for i in p:
        List.append(i)
    return List

def specialCharReverse(str):
    dupl=createList(str)
    rev=len(dupl)-1
    fw=0
    while fw<rev:
        if not checkAlphabet(dupl[fw]):
            fw+=1
        elif not checkAlphabet(dupl[rev]):
            rev-=1
        else:
            dupl[fw],dupl[rev]=swap(dupl[fw],dupl[rev])
            fw+=1
            rev-=1
    print(dupl)
        

def swap(a,b):
    return b,a

def main():
    s=input("Enter string with special characters :")
    specialCharReverse(s)

if __name__:
    import cProfile
    cProfile.run("main()")
