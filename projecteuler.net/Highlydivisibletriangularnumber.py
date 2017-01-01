'''
	By: facug91
	From: https://projecteuler.net/problem=20
	Name: Highly divisible triangular number
	Date: 31/12/2016
'''

from math import sqrt

def number_of_divisors (number):
    ans = 0
    for i in xrange(1, int(sqrt(number+0.0))+1):
        if number % i == 0:
            ans += 2
            if (number/i == i):
                ans -= 1
    return ans

if __name__ == '__main__':
    max_div = -1
    ans = 0
    num = 1
    for x in xrange(2, 15000):
        num += x
        if (max_div < number_of_divisors(num) and max_div < 500):
            max_div = number_of_divisors(num)
            ans = num
    print "Val " + str(ans) + " max " + st
