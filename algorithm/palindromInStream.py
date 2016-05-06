def palindromInStream(str,l):
    j=0
    while j<l:
        i,k=0,j
        flag=0
        while k>=i:
            if str[k]==str[i]:
                i+=1
                k-=1
            else:
                flag=1
                print(str[j],"No")
                break
        if not flag:
            print(str[j],"Yes")
            flag=0
        j+=1

def main():
    s=input("Enter string => ")
    palindromInStream(s,len(s))


if __name__:
    import cProfile
    cProfile.run("main()")
