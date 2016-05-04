def stringPalindrom(str):
    for i, j in  enumerate(str):
        if j != str[-i-1]:
            return False
    return True

def main():
    str=input("Enter string for palindrom check :")
    if stringPalindrom(str):
        print("Palindrom")
    else:
        print("not a Palindeom")

if __name__:
    import cProfile
    cProfile.run("main()")
