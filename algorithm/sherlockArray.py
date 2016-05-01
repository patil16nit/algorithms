# Enter your code here. Read input from STDIN. Print output to STDOUT
n=int(input())
for i in range(0,n):
    length=int(input())
    raw_data=input()
    data=raw_data.split(' ')
    flag=0
    if len(data) == length:
        sum_less=[None]*len(data)
        sum_more=[None]*len(data)
        sum=0
        for i,val in enumerate(data):
            if i==0:
                sum_less[i]=sum
            else:
                sum=sum+int(data[i-1])
                sum_less[i]=sum
        sum=0
        j=len(data)-1
        while j>=0:
            if j==len(data)-1:
                sum_more[j]=sum
            else:
                sum=sum+int(data[j+1])
                sum_more[j]=sum
            j=j-1
        
        for d in range(0, len(data)):
            if sum_less[d]==sum_more[d]:
                flag=1
                print("YES")
        if flag==0:
            print("NO")
