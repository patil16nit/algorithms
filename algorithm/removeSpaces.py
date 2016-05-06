def removeSpaces(str,l):
    if len(str)-1== l:
        return str
    if str[l]==' ':
        str= str[:l]+str[l+1:]
        print("one space removes: ", str)
        str=removeSpaces(str, l)
    else:
        str=removeSpaces(str,l+1)
    return str

def main():
    s=input("input string with spaces")
    print(removeSpaces(s,0))


if __name__:
    import cProfile
    cProfile.run("main()")


