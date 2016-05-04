def minimumTransform(str1, str2):
    n=len(str1)
    m=len(str2)
    if n!=m:
        return -1
    count = [0]*265
    for i in range(n):
        count[ord(str2[i])]+=1
    for j in range(n):
        count[ord(str1[j])]-=1
    for i in range(256):
        if count[i]:
            return -1
    # find minimum operations required
    res=0
    i,j=n-1,n-1
    while i>=0:
        while i>=0 and str1[i]!=str2[j]:
            i-=1
            res+=1
        if i>=0:
            i-=1
            j-=1
    return res

def main():
    print(minimumTransform('EACBD', 'EABCD'))

if __name__:
    import cProfile
    cProfile.run("main()")

        
