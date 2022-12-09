'''
	By: facug91
	From: http://www.spoj.com/problems/TOANDFRO/
	Name: To and Fro
	Number: 400
	Date: 05/09/2010
'''

import sys

texto = []
n = int(sys.stdin.readline())
while (n != 0):
    t = sys.stdin.readline().strip()
    oracion = (n,t)
    texto.append(oracion)
    n = int(sys.stdin.readline())
for x in texto:
    oracion = ''
    filas = len(x[1]) / x[0]
    for i in range(x[0]):
        pos = i
        pasada = 0
        for j in range(filas):
            oracion = oracion + x[1][pos]
            if (pasada % 2 == 0):
                pasada = 1
                pos += x[0]*2-1-2*i
            else:
                pasada = 0
                pos += 1+2*i
    print oracion 
