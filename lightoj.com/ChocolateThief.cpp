/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1249
	Name: Chocolate Thief
	Number: 1249
	Date: 26/07/2014
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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

struct cmp {
	bool operator() (const pair<int, string> &a, const pair<int, string> &b) {
		return (a.first < b.first);
	}
};

int n, l, w, h;
set<pair<int, string>, cmp> volumes;
string s;

int main () {
	int t, i, j;
	
	cin>>t;
	for (int it=1; it<=t; it++) {
		volumes.clear();
		cin>>n;
		for (i=0; i<n; i++) {
			cin>>s>>l>>w>>h;
			volumes.insert(make_pair(l*w*h, s));
		}
		if (volumes.size() == 1) cout<<"Case "<<it<<": no thief\n";
		else cout<<"Case "<<it<<": "<<(*(--(volumes.end()))).second<<" took chocolate from "<<(*(volumes.begin())).second<<"\n";	
	}
	
	return 0;
}
