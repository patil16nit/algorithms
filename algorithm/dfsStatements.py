R=3
C=3

def printStr(arr,m,n,output):
    output[m]=arr[m][n]
    if m==R-1:
        for i in range(R):
            print(output[i], end=" ")
        print("")
        return
    for i in range(C):
        if arr[m+1][i] != "":
            printStr(arr, m+1,i,output)



def printStart(arr):
    output=[""]*R
    for i in range(C):
        if arr[0][i] != "":
            printStr(arr,0,i,output)


def main():
    array=[["You", "We", ""],
           ["are", "have", ""],
           ["sleep", "eat", "drink"]]
    printStart(array)

if __name__:
    import cProfile
    cProfile.run("main()")
