/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1331
	Name: Agent J
	Number: 1331
	Date: 05/08/2014
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
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

double r1, r2, r3, l1, l2, l3, a, b, c, alfa, beta, gama, area, segment1, segment2, segment3;

int main () {
	int t, i, j;
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		scanf("%lf %lf %lf", &r1, &r2, &r3);
		l1 = r1+r2; l2 = r1+r3; l3 = r2+r3;
		
		alfa = acos((l3*l3 - l2*l2 - l1*l1) / (-2.0*l2*l1));
		a = sqrt(r1*r1*2.0 - 2.0*r1*r1*cos(alfa));
		
		beta = acos((l1*l1 - l2*l2 - l3*l3) / (-2.0*l2*l3));
		b = sqrt(r3*r3*2.0 - 2.0*r3*r3*cos(beta));
		
		gama = acos((l2*l2 - l1*l1 - l3*l3) / (-2.0*l1*l3));
		c = sqrt(r2*r2*2.0 - 2.0*r2*r2*cos(gama));
		
		segment1 = (PI*r1*r1 * (alfa/(2.0*PI))) - (sqrt(r1*r1-(a*a/4.0))*a/2.0);
		segment2 = (PI*r3*r3 * (beta/(2.0*PI))) - (sqrt(r3*r3-(b*b/4.0))*b/2.0);
		segment3 = (PI*r2*r2 * (gama/(2.0*PI))) - (sqrt(r2*r2-(c*c/4.0))*c/2.0);
		
		double aux = (a+b+c)/2.0;
		area = sqrt((aux-a)*(aux-b)*(aux-c)*aux) - (segment1 + segment2 + segment3);
		
		printf("Case %d: %.10lf\n", it, area);
	}
	
	return 0;
}
