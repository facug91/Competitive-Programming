/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2515
	Name: Melman Cars
	Number: 2515
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iterator>
#include <utility>
#include <list>

#define tint unsigned long long int
#define MAX_INT 2147483647

using namespace std;

struct cmp {
	bool operator () (const pair<int, int> &a, const pair<int, int> &b) {
		return (a.second > b.second);
	}
};
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> cola;

string ciudad[101];
int dist[101][101];
int distPrim[101];
bool visitado[101];
int distLCS[52][52];
int n;
string s;

int lcs (const string &s1, const string &s2) {
	int i, j;
	
	for (i=0; i<=s1.length(); i++) distLCS[i][0] = 0;
	
	for (j=0; j<=s2.length(); j++) distLCS[0][j] = 0;
	
	for (i=1; i<=s1.length(); i++) {
		for (j=1; j<=s2.length(); j++) {
			if (s1[i-1] == s2[j-1]) {
				distLCS[i][j] = distLCS[i-1][j-1] + 1;
			} else {
				distLCS[i][j] = max(distLCS[i-1][j], distLCS[i][j-1]);
			}
		}
	}
	return distLCS[s1.length()][s2.length()];
}

void calcularPesoAristas() {
	int i, j;
	
	for (i=0; i<n; i++) dist[i][i] = 0;
	
	for (i=0; i<n; i++) {
	
		for (j=i+1; j<n; j++) {
			dist[i][j] = lcs(ciudad[i], ciudad[j]) + 1;
			dist[j][i] = dist[i][j];
		}
	}
}

void prim () {
	int i, j;
	
	for (i=0; i<n; i++) {
		distPrim[i] = MAX_INT;
		visitado[i] = false;
	}
	
	cola.push(make_pair(0,0));
	distPrim[0] = 0;
	
	pair<int, int> act;
	while (!cola.empty()) {
		act = cola.top();
		cola.pop();
		
		if (!visitado[act.first]) {
			visitado[act.first] = true;
			
			for (i=0; i<n; i++) {
				if (!visitado[i]) {
					if (distPrim[i] > dist[act.first][i]) {
						distPrim[i] = dist[act.first][i];
						cola.push(make_pair(i, distPrim[i]));
					}
				}
			}
		}
	}
}

int getMax () {
	int mx = 0, i;
	for (i=0; i<n; i++) {
		if (distPrim[i] > mx) mx = distPrim[i];
	}
	return mx;
}

int main () {
	int i, j;
	
	cin>>n;
	for (i=0; i<n; i++) cin>>ciudad[i];
	
	calcularPesoAristas();
	
	prim();
	
	cout<<getMax()<<endl;
	
	return 0;
}
