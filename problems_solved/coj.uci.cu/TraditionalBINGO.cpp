/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1014
	Name: Traditional BINGO
	Number: 1014
	Date: 21/11/2013
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

int n, i, j, aux, anunciados, resultado;
set<int> columnas[5];
set<int> filas[5];
set<int> diagonales[2];

int main () {
	
	cin>>n;
	
	for (;n--;) {
		
		//lee y carga los sets de filas, columnas y diagonales
		for(j=0; j<2; j++) {
			for (i=0; i<5; i++) {
				cin>>aux;
				columnas[i].insert(aux);
				filas[j].insert(aux);
				if (i == j) {
					diagonales[0].insert(aux);
				} else if (i+j == 4) {
					diagonales[1].insert(aux);
				}
			}
		}
		for (i=0; i<5; i++) {
			if (i != 2) {
				cin>>aux;
				columnas[i].insert(aux);
				filas[2].insert(aux);
			}
		}
		for(j=3; j<5; j++) {
			for (i=0; i<5; i++) {
				cin>>aux;
				columnas[i].insert(aux);
				filas[j].insert(aux);
				if (i == j) {
					diagonales[0].insert(aux);
				} else if (i+j == 4) {
					diagonales[1].insert(aux);
				}
			}
		}
		
		//va eliminando los números que salen de los sets, y preguntando si se vaciaron
		anunciados = 1;
		resultado = 0;
		while (!resultado) {
			cin>>aux;
			for (i=0; i<2; i++) {
				columnas[i].erase(aux);
				if (columnas[i].empty()) {
					resultado = anunciados;
				} else {
					filas[i].erase(aux);
					if (filas[i].empty()) {
						resultado = anunciados;
					} else {
						diagonales[i].erase(aux);
						if (diagonales[i].empty()) {
							resultado = anunciados;
						}
					}
				}
			}
			for (i=2; i<5; i++) {
				columnas[i].erase(aux);
				if (columnas[i].empty()) {
					resultado = anunciados;
				} else {
					filas[i].erase(aux);
					if (filas[i].empty()) {
						resultado = anunciados;
					}
				}
			}
			anunciados++;
		}
		
		//termina de leer los números que hayan quedado
		for (i=anunciados; i<=75; i++) {
			cin>>aux;
		}
		
		//vacía los sets
		for (i=0; i<5; i++) {
			columnas[i].clear();
			filas[i].clear();
		}
		diagonales[0].clear();
		diagonales[1].clear();
		
		
		printf("BINGO after %d numbers announced\n",resultado);
	}
	return 0;
}
