/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2554
	Name: Watching the Game
	Number: 2554
	Date: 18/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <iterator>

using namespace std;

set<int> equipo[1000001];
set<int>::iterator itr;
int casa[1000001];
int n, f, a, b, c, m, i, e, j;

void init () {
	casa[1] = a;
	equipo[casa[1]].insert(1);
	for (j=2; j<=n; j++) {
		casa[j] = ((b*casa[j-1])+c)%f;
		equipo[casa[j]].insert(j);
	}
}

int main () {
	
	cin>>n>>f;
	cin>>a>>b>>c;
	cin>>m;
	
	init();
	
	while (m--) {
		cin>>i>>e;
		equipo[casa[i]].erase(i);
		equipo[e].insert(i);
		casa[i] = e;
		
		if (equipo[e].size() == 1) {
			printf("%d %d\n", n, n);
		} else {
			
			//counterclockwise order
			itr = equipo[e].find(i);
			if (itr != equipo[e].begin()) {
				printf("%d ", i - *(--itr));
			} else {
				printf("%d ", n - *(--(equipo[e].end())) + i);
			}
			
			//clockwise order
			itr = equipo[e].upper_bound(i);
			if (itr == equipo[e].end()) {
				printf("%d\n", n - i + *(equipo[e].begin()));
			} else {
				printf("%d\n", *itr - i);
			}
		}
	}
	
	return 0;
}
