'''
	By: facug91
	From: https://projecteuler.net/problem=14
	Name: Longest Collatz sequence
	Date: 27/12/2016
'''

DP = [-1 for x in xrange(1000001)]

def collatz (n):
    ans = 0
    if (n <= 1000000):
        if (DP[n] != -1): return DP[n]
    if (n == 1): ans = 1
    elif (n % 2 == 0): ans = collatz(n/2) + 1
    else: ans = collatz(n*3+1) + 1
    if (n <= 1000000): DP[n] = ans
    return ans

if __name__ == '__main__':
    ans = 0
    for i in xrange(1, 1000001):
        collatz(i)
        if (DP[i] > DP[ans]): ans = i
    print ans
