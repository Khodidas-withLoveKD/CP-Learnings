try:
    age = int(input('Enter your Age: '))
    income = 2000
    risk = income/age
    print(f'Your age is {age}')
except ValueError:
    print('Invalid input')
except ZeroDivisionError:
    print('Age cannot be zero')

print('=== END ===')
