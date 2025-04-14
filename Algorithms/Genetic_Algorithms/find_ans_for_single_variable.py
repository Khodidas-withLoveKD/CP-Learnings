import random

"""
We will try to simulate how genetic algorithms work

Maximize the function f(x) = x^2
(The goal is to find the value of x between -10 and 10 that gives the highest square.)

How they work is:
1. Decide a solution chromosome (or solution)
2. Generate initial population
3. Evaluate fitness
4. Select parents
5. Do crossover - produce offsprings
6. Do mutation
7. Give the best solution
"""

# Basic Parameters
GENES_RANGE = (-10, 10)
NUM_OF_GENS = 50
POPU_SIZE = 10
MUTATION_RATE = 0.1  # the chances that mutation should be done. Here it means, there are 10% chances that mutation will be done


def create_individual():
    return random.uniform(*GENES_RANGE)


def create_population():
    return [create_individual() for _ in range(POPU_SIZE)]


def fitness(val):
    # return val**2 - 25
    return val ** 2


def select_parent(population):  # we have used tournament selection here
    a, b = random.sample(population, 2)
    return a if fitness(a) > fitness(b) else b


def do_crossover(parent_a, parent_b):
    # simple average for crossover
    return (parent_a + parent_b) / 2


def mutate(individual):
    mutation_chance = random.random()
    if mutation_chance <= MUTATION_RATE:
        # add small noise
        mutation_value = random.uniform(-1, 1)
        individual += mutation_value
        # clip to valid range
        individual = max(GENES_RANGE[0], min(individual, GENES_RANGE[1]))

    return individual


def genetic_algorithm():
    population = create_population()
    # the main loop
    # go on producing till Nth generation
    for generation in range(NUM_OF_GENS):
        # create new generation (by crossover and mutation)
        new_population = []

        for _ in range(POPU_SIZE):
            # select parents
            parent_1 = select_parent(population)
            parent_2 = select_parent(population)

            # do crossover
            child = do_crossover(parent_1, parent_2)

            # mutate
            child = mutate(child)

            new_population.append(child)

        population = new_population
        # Get the fittest in this generation
        best = max(population, key=fitness)
        print(f'Best in Generation {generation + 1} | value = {best:.4f} | fitness = {fitness(best):.4f}')

    return max(population, key=fitness)


best_solution = genetic_algorithm()
print(f'Best Overall value = {best_solution:.4f} | fitness = {fitness(best_solution):.4f}')
