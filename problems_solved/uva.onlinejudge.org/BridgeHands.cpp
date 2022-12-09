/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=9
	Name: Bridge Hands
	Number: 555
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

int value0['Z'], value1['Z'];

struct cmp {
	bool operator() (const char * a, const char * b) {
		if (a[0] == b[0]) {
			return (value1[a[1]] < value1[b[1]]);
		} else {
			return (value0[a[0]] < value0[b[0]]);
		}
	}
} mycmp;

char start, deal[30], to_letter[5];
vector<char*> player[4];
int idx, to_pos['Z'], len;

int main() {
	
	to_pos['S'] = 0;
	to_pos['W'] = 1;
	to_pos['N'] = 2;
	to_pos['E'] = 3;
	
	value0['C'] = 0;
	value0['D'] = 1;
	value0['S'] = 2;
	value0['H'] = 3;
	
	value1['2'] = 0;
	value1['3'] = 1;
	value1['4'] = 2;
	value1['5'] = 3;
	value1['6'] = 4;
	value1['7'] = 5;
	value1['8'] = 6;
	value1['9'] = 7;
	value1['T'] = 8;
	value1['J'] = 9;
	value1['Q'] = 10;
	value1['K'] = 11;
	value1['A'] = 12;
	
	while (scanf("%c", &start), start != '#') {
		getchar();
		
		idx = (to_pos[start] + 1) % 4;
		for (int i=0; i<2; i++) {
			
			gets(deal);
			
			len = strlen(deal);
			for (int j=0; j<len; j+=2) {
				char * to = new char[3];
				strncpy (to, deal+j, 2);
				to[2] = '\0';
				//cout<<to<<endl;
				player[idx].push_back(to);
				idx = (idx + 1) % 4;
			}
		}
		
		for (int j=0; j<4; j++) {
			
			sort(player[j].begin(), player[j].end(), mycmp);
			
			//ni idea por qué esto ¿?
			to_letter[0] = 'S';
			to_letter[1] = 'W';
			to_letter[2] = 'N';
			to_letter[3] = 'E';
			//pero sino, no funciona
			
			printf("%c:", to_letter[j]);
			for (int k=0; k<13; k++)
				printf(" %s", player[j][k]);
			printf("\n");
			
		}
		
		for (int i=0; i<4; i++)
			player[i].clear();
		
	}
	
	return 0;
} 
