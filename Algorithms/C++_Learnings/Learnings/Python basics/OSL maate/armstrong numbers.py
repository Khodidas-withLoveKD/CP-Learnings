import math

def findLength(num):
    count = 0
    while int(num) > 0:
        count += 1
        num /= 10
        print("num =", num)
    print("count =",count)
    return count

def checkArmstrong(num):
    length = findLength(num)
    ans = 0

    while int(num) > 0:
        rem = num % 10
        ans += rem**length
        num = num/10
    return ans

num = 9
if num == checkArmstrong(num):
    print("armstrong")
else:
    print("Not anmstrong")
