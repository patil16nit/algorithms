def bubblesort(arr):
    for i,val in enumerate(arr):
        j=len(arr)-1
        while(j>=i):
            if arr[j]<arr[j-1]:
                arr[j],arr[j-1]=arr[j-1],arr[j]
            j=j-1
def main():
    A=[2,8,1,3,5]
    bubblesort(A)

if __name__:
    import cProfile
    cProfile.run("main()")
