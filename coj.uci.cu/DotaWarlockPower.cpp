/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1480
	Name: Dota Warlock Power
	Number: 1480
	Date: 28/11/2013
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <cmath>
#include <vector>
#define x first
#define y second
#define sqr(x) ((x) * (x))
#define DBL_MAX  1E+37


using namespace std;

struct cmp { 
    bool operator() (const pair<int, double> &a, const pair<int, double> &b) {
        return a.second > b.second;
    }
};

int n, i, j;
double x, y, total;
pair<double, double> peca[100];
double distancia[100][100];
bool visitado[100];
double distmin[100];
priority_queue< pair<int, double>, vector<pair<int, double> >, cmp > cola;
pair<int, double> act;

int main () {
	
	cin>>n;
	
	for (i=0; i<n; i++) {
		cin>>x>>y;
		peca[i] = make_pair(x, y);
		visitado[i] = false;
		distmin[i] = DBL_MAX;
	}
	
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			distancia[i][j] = sqrt(sqr(peca[i].x - peca[j].x) + sqr(peca[i].y - peca[j].y));
		}
	}
	
	distmin[0] = 0.0;
	cola.push(make_pair(0, 0.0));
	
	while (!cola.empty()) {
		act = cola.top();
		cola.pop();
		
		if (!visitado[act.first]) {
			
			visitado[act.first] = true;
			
			for (i=0; i<n; i++) {
				if (!visitado[i]) {
					if (distmin[i] > distancia[act.first][i]) {
						distmin[i] = distancia[act.first][i];
						cola.push(make_pair(i, distancia[act.first][i]));
					}
				}
			}
		}
	}
	
	total = 0.0;
	for (i=0; i<n; i++) {
		total += distmin[i];
	}
	total *= 5.0;
	
	printf("%.2f\n", total);
	
	return 0;
}
