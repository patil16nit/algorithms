def reverseString(msg, start, end):
    while start < end:
        msg[start], msg[end] = msg[end], msg[start]
        start += 1
        end -= 1
    return ''.join(msg)

def confusingParanthesis(message):
    word_start = 0
    msg = list(message)
    reverseString(msg, 0, len(msg)-1)
    for charPosition in xrange(len(message)):
        if (charPosition == len(message) or msg[charPosition] == ' '):
            reverseString(msg, word_start, charPosition -1)
            word_start=charPosition+1
    return ''.join(msg)

def main():
    message = raw_input("Enter the message to reverse it : ")
    print confusingParanthesis(message)

if __name__ == '__main__':
   import cProfile
   cProfile.run("main()")
