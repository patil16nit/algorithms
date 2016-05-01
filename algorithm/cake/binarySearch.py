def binary(targets, num):
    floor_index = -1
    ceiling_index = len(targets)
    while floor_index +1 < ceiling_index:
        distance = ceiling_index + floor_index
        half_distance = int((ceiling_index-floor_index))/2+1
        guess_index = half_distance + floor_index
        guess_value = targets[guess_index]
        if guess_value == num:
            return True
        if num < guess_value:
            ceiling_index = guess_index
        else:
            floor_index = guess_index
    return False


targets = [1,3,5,6,7]
search = binary(targets, 5)
print(search)
