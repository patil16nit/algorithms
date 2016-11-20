
def permutationPalindrom(msg, start, end):
    if start == end:
        print ''.join(msg)
    else:
        for i in xrange(start, end+1):
            msg[start], msg[i] = msg[i], msg[start]
            permutationPalindrom(msg, start+1, end)
            msg[start], msg[i] = msg[i], msg[start]
     
    

def main():
    message = raw_input("Enter the string for validation of permuation palindrom : ")
    msg = list(message)
    permutationPalindrom(msg, 0, len(message)-1)




if __name__ == "__main__":
    import cProfile
    cProfile.run("main()")

