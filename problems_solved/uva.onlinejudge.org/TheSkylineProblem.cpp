/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=41
        Name: The Skyline Problem
        Date: 07/03/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
#define MOD 1000000007ll
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, l[5005], h[5005], r[5005], city[10005];
priority_queue<ii> pq;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	memset(city, 0, sizeof city);
	n = 0;
	while (cin>>l[n]>>h[n]>>r[n]) n++;
	pq.push(ii(0, 10005));
	for (i=0, j=0; i<10005; i++) {
		while (pq.top().S <= i) pq.pop();
		while (j < n && l[j] == i) {
			pq.push(ii(h[j], r[j]));
			j++;
		}
		city[i] = pq.top().F;
	}
	bool first = true;
	if (city[0] > 0) {
		first = false;
		cout<<0<<" "<<city[0];
	}
	for (i=1; i<10005; i++) {
		if (city[i] > city[i-1]) {
			if (first) first = false;
			else cout<<" ";
			cout<<i<<" "<<city[i];
		}
		if (city[i] < city[i-1]) {
			cout<<" "<<i<<" "<<city[i];
		}
	}
	cout<<endl;
	
	return 0;
}
