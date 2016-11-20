def findEndParanthesis(message, startPosition):
    isOpen = 0
    charPosition=startPosition+1
    while charPosition <= len(message)-1: 
        char = message[charPosition]
        if message[charPosition] == '(' :
            isOpen += 1
        elif message[charPosition] == ')': 
            if isOpen == 0:
                return charPosition
            else:
                isOpen -= 1
        charPosition +=1
    raise Exception("No closing parenthesis :(") 

def main():
    message = raw_input("Entere the paranthesis string : ")
    startPosition = int(raw_input("Enter position of the start paranthesis : "))
    print findEndParanthesis(message, startPosition)


if __name__ == '__main__':
    import cProfile
    cProfile.run('main()')
