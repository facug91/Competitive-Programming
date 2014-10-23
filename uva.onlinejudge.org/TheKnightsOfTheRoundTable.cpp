/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1136
        Name: The Knights Of The Round Table
        Date: 18/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 3000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

double a, b, c;

double perimeter () {
	return a+b+c;
}
double area () {
	double sp = perimeter() / 2.0;
	return sqrt(sp*(sp-a)*(sp-b)*(sp-c));
}
double r_in_circle () {
	return area() / (0.5 * perimeter());
}
bool is_triangle () {
	if (a < b) swap(a, b);
	if (a < c) swap(a, c);
	return a < (b+c);
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
		if (is_triangle()) printf("The radius of the round table is: %.03lf\n", r_in_circle());
		else printf("The radius of the round table is: 0.000\n");
	}
	
	return 0;
}
