def nth_fibonacci(n):
    if n in [0,1]:
        return n
    return nth_fibonacci(n-1) + nth_fibonacci(n-2)


num =input("enter int : ")
print(nth_fibonacci(int(num)))
