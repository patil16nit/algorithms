def printSeq(arr):
    print("")
    for data in arr:
        print(data, end=" ") 

def sumseq(x, arr, cur_sum, cur_idx):
    if x == cur_sum:
        printSeq(arr)
        
    n=1
    while (n <= (x-cur_sum)) and (cur_idx==0 or n <= arr[cur_idx-1]):
        arr.append(n)
        sumseq(x, arr, cur_sum+n, cur_idx+1)
        n=n+1

def main():
    sumseq(4,[],0,0)

if __name__:
    import cProfile
    cProfile.run("main()")
