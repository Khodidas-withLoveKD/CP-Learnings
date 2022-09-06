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
car_state = ''

while user_input != 'quit':
    print('-----')
    user_input = input('Enter your command: ').lower()
    if user_input == 'help':
        show_commands()
    elif user_input == 'start':
        if car_state == 'started':
            print('Car is already started')
        else:
            print('The car has started. Vroom Vroom!!!')
            car_state = 'started'
    elif user_input == 'stop':
        if car_state == 'stopped':
            print('Car is already stopped')
        else:
            print('The car stopped. SCREEEEEECH!!!')
            car_state = 'stopped'
    elif user_input == 'quit':
        print('Game Over!!')
    else:
        print("I didn't understand that. Try Again")
