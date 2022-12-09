/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=206
        Name: Lining Up
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
#define MOD 1000000007
//#define MAXN 3000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct point {
	int x, y;
	point () {x = y = 0;}
	point(int _x, int _y) : x(_x), y(_y) {};
};

int x, y;
vector<point> points;
map<double, int> slopes;
map<double, int>::iterator itr;
pair<map<double, int>::iterator, bool> ret;
char line[50];

int solve () {
	int i, j, k, ans = 2, aux;
	double m0, m1;
	for (i=0; i<(int)points.size(); i++) {
		if (ans > (int)points.size()-i) break;
		slopes.clear();
		for (j=i+1; j<(int)points.size(); j++) {
			ret = slopes.insert(make_pair((points[i].x == points[j].x) ? 1.0 : ((double)(points[i].y-points[j].y)/(double)(points[i].x-points[j].x)), 2));
			if (!ret.second) {
				(*ret.first).second++;
			}
		}
		for (itr=slopes.begin(); itr!=slopes.end(); itr++) {
			if (ans < (*itr).second) ans = (*itr).second;
		}
	}
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	getchar();
	gets(line);
	while (TC--) {
		points.clear();
		while (gets(line)) {
			if (line[0] == 0) break;
			x = atoi(strtok(line, " "));
			y = atoi(strtok(NULL, " "));
			points.push_back(point(x, y));
		}
		cout<<solve()<<endl;
		if (TC) cout<<endl;
	}
	
	return 0;
}
