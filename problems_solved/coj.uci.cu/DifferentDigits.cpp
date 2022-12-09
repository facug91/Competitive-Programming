/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2120
	Name: DifferentDigits
	Number: 2120
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

#define tint unsigned long long int
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9;

#define INF 1000000000

using namespace std;

bool numero[10];
int aux;
bool check (const int &num) {
	aux = num;
	memset(numero, false, sizeof(numero));
	while (aux) {
		if (!numero[aux%10]) numero[aux%10] = true;
		else return false;
		aux /= 10;
	}
	return true;
}

int main() {
	
	int n, m, i, res;
	
	while (cin>>n>>m) {
		res = 0;
		for (i=n; i<=m; i++) {
			res += check(i);
		}
		cout<<res<<endl;
	}
	
	return 0;
