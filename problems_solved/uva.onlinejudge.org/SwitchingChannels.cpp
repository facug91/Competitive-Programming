/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=170
	Name: Switching Channels
	Number: 234
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iterator>
#include <utility>
#include <list>
#include <stack>
#include <iomanip>
#include <bitset>

#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
//const long double PI = 2*acos(0);

#define INF 1000000000
//
using namespace std;

int p, programme[10], a, channel[10], times[10], miss[10], perm[10];
vector<int> alignment[6];

void check (int imp) {
	
	if (imp == 6) return;
	
	if (alignment[imp].size() == 0) {
		check(imp+1);
		return;
	}
	
	int i, j, sum = 0, aux;
	
	for (i=0; i<alignment[imp].size(); i++) {
		
		for (j=0; ((j<p) && (times[j]<alignment[imp][i])); j++);
		
		if (j == 0) aux = min(times[j]-alignment[imp][i], alignment[imp][i]);
		else if (j == p) aux = alignment[imp][i]-times[j-1];
		else aux = min(times[j]-alignment[imp][i], alignment[imp][i]-times[j-1]);
		
		sum += aux;
		
	}
		
	if (sum == miss[imp]) check(imp+1);
	else if (sum < miss[imp]) {
		miss[imp] = sum;
		for (i=0; i<p; i++) 
			channel[i] = programme[perm[i]];
		for (; imp<6; imp++) {
			sum = 0;
			for (i=0; i<alignment[imp].size(); i++) {
				
				for (j=0; ((j<p) && (times[j]<alignment[imp][i])); j++);
				
				if (j == 0) aux = min(times[j]-alignment[imp][i], alignment[imp][i]);
				else if (j == p) aux = alignment[imp][i]-times[j-1];
				else aux = min(times[j]-alignment[imp][i], alignment[imp][i]-times[j-1]);
				
				sum += aux;
				
			}
			miss[imp] = sum;
		}
	}
	
}

int error () {
	
	int sum = 0, i, j, imp, aux;
	
	times[0] = channel[0];
	for (i=1; i<p; i++) 
		times[i] = times[i-1] + channel[i];
	
	for (imp=1; imp<6; imp++) {
		for (i=0; i<alignment[imp].size(); i++) {
			
			for (j=0; ((j<p) && (times[j]<alignment[imp][i])); j++);
			
			if (j == 0) aux = min(times[j]-alignment[imp][i], alignment[imp][i]);
			else if (j == p) aux = alignment[imp][i]-times[j-1];
			else aux = min(times[j]-alignment[imp][i], alignment[imp][i]-times[j-1]);
			
			sum += aux;
			
		}
	}
	
	return sum;
}

int main() {
	
	int t=1, i;
	
	while (scanf("%d", &p), p) {
		
		if (t != 1) {
			for (i=1; i<6; i++)
				alignment[i].clear();
		}
		
		for (i=0; i<p; i++)
			scanf("%d", &programme[i]);
		
		scanf("%d", &a);
		int x, y;
		for (i=0; i<a; i++) {
			scanf("%d %d", &x, &y);
			alignment[x].push_back(y);
		}
		
		for (i=0; i<6; i++) miss[i] = INF;
		for (i=0; i<p; i++) perm[i] = i;
		
		do {
			times[0] = programme[perm[0]];
			for (i=0; i<p; i++) 
				times[i] = times[i-1] + programme[perm[i]];
			check(1);
		} while (next_permutation(perm, perm+p));
		
		printf("Data set %d\n", t++);
		printf("Order: %d", channel[0]);
		for (i=1; i<p; i++)
			printf(" %d", channel[i]);
		printf("\n");
		printf("Error: %d\n", error());
		
	}
	
	return 0;
} 
