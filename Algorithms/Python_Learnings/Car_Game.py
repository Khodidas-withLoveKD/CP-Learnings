"""
    help - to get the below list
    ----
    start - to start the car
    stop - stop the car
    quit - quit the game
"""


def show_commands():
    print("""start - to start the car
stop - to stop the car
quit - to stop the game""")


print("Type 'Help' to get the list of commands")
user_input = ''
car_started = False

while user_input != 'quit':
    print('-----')
    user_input = input('Enter your command: ').lower()
    if user_input == 'help':
        show_commands()
    elif user_input == 'start':
        if car_started:
            print('Car is already started')
        else:
            print('The car has started. Vroom Vroom!!!')
            car_started = True
    elif user_input == 'stop':
        if not car_started:
            print('Car is already stopped')
        else:
            print('The car stopped. SCREEEEEECH!!!')
            car_started = False
    elif user_input == 'quit':
        print('Game Over!!')
    else:
        print("I didn't understand that. Try Again")
