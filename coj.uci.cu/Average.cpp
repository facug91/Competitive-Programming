/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1597
	Name: Average
	Number: 1597
	Date: 06/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

struct cmpQueue {
    bool operator() (const double &a , const double &b ) {
        return (a > b);
    }
};

int main () {
	
	int h, l, n, i;
	double result, aux;
	
	cin>>h>>l>>n;
	
	for (;(h) && (l) && (n);) {
	
		priority_queue<double> cola_descendente;
		priority_queue<double, vector<double>, cmpQueue > cola_ascendente;
		
	
		result = 0.0;
		
		i = n;
		for (;i--;) {
			cin>>aux;
			result += aux;
			cola_descendente.push(aux);
			cola_ascendente.push(aux);
		}
		
		n -= h;
		n -= l;
		
		for (;h--;) {
			result -= cola_descendente.top();
			cola_descendente.pop();
		}
		
		for (;l--;) {
			result -= cola_ascendente.top();
			cola_ascendente.pop();
		}
		
		result /= n;
		
		printf("%.6lf\n", result);
		
		cin>>h>>l>>n;
	}
	
	return 0;
}
