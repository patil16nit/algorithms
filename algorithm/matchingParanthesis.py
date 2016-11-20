def matchingParanthesis(message):
    lists = []
    dict = {'}':'{', ']':'[', ')':'('}
    notFirst = False
    for i in xrange(len(message)):
        if message[i] in ["{", "[", "("]:
            notFirst = True
            lists.append(message[i])
        elif message[i] in ["}", "]", ")"]:
            if not lists and notFirst == True:
                return True
            elif not lists and notFirst == False:
                return False
            else:
                top = lists[len(lists)-1]
                if dict[message[i]] == top:
                    lists.pop()
    if not lists:
        return True
    else:
        return False

def main():
    message = raw_input("Enter the string that you want to verify : ")
    print matchingParanthesis(message)

if __name__ == "__main__":
    import cProfile
    cProfile.run("main()")
