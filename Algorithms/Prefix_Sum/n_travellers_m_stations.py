"""
This was asked in DE shaw interview
x-----x-----------x-------------x-------------x------------x
0     1           2             3             4            5

N=5
Travellers = [(1, 4), (3, 5)]

Output -> [0, 1, 2, 2, 1]
              s1   e1,s2 e2
           0  1  1   2. 1

--------
N=5
Travellers = [(1, 4), (2, 5), (1,3), (2,4)]
         0. 1.  2. 3  4. 5
Output -> [0, 0, 0, 0, 0]
              s. e
                 s.     e
              s.     e
                 s   e
           0, 2, 4,  4,  1

positions = [(0,0), (2, 1)]
Algo
1. For each traveller:
    2. consider all the indexes it will visit
    3. Add them in output
"""


def getSegmentCount(travellers, n):
    output = [0] * n
    m = len(travellers)
    positions = [(0, 0)] * n

    for traveller in travellers:
        start, end = traveller
        output[start] += 1
        if end < n:
            output[end] -= 1

    # do the prefix sum
    for i, num in enumerate(output):
        if i > 0:
            output[i] += output[i-1]

    print(output)

travellers = [(1, 4), (2, 5), (1,3), (3,5)]
n = 5
getSegmentCount(travellers, n)