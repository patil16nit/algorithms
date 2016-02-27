def fibo(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        print(n)
        return fibo(n-1) + fibo(n-2)


def main():
    d=input()
    data=fibo(int(d))
    print(data)

if __name__:
    import cProfile
    cProfile.run("main()")
