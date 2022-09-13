dict = {}

dict[1] = 'a'
dict[5] = 'b'
dict[3] = 'c'
dict[2] = 'd'
dict[4] = 'e'

print("Dict: ",dict)
print("Sorted by key: ", sorted(dict.keys()))
print("Sorted by items: ", sorted(dict.items()))
print("Sorted by values: ", sorted(dict.items(), key = lambda item: item[1]))
print("Sorting itmes by key another way: ", sorted(dict.items(), key = lambda item: item[0]))

if a in dict(key = lambda item: item[1]):
    print("Present")
else:
    print("NOT")
