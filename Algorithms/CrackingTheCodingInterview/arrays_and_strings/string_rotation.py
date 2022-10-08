"""
there is a method to check if one is a substring of other
you have to use it only once
xy = waterbottle
yx = erbottlewa
so yx will be a substring of xyxy
"""


def is_substring(str1, str2):
    pass


s1 = input()
s2 = input()

if len(s1) != len(s2):
    print('Not Substring')

if is_substring(s1+s1, s2):
    print('YES')
else:
    'NO'
