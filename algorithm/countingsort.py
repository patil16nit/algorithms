def printArray(array, n):
    for i in xrange(n):
        print array[i]


def countingSort(arrayList, n):
    C = [0] * n
    out = [0]*n
    for i in xrange(n):
        C[arrayList[i]-1] += 1

    for j in xrange(1,n):
        C[j] = C[j] + C[j-1]

    for i in xrange(n-1,-1, -1):
        out[C[arrayList[i]-1]-1] = arrayList[i]
	C[arrayList[i]-1] -= 1

    for i in xrange(n):
        print out[i]


def main():
    arrayList  = raw_input("Enter space separated arraylist :")
    arrayList = [int(x) for x in arrayList.split(" ")]
    countingSort(arrayList, len(arrayList))

if __name__ == "__main__":
    import cProfile
    cProfile.run("main()")
