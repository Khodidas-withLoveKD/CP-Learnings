def square(n):
    n *= n


num = 10
print(f'Before num = {num}')
square(num)
print(f'AFTER num = {num}')
# number behaves as poss by value


def change_name(naam):
    naam += "Kiran"


name = "KD"
print(f'BEFORE NAme = {name}')
change_name(name)
print(f'AFTER NAme = {name}')
# same for string


def change_dict(d):
    d['KD'] = 'Kiran'


dictionary = {'KIRAN': 'KD'}
print(f'BEFORE dict={dictionary}')
change_dict(dictionary)
print(f'AFTER dict={dictionary}')
#  pass by arguments


def change_list(l):
    l.append(10)


nums = [1, 2, 3]
print(f'BEFORE nums={nums}')
change_list(nums)
print(f'AFTER nums={nums}')





