print('IF STATEMENTS')
price_of_house = 1000000
has_good_credit = True

if has_good_credit:
    down_payment = price_of_house * 0.1
else:
    down_payment = price_of_house * 0.2

print(f'Down_payment you have to pay is: Rs {round(down_payment) if down_payment.is_integer() else down_payment}')

print('-----\nName exercise')
name = 'KhodidasKhodidasKhodidasKhodidasKhodidasKhodidasKhodidasKhodidasKhodidasKhodidasKhodidas'
if len(name) < 3:
    print('Must be at least 3 characters')
elif len(name) > 50:
    print('Cannot have more than 50 characters')
else:
    print('The name looks good')

print('------\nPound to Kg exercise')
# take input weight
weight = float(input('Enter your weight: '))
# ask if in kg or pound
weight_type = input('(L)bs or (K)gs: ').upper()
# give the converted value
if weight_type == 'L':
    current_weight = weight * 0.45
    print(f'Your weight is {round(current_weight, 2)} Kgs')
elif weight_type == 'K':
    current_weight = weight * 2.2
    print(f'Your weight is {round(current_weight, 2)} Lbs')
else:
    print('Incorrect weight category\n Try Again')
