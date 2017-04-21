'''
	By: facug91
	From: https://projecteuler.net/problem=23
	Name: Non-abundant sums
	Date: 01/01/2017
'''


def sum_of_proper_divisors (num):
    i = 2; sum = 1
    while i*i <= num:
        if num % i == 0:
            sum += i
            if i*i != num:
                sum += num/i
        i += 1
    return sum

def is_sum_of_abundants (num, sumd, abundants):
    for x in abundants:
        if x+2 > num:
            return False
        if sumd[num-x] > num-x:
            return True
    return False

sumd = [ sum_of_proper_divisors(x) for x in xrange(28200) ]

abundants = []
for x in xrange(2, 28200):
    if (x < sumd[x]):
        abundants.append(x)

ans = 0
for x in xrange(28200):
    if not is_sum_of_abundants(x, sumd, abundants):
        ans += x

print ans
