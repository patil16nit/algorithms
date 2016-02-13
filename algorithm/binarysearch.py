
def binarysearch(arr, key, min, max):
    print("min -> ",min, " max-> ",max)
    mid=(max+min)//2
    while (min<=max and arr[mid]!=key): 
       if key<arr[mid]:
           max=mid-1
       elif key>arr[mid]:
           min=mid+1 
       mid=(max+min)//2
    if min>max:
        print("not found")
        return
    else:
        print("found at ", mid)
        return

def mergesort(A,p,q,r):
    n1=q-p+1
    n2=r-q
    L=[None]*n1
    R=[None]*n2
    x,y=0,0
    while (x<n1):
        L[x]=A[p+x]
        x=x+1
    while (y<n2):
        R[y]=A[q+y+1]
        y=y+1 
    k=p
    i,j=0,0
    while (k<r):
        if L[i]<=R[j]:
            A[k]=L[i]
            i=i+1
        else:
            A[k]=R[j]
            j=j+1
        k=k+1

def merge(B,p,r):
    if (p<r):
        q=(p+r)//2
        merge(B,p,q)
        merge(B,q+1,r)
        mergesort(B,p,q,r)

def main():
    arr=[4,5,1,9]
    merge(arr,0,len(arr)-1)
    for val in arr:
        print(val)
    binarysearch(arr,9,0,len(arr)-1)

if __name__ == '__main__':
    import cProfile
    cProfile.run("main()")
