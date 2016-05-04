def validParanthesis(str):
    print(str)
    stack=[]
    count=0
    for i in str:
        if '(' == i:
            stack.append(i)
        else:
            if stack:
                stack.pop()
                count+=2
    print(count)

def main():
    s=input("Enter parantheses : ")
    s=list(s)
    validParanthesis(s)
    

if __name__:
    import cProfile
    cProfile.run("main()")
