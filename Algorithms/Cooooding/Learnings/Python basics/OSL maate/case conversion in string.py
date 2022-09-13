#convert case of string

def changeCase(string):
    string = list(string)
    for i in range(len(string)):
        if string[i].isupper():# >= 'A' and string[i] <= 'Z':
            #change to lower change
            string[i] = string[i].lower()
            print(string[i])
        elif string[i] >= 'a' and string[i] <= 'z': # or string[i].islower() both will work
            print("Inside Else")
            #change to upper change
            string[i] = string[i].upper()
    string = ''.join(string)
    return string
#---------------------

string = "Hey Man How Are You"
#print(string.swapcase())
string = changeCase(string)
print(string)
