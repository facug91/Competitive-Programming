/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2415
	Name: Find the Wedding Cake Volume
	Number: 2415
	Date: 11/12/2014
*/

#include <cstdio>
#include <cmath>

using namespace std;

int main () {
	int t, n, r, h;
	double a;
	double PI = 2*acos(0);
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		a = 0.0;
		while (n--) {
			scanf("%d %d", &r, &h);
			a += PI*r*r*h;
		}
		printf("%.2lf\n", a);
	}
	
	return 0;
}
