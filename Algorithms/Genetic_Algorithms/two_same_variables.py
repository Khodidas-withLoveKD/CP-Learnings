import random

"""
Solve the equation:
x^2 - x - 6 = 0

The approach could be little different here as x can have two values (+3 & -2) . Will see
"""


# PARAMS
POPU_SIZE = 10
NO_OF_GENS = 50
GENERATION_RANGE = (-10, 10)
MUTATION_RATE = 0.1


def create_individual():
    return random.uniform(*GENERATION_RANGE)


def generate_population():
    return [create_individual() for _ in range(POPU_SIZE)]


def fitness(x):  # the most crucial part
    return - abs(x**2 - x - 6)


def select_parent(population):
    # randomly select two values
    a, b = random.sample(population, 2)
    return a if fitness(a) > fitness(b) else b


def crossover(parent_1, parent_2):
    # will do simple average
    return (parent_1 + parent_2) / 2


def mutate(individual):
    mutation_chance = random.random()
    if mutation_chance <= MUTATION_RATE:
        noise = random.uniform(-1, 1)
        individual += noise

    return individual


def genetic_algorithm():
    population = generate_population()

    for i in range(NO_OF_GENS):
        new_population = []

        for j in range(POPU_SIZE):
            # get parents
            parent_1 = select_parent(population)
            parent_2 = select_parent(population)

            child = crossover(parent_1, parent_2)
            child = mutate(child)

            new_population.append(child)

        population = new_population
        best = max(population, key=fitness)
        print(f'Best in Generation {i+1}: {best:.4f} | fitness = {fitness(best):.4f}')

    best_solution = max(population, key=fitness)
    return best_solution


best_solution = genetic_algorithm()
print(f'Best overall: {best_solution:.4f} | fitness = {fitness(best_solution):.4f}')

