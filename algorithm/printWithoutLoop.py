def printWithoutLoop(x):
    if x<=0:
        print(x)
        return
    print(x)
    printWithoutLoop(x-5)
    print(x)

def main():
    data=input("number for loop :")
    printWithoutLoop(int(data))


if __name__:
    import cProfile
    cProfile.run("main()")
