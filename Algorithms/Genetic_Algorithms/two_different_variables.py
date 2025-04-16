"""
We will use genetic algorithms to get answer for two variables
Mathematically we will need two equations to solve two variables
Will try with one first
Eqn: x + y = 0
There can be lots of pairs of ans viz. (-1, 1), (-2, 2), etc.

Little difficult but will see
--––––––––––––––––––
Now, we will try with two linear equations
2x + y = 11
x - y = 1
Ans: x = 4, y = 3
"""
import random


# PARAMS
POPU_SIZE = 50
NO_OF_GENS = 50
GENERATION_RANGE = (-10, 10)
MUTATION_RATE = 0.1


def create_individual():
    x = random.uniform(*GENERATION_RANGE)
    y = random.uniform(*GENERATION_RANGE)
    return x, y


def generate_population():
    return [create_individual() for _ in range(POPU_SIZE)]


def fitness(individual):  # the most crucial part
    # the main concern lie with two linear equations is the fitness part
    # that how do we decide the fitness
    # ------
    # there are two equations
    # we understand that 2x + y should be near to 11 and x - y should be 1
    # so fitnesss_1 => - abs(2x + y - 11)
    # and fitness_2 => - abs(x - y)
    # how do we club this together?
    # Do the average?
    # No, doing total error helps more => less error = fitter individual
    x, y = individual
    error_1 = abs(2*x + y - 11)
    error_2 = abs(x - y - 1)
    total_error = error_1 + error_2

    return - total_error


def select_parent(population):
    # randomly select two values
    a, b = random.sample(population, 2)
    return a if fitness(a) > fitness(b) else b


def crossover(parent_1, parent_2):
    # will do simple average
    parent_1_x, parent_1_y = parent_1
    parent_2_x, parent_2_y = parent_2

    new_x = (parent_1_x + parent_2_x) / 2
    new_y = (parent_1_y + parent_2_y) / 2
    return new_x, new_y


def mutate(individual):
    mutation_chance = random.random()
    if mutation_chance <= MUTATION_RATE:
        # adding more randomness to get more random answer
        noise_for_x = random.uniform(-1, 1)
        x, y = individual
        x += noise_for_x
        noise_for_y = random.uniform(-1, 1)
        y += noise_for_y

        individual = (x, y)

    return individual


def genetic_algorithm():
    population = generate_population()

    for i in range(NO_OF_GENS):
        new_population = []

        # the challenge lies here in creating population
        # because those two who workout together the best should be kept together
        # but if you initially generate 10 pairs, then they won't be the best for sure
        # so we will inter crossover as well
        # so x1 will crossover with y1, y2, ... y10. Same goes for x2, x3 and so on...
        # -----------------------
        # But the above approach causes crossover issues
        # so, instead we will randomly select two fitter parents and do the crossover of the x,y pair
        for j in range(POPU_SIZE):
            # get parents
            parent_1 = select_parent(population)
            parent_2 = select_parent(population)
            child = crossover(parent_1, parent_2)
            child = mutate(child)

            new_population.append(child)

        population = new_population
        best = max(population, key=fitness)
        best_x, best_y = best
        print(f'Best in Generation {i+1}: x = {best_x:.4f} | y = {best_y:.4f} | fitness = {fitness(best):.4f}')

    best_solution = max(population, key=fitness)
    return best_solution


best_solution = genetic_algorithm()
best_x, best_y = best_solution
print(f'======\nBest overall: x = {best_x:.4f} | y = {best_y:.4f}  | fitness = {fitness(best_solution):.4f}')
