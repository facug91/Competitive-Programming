/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1146
	Name: Stack 'em Up
	Number: 10205
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

int t, n = 0, i, j, k, len, deck[53], aux[53], moves[105][53];
char ks[10], cards[][20] = {" ","2 of Clubs","3 of Clubs","4 of Clubs","5 of Clubs","6 of Clubs","7 of Clubs","8 of Clubs","9 of Clubs","10 of Clubs","Jack of Clubs","Queen of Clubs","King of Clubs","Ace of Clubs","2 of Diamonds","3 of Diamonds","4 of Diamonds","5 of Diamonds","6 of Diamonds","7 of Diamonds","8 of Diamonds","9 of Diamonds","10 of Diamonds","Jack of Diamonds","Queen of Diamonds","King of Diamonds","Ace of Diamonds","2 of Hearts","3 of Hearts","4 of Hearts","5 of Hearts","6 of Hearts","7 of Hearts","8 of Hearts","9 of Hearts","10 of Hearts","Jack of Hearts","Queen of Hearts","King of Hearts","Ace of Hearts","2 of Spades","3 of Spades","4 of Spades","5 of Spades","6 of Spades","7 of Spades","8 of Spades","9 of Spades","10 of Spades","Jack of Spades","Queen of Spades","King of Spades","Ace of Spades"};

int to_int () {
	int aux = 0;
	for (int i=0; ks[i]; i++) {
		aux = aux*10+(ks[i]-'0');
	}
	return aux;
}

int main() {
	
	scanf("%d", &t);
	
	for (int it=0; it<t; it++) {
		
		if (it) printf("\n");
		
		scanf("%d", &n);
		
		for (k=1; k<=n; k++) {
			for (j=1; j<=52; j++) {
				scanf("%d", &i);
				moves[k][j] = i;
			}
		}
		getchar();
		
		for (i=1; i<=52; i++) deck[i] = i;
		
		while (gets(ks) && (strlen(ks))) {
			
			k = atoi (ks);
			
			for (i=1; i<=52; i++)
				aux[i] = deck[moves[k][i]];
			for (i=1; i<=52; i++)
				deck[i] = aux[i];
			
		}
		
		for (i=1; i<=52; i++) 
			printf("%s\n", cards[deck[i]]);
		
		
	}
	
	return 0;
} 
