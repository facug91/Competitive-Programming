/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=276
	Name: Master-Mind Hints
	Number: 340
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

int n, c, original[10], copi[10], guess[10], strong, weak, i, j, t; 
vector<int> secret_code, guess_code;

int main() {
	
	t = 1;
	
	while (scanf("%d", &n), n) {
		
		printf("Game %d:\n", t);
		
		if (t != 1) {
			secret_code.clear();
			guess_code.clear();
		}
		
		memset(original, 0, sizeof original);
		for (i=0; i<n; i++) {
			scanf("%d", &c);
			secret_code.push_back(c);
			original[c]++;
		}
		
		memset(guess, 0, sizeof guess);
		for (i=0; i<n; i++) {
			scanf("%d", &c);
			guess_code.push_back(c);
			guess[c]++;
		}
		
		while (guess_code.back() != 0) {
			
			for (i=1; i<10; i++)
				copi[i] = original[i];
			
			strong = 0;
			for (i=0; i<n; i++) {
				if (secret_code[i] == guess_code[i]) {
					copi[secret_code[i]]--;
					guess[guess_code[i]]--;
					strong++;
				}
			}
			
			weak = 0;
			for (i=1; i<10; i++) {
				weak += (min(copi[i], guess[i]));
			}
			
			printf("    (%d,%d)\n", strong, weak);
			
			memset(guess, 0, sizeof guess);
			guess_code.clear();
			for (i=0; i<n; i++) {
				scanf("%d", &c);
				guess_code.push_back(c);
				guess[c]++;
			}
		}
		
		t++;
		
	}
	
	return 0;
} 
