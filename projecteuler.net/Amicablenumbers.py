'''
	By: facug91
	From: https://projecteuler.net/problem=21
	Name: Amicable numbers
	Date: 31/12/2016
'''

div_sum = [0]*10001

def calc_div_sum (n):
    lo = 2; sum = 1
    while (lo*lo <= n):
        if (n % lo == 0):
            sum += lo
            if (n / lo != lo):
                sum += (n / lo)
        lo += 1
    return sum

for x in xrange(2, 10001): div_sum[x] = calc_div_sum(x)

ans = 0
for x in xrange(2, 10001):
    if (div_sum[x] <= 10000 and div_sum[div_sum[x]] == x and div_sum[x] != x):
        print x
        ans += x

print ans
