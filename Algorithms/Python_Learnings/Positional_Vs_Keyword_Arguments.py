# parameters and arguments are different --> How?
def greet_user(first_name, last_name):
    print(f'Hi {first_name} {last_name}')
    print('Welcome aboard')
    print('---------')


print(f'Positional Argument Function greet_user("Kiran", "Chauhan"):\n{greet_user("Kiran", "Chauhan")}')
print(f'Keyword Argument Function \ngreet_user(first_name="Kiran", last_name="Chauhan"):\n{greet_user(first_name="Kiran", last_name="Chauhan")}')
print(f'Keyword Argument Function \ngreet_user(last_name="Kiran", first_name="Chauhan"):\n{greet_user(last_name="Kiran", first_name="Chauhan")}')
print(f'Keyword + Positional Argument Function \n'
      f'Positional should be first and then Keyword Args'
      f'\ngreet_user("Kiran", last_name="Chauhan"):\n{greet_user("Kiran", last_name="Chauhan")}')
# Throws error
# greet_user(first_name="Kiran", "Chauhan")

# Output of below?
# print(f'Different Test \ngreet_user("Kiran", first_name="Chauhan"):\n{greet_user("Kiran", first_name="Chauhan")}')


