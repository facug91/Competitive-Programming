'''
	By: facug91
	From: https://projecteuler.net/problem=22
	Name: Names scores
	Date: 31/12/2016
'''

file = open('/home/facug91/Desktop/p022_names.txt', 'r')
names = sorted(file.readline().replace('\"', '').split(','))
scores = [ sum(ord(x)-ord('A')+1 for x in names[i]) * (i+1) for i in xrange(len(names)) ]
print sum(scores)
