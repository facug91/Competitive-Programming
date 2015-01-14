/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=401
        Name: Overlapping Rectangles
        Date: 12/11/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct point {
	int x, y;
	point () {x = y = 0;}
	point (int _x, int _y) : x(_x), y(_y) {};
};

point p1, p2, p3, p4, p5, p6;

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>p1.x>>p1.y>>p2.x>>p2.y;
		cin>>p3.x>>p3.y>>p4.x>>p4.y;
		p5.x = max(p1.x, p3.x);
		p5.y = max(p1.y, p3.y);
		p6.x = min(p2.x, p4.x);
		p6.y = min(p2.y, p4.y);
		if (p5.x >= p6.x || p5.y >= p6.y) cout<<"No Overlap"<<endl;
		else cout<<p5.x<<" "<<p5.y<<" "<<p6.x<<" "<<p6.y<<endl;
		if (TC) cout<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
}
