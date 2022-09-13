string = "abcedfghijKLMNOPQRSTUVWxyzEeAaI"
count = 0
string = string.lower()
for i in range(len(string)):
    #if string[i] == 'a' or string[i] == 'A' or string[i] == 'e' or string[i] == 'E' or string[i] == 'I' or string[i] == 'i' or string[i] == 'o' or string[i] == 'O' or string[i] == 'u' or string[i] == 'U':
    if string[i] == 'a' or string[i] == 'e' or string[i] == 'o' or string[i] == 'i' or string[i] == 'u':
        count += 1
print("count =",count)
