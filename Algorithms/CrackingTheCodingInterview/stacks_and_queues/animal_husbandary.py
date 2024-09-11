"""
Animal Shelter: An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first out"basis.
Peoplemustadopteitherthe"oldest"(basedonarrivaltime)ofallanimalsattheshelter, or they can select whether they would
prefer a dog or a cat (and will receive the oldest animal of that type). They cannot select which specific animal
they would like. Create the data structures to maintain this system and implement operations such as enqueue,
dequeueAny, dequeueDog, and dequeueCat. You may use the built-in Linkedlist data structure.
"""
from enum import Enum


class AnimalType(Enum):
    CAT = 'Cat'
    DOG = 'Dog'


# LL node -> data, next
class Node:
    def __init__(self, animal_type, next=None):
        self.animal_type = animal_type
        self.next = next


# animal_shelter -> global vars - dog/cat_count
class AnimalShelter:
    def __init__(self):
        # create ll
        # enque at tail, # deque from head
        self.tail = None
        self.sentinel_node = Node(None)
        self.dog_count = 0
        self.cat_count = 0
        print('INIT time | ', end=" ")
        self.current_queue()

    def enqueue_any(self, animal_type):
        # if no animal in shelter
        # print('-- BEFORE EnQ ---')
        # self.current_queue()
        print(f'Enqueing {animal_type}')
        if self.tail is None:
            print('tail is None')
            self.tail = Node(animal_type)
            self.sentinel_node.next = self.tail
        else:
            print(f'tail is {animal_type}')
            self.tail.next = Node(animal_type)
            self.tail = self.tail.next
        if animal_type == AnimalType.CAT:
            self.cat_count += 1
        else:
            self.dog_count += 1
        print('--- AFTER Enqu --- | ', end="")
        self.current_queue()

    def deque_any(self):
        # if no animal in shelter
        if self.sentinel_node.next is None:
            print('No animals in shelter')
        else:
            print(f'Adopted animal type = {self.sentinel_node.next.animal_type}')
            if self.sentinel_node.next.animal_type == AnimalType.DOG:
                self.dog_count -= 1
            else:
                self.cat_count -= 1
            self.sentinel_node.next = self.sentinel_node.next.next
            # if current node is tail
            if self.sentinel_node == self.tail:
                # make it None
                self.tail = None
            print('--- AFTER deque Any --- | ', end="")
            self.current_queue()

    def __deque_animal_of_specific_type(self, animal_type):
        pred = self.sentinel_node
        temp = self.sentinel_node.next
        while temp.animal_type != animal_type:
            pred = temp
            temp = temp.next
        print(f'Here is your animal of Type = {temp.animal_type}')
        pred.next = temp.next
        # if current node is tail
        if temp == self.tail:
            # make it None
            self.tail = None

    def deque_cat(self):
        if self.cat_count == 0:
            print('No cats in shelter')
            return
        self.cat_count -= 1
        self.__deque_animal_of_specific_type(AnimalType.CAT)
        print('--- AFTER deque CAT --- | ', end="")
        self.current_queue()

    def deque_dog(self):
        if self.dog_count == 0:
            print('No dogs in shelter')
            return
        self.dog_count -= 1
        self.__deque_animal_of_specific_type(AnimalType.DOG)
        print('--- AFTER deque DOG --- | ', end="")
        self.current_queue()

    def current_queue(self):
        temp = self.sentinel_node.next
        # temp = self.sentinel_node
        print('Current Shelter stacks_and_queues: ', end="")
        while temp:
            print(temp.animal_type.value, end="->")
            temp = temp.next
        print('None')

# enqueue -> Node -> data = animal_type
# deque_dog -> based on dog_count travel
# deque_cat -> based on cat_count travel
# d_any -> remove the first one


# Test Casses
# init
shelter = AnimalShelter()
# deque with no animals
shelter.deque_any()
shelter.deque_dog()
shelter.deque_cat()
# inserting one and removing one
shelter.enqueue_any(AnimalType.CAT)
shelter.deque_dog()
shelter.deque_cat()
# inserting one and removing one
shelter.enqueue_any(AnimalType.DOG)
shelter.deque_cat()
shelter.deque_dog()
# appending in que
# D C D C D C
shelter.enqueue_any(AnimalType.DOG)
shelter.enqueue_any(AnimalType.CAT)
shelter.enqueue_any(AnimalType.DOG)
shelter.enqueue_any(AnimalType.CAT)
shelter.enqueue_any(AnimalType.DOG)
shelter.enqueue_any(AnimalType.CAT)
# trying to remove all cats
shelter.deque_cat()
shelter.deque_cat()
shelter.deque_cat()
shelter.deque_cat()
# trying to remove all dogs
shelter.deque_dog()
shelter.deque_dog()
shelter.deque_dog()
shelter.deque_dog()


