'''
	By: facug91
	From: https://projecteuler.net/problem=19
	Name: Counting Sundays
	Date: 31/12/2016
'''

import calendar as ca

mycalendar = ca.Calendar()
ans = 0
for year in xrange(1901, 2001):
    for month in mycalendar.yeardays2calendar(year, 12)[0]:
        for week in month:
            for day in week:
                if (day[0] == 1 and day[1] == 6):
                    ans += 1
print ans
