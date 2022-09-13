# import only system from os
from os import system, name
# import sleep to show output for some time period
from time import sleep

# define our clear function
def clear():
    # sleep for 2 seconds after printing output
    sleep(2)
    # for windows
    if name == 'nt':
        _ = system('cls')

    # for mac and linux(here, os.name is 'posix')
    else:
        _ = system('clear')

for i in range(10):
    # print out some text
    print('Connect four\n'*5)
    # now call function we defined above
    clear()
