/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2048
	Name: Counting Islands
	Number: 2048
	Date: 28/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <utility>
#include <iterator>
#include <vector>

#define MAX_INT 2147483647

using namespace std;

string isla[101];
bool visitado[101][101];
queue<pair<int, int> > cola;
int dist1[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dist2[] = {1, -1, 0, 1, -1, 0, 1, -1};

int bfs (int n, int x, int y) {
	int i, j, c = 1;
	cola.push(make_pair(x, y));
	visitado[x][y] = true;
	
	pair<int, int> act;
	while (!cola.empty()) {
		act = cola.front();
		cola.pop();
		
		for (i=0; i<8; i++) {
			if ((act.first+dist1[i] >= 0) && (act.first+dist1[i] < n) && (act.second+dist2[i] >= 0) && (act.second+dist2[i] < n)) {
				if ((!visitado[act.first+dist1[i]][act.second+dist2[i]]) && (isla[act.first+dist1[i]][act.second+dist2[i]] == 'l')) {
					visitado[act.first+dist1[i]][act.second+dist2[i]] = true;
					cola.push(make_pair(act.first+dist1[i], act.second+dist2[i]));
					c++;
				}
			}
		}
	}
	
	return c;
}

int main () {
	int n, i, j;
	int cont, mx, mn, aux;
	
	cin>>n;
	while (n) {
		for (i=0; i<n; i++) {
			cin>>isla[i];
		}
		
		memset (visitado, false, sizeof(visitado));
		mx = 0;
		mn = MAX_INT;
		cont = 0;
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) {
				if ((!visitado[i][j]) && (isla[i][j] == 'l')) {
					aux = bfs(n, i, j);
					if (aux > mx) mx = aux;
					if (aux < mn) mn = aux;
					cont++;
				}
			}
		}
		
		if (cont == 0) cout<<"0 0 0"<<endl;
		else cout<<cont<<" "<<mn<<" "<<mx<<endl;
		
		cin>>n;
	}
	
	return 0;
}
