def denomilies(amount_left, avail_denomination):
    if amount_left == 0:
        return 1
    if amount_left < 0:
        return 0

    if len(avail_denomination) == 0:
        return 0
    
    cur_coin, denomination_left = avail_denomination[0], avail_denomination[1:]

    num_possibilities=0
    while(amount_left > 0):
        num_possibilities += denomilies(amount_left, denomination_left)
        amount_left -= cur_coin
    
    return num_possibilities 

def main():
    d = input("Enter amount")
    s = input("enter array element")
    
    num=[]
    for i in s.split(" "):
        num.append(int(i))
    print(num)
    possibilities = denomilies(int(d), num)
    print("NUmber of possibilities ",possibilities) 

if __name__:
    import cProfile
    cProfile.run("main()")
