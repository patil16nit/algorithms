def fibo(n,f,s):
    
    if f == s:
        print('f == s ', n)
        if n <= f-1:
            return 0;
        elif n == f:
            return f
        else:
            return ((fibo((n-1),f,s))**2 + fibo((n-2),f,s))
    else:
        print('data -> ', n)
        if n == f:
            return f
        elif n == s:
            return s
        else:
            return ((fibo((n-1),f,s))**2 + fibo((n-2),f,s))

def main():
    d=input()
    data=fibo(int(d),1,1)
    print(data)

if __name__:
    import cProfile
    cProfile.run("main()")
