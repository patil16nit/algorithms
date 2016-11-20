def allCombinationMultipleList(arrayLists, loop, L): 
    if loop > len(arrayLists)-1:
        print L
    else:
        for i in xrange(len(arrayLists[loop])):
            print i, loop
            L[loop][i] = arrayLists[loop][i]
            allCombinationMultipleList(arrayLists, loop+1, L) #L.append(arrayLists[loop][i]))

def main():
    arrayLists = []
    out = []
    lists = int(raw_input("Enter number of lists :"))
    for i in xrange(lists):
        newList = []
        newList = raw_input("Enter List : ")
        newList = [int(i) for i in newList.split(" ")]
        arrayLists.append(newList)
        out.append([0]*len(newList))
    print out
    allCombinationMultipleList(arrayLists, 0, out)
    print arrayLists

if __name__ == "__main__":
    import cProfile
    cProfile.run("main()")
