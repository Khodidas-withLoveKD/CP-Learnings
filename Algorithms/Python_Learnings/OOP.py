class Point:
    def draw(self):
        print('draw')

    def move(self):
        print('Move')


point_1 = Point()
print(point_1.draw())
print(point_1.move())
# assigning attributes
point_1.x = 1
print(point_1.x)
# throws error because y attribute for point_1 is not defined
# print(point_1.y)

point2 = Point()
# throws error because point_1 and point2 are two different instances
# print(point2.x)
# instance?
point3 = point_1
print(f'Point3.x = {point3.x}')
point3.z = 2
print(f'Point1.z = {point_1.z}')


class Point2:
    def __init__(self, x, y):
        self.x = x
        self.y = y


print('==== AFTER ADDING CONSTRUCTOR ====')
point4 = Point2(10, 20)
print(point4.x)
print(point4.y)
point4.x = 12
print(point4.x)

print('=== EXERCISE ===')


class Person:
    def __init__(self, input_name):
        self.name = input_name

    def talk(self):
        print(f'{self.name} is talking!!')


person1 = Person('Khodidas')
print(person1.talk())
person2 = Person('Kiran')
print(person2.talk())


print('\n====== INHERITANCE ====')


class Mammal:
    def walk(self):
        print('walk')


class Dog(Mammal):
    def bark(self):
        print('bark')


class Cat(Mammal):
    def meow(self):
        print('meow')


dog = Dog()
dog.walk()
dog.bark()
cat = Cat()
cat.walk()
cat.meow()

