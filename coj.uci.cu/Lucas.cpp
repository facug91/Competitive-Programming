/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1649
	Name: Lucas
	Number: 1649
	Date: 31/10/2013
*/

#include <iostream>
#include <cstdio>
#include <utility>
#include <set>
#include <queue>
#include <iterator>
#include <cstring>
#include <string.h>


using namespace std;

//Accepted

int main () {
	int n, i;
	
	scanf("%d",&n);;
	
	pair<int,int> columnas[n+1];
	
	int f1[n+1];
	
	pair<int,int> fila;
	
	set<int> faltantes2;
	set<int> faltantes3;
	i = 1;
	while (i <= n) {
		faltantes2.insert(i);
		faltantes3.insert(i);
		i++;
	}
	
	int cantFila2[n+1];
	int cantFila3[n+1];
	memset (cantFila2, 0, sizeof(cantFila2));
	memset (cantFila3, 0, sizeof(cantFila3));
	
	i = 1;
	while (i <= n) {
		scanf("%d",&f1[i]);
		i++;
	}
	
	i = 1;
	while (i <= n) {
		scanf("%d",&columnas[f1[i]].first);
		cantFila2[columnas[f1[i]].first]++;
		faltantes2.erase(columnas[f1[i]].first);
		i++;
	}
	
	i = 1;
	while (i <= n) {
		scanf("%d",&columnas[f1[i]].second);
		cantFila3[columnas[f1[i]].second]++;
		faltantes3.erase(columnas[f1[i]].second);
		i++;
	}
	
	queue<int> cola;
	
	bool retirados[n+1];
	memset (retirados,false,n+1);
	
	set<int>::iterator itr;
	
	for (itr=faltantes2.begin(); itr != faltantes2.end(); itr++) {
		cola.push(*itr);
	}
	for (itr=faltantes3.begin(); itr != faltantes3.end(); itr++) {
		cola.push(*itr);
	}
	
	int aux, total = 0;
	while (!cola.empty()) {
		aux = cola.front();
		cola.pop();
		
		if (!retirados[aux]) {
			retirados[aux] = true;
			
			total++;
			
			if (cantFila2[columnas[aux].first] == 1) {
				cola.push(columnas[aux].first);
			} else {
				cantFila2[columnas[aux].first]--;
			}
			
			if (cantFila3[columnas[aux].second] == 1) {
				cola.push(columnas[aux].second);
			} else {
				cantFila3[columnas[aux].second]--;
			}
		}
	}
	
	printf ("%d\n",total);
	
	return 0;
}
