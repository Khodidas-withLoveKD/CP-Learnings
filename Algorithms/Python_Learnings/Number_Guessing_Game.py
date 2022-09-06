'''
    Guess the number between 0 to 9 (randomly generated)
    Give them max 3 tries
    Give them the warning messages like 'Too high/low'
    Result Messages - You Won :), Oops! You Lost
    Also, show them the no. of attempts left
'''
import random

number_to_be_guessed = random.randint(0, 9)
print(f'Ans = {number_to_be_guessed}')
attempts_left = 3

while attempts_left:
    print(f'---------\nAttempt: {3 - attempts_left + 1}')
    user_guess = int(input('Enter your guess: '))
    if user_guess < number_to_be_guessed:
        print('Too Low')
    elif user_guess > number_to_be_guessed:
        print('Too High')
    else:
        print('Yaaayyy!!! You guessed it correctly :)')
        break
    attempts_left -= 1
else:  # Will get executed if we jump out of the while loop using break
    print('=======\nAwwww :( Better luck next time Buddy')
