import random

members = ['Khodidas', 'Kiran', 'Pooju', 'Jayu', 'Rudu']
for i in range(5):
    print(f'Leader = {random.choice(members)}')

print('==== EXERCISE: DICE ROLL ====')


class Dice:
    def __init__(self):
        self.dice = None

    def roll(self):
        # Will interpret this as a tuple itself
        return random.randint(1, 6), random.randint(1, 6)


dice1 = Dice()
for i in range(3):
    print(dice1.roll())
