def countingSort(list, max_value):
    num_list =[0] * (max_value+1)
    for item in list:
        num_list[item] +=1
    print(num_list)
    sorted_list=[]
    for item, count in enumerate(num_list):
        for time in range(count):
            sorted_list.append(item)
    return sorted_list

def main():
    data=[1, 4, 1, 2, 7, 5, 2]
    print(data)
    sorted_data=countingSort(data, 9)
    print(sorted_data)


if  __name__:
    import cProfile
    cProfile.run("main()")
