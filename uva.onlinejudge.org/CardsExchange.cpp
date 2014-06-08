/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2725
	Name: Cards' Exchange
	Number: 11678
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

int a, b, c, ans_a, ans_b;
vector<int> alice_cards, betty_cards;

int main() {
	
	while (scanf("%d %d", &a, &b), a || b) {
		
		scanf("%d", &c);
		alice_cards.push_back(c);
		for (int i=1; i<a; i++) {
			scanf("%d", &c);
			if (c != alice_cards.back()) alice_cards.push_back(c);
		}
		
		scanf("%d", &c);
		betty_cards.push_back(c);
		for (int i=1; i<b; i++) {
			scanf("%d", &c);
			if (c != betty_cards.back()) betty_cards.push_back(c);
		}
		
		ans_a = ans_b = 0;
		while (!alice_cards.empty() && !betty_cards.empty()) {
			if (alice_cards.back() == betty_cards.back()) {
				alice_cards.pop_back();
				betty_cards.pop_back();
			} else if (alice_cards.back() < betty_cards.back()) {
				betty_cards.pop_back();
				ans_b++;
			} else {
				alice_cards.pop_back();
				ans_a++;
			}
		}
		
		while (!alice_cards.empty()) {
			alice_cards.pop_back();
			ans_a++;
		}
		
		while (!betty_cards.empty()) {
			betty_cards.pop_back();
			ans_b++;
		}
		
		printf("%d\n", min(ans_a, ans_b));
		
		
	}
	
	return 0;
} 
