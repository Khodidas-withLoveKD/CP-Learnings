str = "Myasasasasas name is Khodidas"
li = str.split(" ")
li.sort(key = lambda str: len(str) > 5, reverse = True)

li2 = []
li2 = list(filter(lambda str: len(str) > 5, li))
print(li)
print("list_2 =", li2)
