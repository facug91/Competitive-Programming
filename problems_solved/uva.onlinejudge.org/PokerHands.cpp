/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1256
	Name: Poker Hands
	Number: 10315
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

int card['Z'];

struct cmp {
	bool operator() (char * a, char * b) {
		if (a[0] == b[0]) return (a[1] < b[1]);
		else return (card[a[0]] < card[b[0]]);
	}
} myCmp;

vector<char*> hand[2];
int value[2];
bool dif['Z'];

void init () {
	card['2'] = 0;
	card['3'] = 1;
	card['4'] = 2;
	card['5'] = 3;
	card['6'] = 4;
	card['7'] = 5;
	card['8'] = 6;
	card['9'] = 7;
	card['T'] = 8;
	card['J'] = 9;
	card['Q'] = 10;
	card['K'] = 11;
	card['A'] = 12;	
}

int calculate_value (int h) {
	
	/*
		0: HIGH CARD
		1: PAIR
		2: TWO PAIRS
		3: THREE OF A KIND
		4: STRAIGHT
		5: FLUSH
		6: FULL HOUSE
		7: FOUR OF A KIND
		8: STRAIGHT FLUSH
	*/

	sort(hand[h].begin(), hand[h].end(), myCmp);
	
	if ((hand[h][0][1] == hand[h][1][1]) && (hand[h][1][1] == hand[h][2][1]) 
		&& (hand[h][2][1] == hand[h][3][1]) && (hand[h][3][1] == hand[h][4][1])) { //es escalera real o color
		int aux = card[hand[h][0][0]];
		for (int i=1; i<5; i++) {
			if (card[hand[h][i][0]]-1 == aux) aux = card[hand[h][i][0]];
			else return 5;
		}
		return 8;
	} else { 
		for (int i='0'; i<='9'; i++) dif[i] = false;
		dif['A'] = false; dif['J'] = false; dif['Q'] = false; dif['K'] = false; dif['T'] = false;
		int cont = 0;
		for (int i=0; i<5; i++) { //cuanta los distintos valores de las cartas
			if (!dif[hand[h][i][0]]) {
				dif[hand[h][i][0]] = true;
				cont++;
			}
		} 
		if (cont == 2) { //es full o poker
			if ((hand[h][0][0] == hand[h][3][0]) || (hand[h][1][0] == hand[h][4][0])) {
				return 7;
			} else {
				return 6;
			}
		} else if (cont == 3) { //es pierna o doble par
			if ((hand[h][0][0] == hand[h][2][0]) || (hand[h][1][0] == hand[h][3][0]) || (hand[h][2][0] == hand[h][4][0])) {
				return 3;
			} else {
				return 2;
			}
		} else if (cont == 4) { //par
			return 1;
		} else { //cont = 5 , escalera común o carta alta
			int aux = card[hand[h][0][0]];
			for (int i=1; i<5; i++) {
				if (card[hand[h][i][0]]-1 == aux) aux = card[hand[h][i][0]];
				else return 0;
			}
			return 4;
		}
	}
}

void tiebreaker () {
	
	/*
		0: HIGH CARD
		1: PAIR
		2: TWO PAIRS
		3: THREE OF A KIND
		4: STRAIGHT
		5: FLUSH
		6: FULL HOUSE
		7: FOUR OF A KIND
		8: STRAIGHT FLUSH
	*/
	
	switch (value[0]) {
		
		case 0:
			for (int i=4; i>=0; i--) {
				if (card[hand[0][i][0]] != card[hand[1][i][0]]) {
					value[0] = card[hand[0][i][0]];
					value[1] = card[hand[1][i][0]];
					return;
				}
			}
			value[0] = 0;
			value[1] = 0;
			return;
			
		case 1:
			value[0] = card[hand[0][0][0]];
			for (int i=1; i<5; i++) {
				if (card[hand[0][i][0]] == value[0]) break;
				else value[0] = card[hand[0][i][0]];
			}
			value[1] = card[hand[1][0][0]];
			for (int i=1; i<5; i++) {
				if (card[hand[1][i][0]] == value[1]) break;
				else value[1] = card[hand[1][i][0]];
			}
			if (value[1] == value[0]) {
				for (int i=4, j=4; i>=0 && j>=0;) {
					if (card[hand[0][i][0]] == value[0]) i--;
					else if (card[hand[1][j][0]] == value[1]) j--;
					else if (card[hand[0][i][0]] == card[hand[1][j][0]]) {
						i--; j--;
					} else {
						value[0] = card[hand[0][i][0]];
						value[1] = card[hand[1][j][0]];
						return;
					}
				}
				value[0] = 0;
				value[1] = 0;
				return;
			} else return;
			
		case 2:
			int aux[2], i;
			
			aux[0] = card[hand[0][1][0]];
			value[0] = card[hand[0][3][0]];
			
			aux[1] = card[hand[1][1][0]];
			value[1] = card[hand[1][3][0]];
			
			if (value[0] != value[1]) return;
			else if (aux[0] != aux[1]) {
				value[0] = aux[0];
				value[1] = aux[1];
				return;
			} else {
				for (int i=0; i<5; i+=2) {
					if ((card[hand[0][i][0]] != aux[0]) && (card[hand[0][i][0]] != value[0])) {
						value[0] = card[hand[0][i][0]];
						break;
					}
				}
				for (int i=0; i<5; i+=2) {
					if ((card[hand[1][i][0]] != aux[1]) && (card[hand[1][i][0]] != value[1])) {
						value[1] = card[hand[1][i][0]];
						break;
					}
				}
				return;
			}
		
		case 3:
			value[0] = card[hand[0][2][0]];
			value[1] = card[hand[1][2][0]];
			
		case 4:
			value[0] = card[hand[0][4][0]];
			value[1] = card[hand[1][4][0]];
			return;
		
		case 5:
			for (int i=4; i>=0; i--) {
				if (card[hand[0][i][0]] != card[hand[1][i][0]]) {
					value[0] = card[hand[0][i][0]];
					value[1] = card[hand[1][i][0]];
					return;
				}
			}
			value[0] = 0;
			value[1] = 0;
			return;
		
		case 6:
			value[0] = card[hand[0][2][0]];
			value[1] = card[hand[1][2][0]];
			return;
		
		case 7:
			value[0] = card[hand[0][2][0]];
			value[1] = card[hand[1][2][0]];
			return;
		
		case 8:
			value[0] = card[hand[0][4][0]];
			value[1] = card[hand[1][4][0]];
			return;
		
	}
	
}

int main() {
	
	init();
	
	char s[50];
	
	while (gets(s)) {
		
		char * p;
		char * d;
		p = strtok(s, " ");
		for (int i=0; i<5; i++) {
			d = new char[3];
			strcpy(d, p);
			hand[0].push_back(d);
			p = strtok(NULL, " ");
		}
		for (int i=0; i<5; i++) {
			d = new char[3];
			strcpy(d, p);
			hand[1].push_back(d);
			p = strtok(NULL, " ");
		} 
		
		value[0] = calculate_value(0);
		value[1] = calculate_value(1);
		
		if (value[0] == value[1]) tiebreaker();
		
		if (value[0] > value[1]) printf("Black wins.\n");
		else if (value[0] < value[1]) printf("White wins.\n");
		else printf("Tie.\n");
		
		hand[0].clear();
		hand[1].clear();
		
	}
	
	return 0;
} 
