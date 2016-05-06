def flip(c):
    return 0 if c==1 else 1

def complements(arr):
    a=len(arr)
    ones=[]
    twos=[]
    for i in range(a):
        ones.append(flip(arr[i]))
        twos.append(flip(arr[i]))
    j=a-1
    while j>=0:
        if ones[j]==1:
            twos[j]=0
            j=j-1
        else:
            twos[j]=1
            break;

    if j==-1:
        twos = [1]+ twos

    print("ones -> ",ones)
    print("twos -> ",twos)



def main():
    s=input("Enter binary number: ")
    arr=[]
    for i in list(s):
        arr.append(int(i))
    complements(arr)


if __name__:
    import cProfile
    cProfile.run("main()")
