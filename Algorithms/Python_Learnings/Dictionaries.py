import datetime

customer = {
    'name': 'Khodidas',
    'age': 24,
    'is_single': False
}

print(customer)
print(customer.get('name'))
print(customer['name'])
# Below two will give error
# print(customer['birthdate'])
# print(customer['Name'])
# below will not
print(customer.get('Name'))
# give a default value (same as Map.getOrDefault() of java)
print(customer.get('birthdate', 'Jan 1 2004'))
# modify a value
customer['name'] = 'Kiran'
print(customer['name'])
# add a new key-value pair
customer['birth_date'] = datetime.date(2002, 4, 13)
print(customer['birth_date'])

print('==== EXERCISE: TRANSLATE PHONE NUMBER TO WORD ====')
# get the number in input
lucky_number = input('Enter you lucky number (No matter how long): ')
numbers_map = {
    '0': 'Zero',
    '1': 'One',
    '2': 'Two',
    '3': 'Three',
    '4': 'Four',
    '5': 'Five',
    '6': 'Six',
    '7': 'Seven',
    '8': 'Eight',
    '9': 'Nine',
}
ans = ''
# split each digit
for num in lucky_number:
    ans += numbers_map[num] + ' '
# map each digit to it's spelling and store it in a variable
print(f'Your lucky number is: {ans}')
