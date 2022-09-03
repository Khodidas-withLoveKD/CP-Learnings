test_str = 'Python Hey there'
test_str_single_quotes = 'Hey "Guys" there'
test_str_double_quotes = "Hey Guy's there"

print(test_str)
print(test_str[0])
print(test_str[-2])
print(test_str_single_quotes)
print(test_str_double_quotes)

print(test_str[0:3])
print(test_str[0:])
print(test_str[:3])
print(test_str[-4:-1])

# copy a variable
str_copy = test_str[:]
print('str_copy = ' + str_copy)

# formatted string
# same as that of stiring literals in js
print('FORMATTED STRING\n-------')
first_name = 'Khodidas'
last_name = 'Chauhan'
concated_string = first_name + ' [' + last_name + '] is a coder'
formatted_string = f'{first_name} [{last_name} is a coder {{}}'
print(concated_string)
print(formatted_string)


print('STRING METHODS\n========')
print(test_str.upper())
print(test_str.lower())
print(test_str.swapcase())
print(test_str.title())
print(test_str)
print(test_str.find('o'))
print(test_str.find('O'))
print(test_str.find('the'))
print(test_str.replace('there', 'everywhere'))
print(test_str.replace('There', 'everywhere'))
print('Python' in test_str)
print('python' in test_str)
print(len(test_str))
