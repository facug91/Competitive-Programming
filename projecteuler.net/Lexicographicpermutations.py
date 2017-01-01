'''
	By: facug91
	From: https://projecteuler.net/problem=24
	Name: Lexicographic permutations
	Date: 01/01/2017
'''

def next_permutation (perm):
    curr = len(perm)-1
    while curr > 0 and perm[curr-1] >= perm[curr]:
        curr -= 1
    if (curr == 0):
        return False
    pivot = curr - 1
    pivot2 = len(perm)-1
    while perm[pivot2] <= perm[pivot]:
        pivot2 -= 1
    perm[pivot] , perm[pivot2] = perm[pivot2] , perm[pivot]
    perm[curr:] = reversed(perm[curr:])
    return True

perm = range(10)
for x in xrange(1, 1000000):
    next_permutation(perm)
print perm
