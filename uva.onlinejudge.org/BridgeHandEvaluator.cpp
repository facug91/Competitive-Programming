/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=403
	Name: Bridge Hand Evaluator
	Number: 462
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

char s[2], card[] = {'K', 'Q', 'J'}, suit[] = {'S', 'H', 'D', 'C'};
bool stopped[4];
int points, aux, bid, idx;
int data[4][5]; //data[i][] 'S' = 0 ; 'H' = 1 ; 'D' = 2 ; 'C' = 3
				//data[][j] ace = 0 ; king = 1 ; queen = 2 ; jack = 3 ; total = 4;

void process_type (int i) {
	switch (s[0]) {
		case 'A':
			data[i][0]++;
			break;
		case 'K':
			data[i][1]++;
			break;
		case 'Q':
			data[i][2]++;
			break;
		case 'J':
			data[i][3]++;
			break;
	}
}

void process_card () {
	switch (s[1]) {
		case 'S': 
			data[0][4]++;
			process_type(0);
			break;
		case 'H': 
			data[1][4]++;
			process_type(1);
			break;
		case 'D': 
			data[2][4]++;
			process_type(2);
			break;
		case 'C': 
			data[3][4]++;
			process_type(3);
			break;
	}
}

int main() {
	
	while (scanf("%s", s) != EOF) {
		
		for (int i=0; i<4; i++)
			for (int j=0; j<5; j++)
				data[i][j] = 0;
		
		process_card();
		for (int i=0; i<12; i++) {
			scanf("%s", s);
			process_card();
		}
		
		aux = 4; points = 0; 
		stopped[0] = stopped[1] = stopped[2] = stopped[3] = false;
		for (int i=0; i<4; i++)  {// ace, king, queen, jack
			for (int j=0; j<4; j++) { //'S', 'H', 'D', 'C'
				points += (data[j][i]*aux);
				if ((i) && (data[j][i]) && (data[j][4] <= 4-aux)) points--;
				if (i != 3) {
					if (i == 0) {
						if (data[j][i]) stopped[j] = true;	
					} else if ((data[j][i]) && (data[j][4] >= 5-aux)) stopped[j] = true;
				}
			}
			aux--;
		}
		
		if ((stopped[0]) && (stopped[1]) && (stopped[2]) && (stopped[3]) && (points >= 16)) {
			printf("BID NO-TRUMP\n");
		} else {
			for (int i=0; i<4; i++) {
				if (data[i][4] == 2) points++;
				else if ((data[i][4] == 0) || (data[i][4] == 1)) points += 2;
			}
			if (points < 14) printf("PASS\n");
			else {
				bid = max(data[0][4], max(data[1][4], max(data[2][4], data[3][4])));
				for (idx=0; data[idx][4]!=bid; idx++);
				printf("BID %c\n", suit[idx]);
			}
		}
		
	}
	
	return 0;
} 
