/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=775&problem=1242&mosmsg=Submission+received+with+ID+16831618
        Name: Rings and Glue
        Date: 11/02/2016
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
//#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, p[105], size[105], ans;
double x[105], y[105], r[105];

double dist_point (int i, int j) {
	return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}

int find_set (int i) {
	return (i == p[i]) ? i : (p[i] = find_set(p[i]));
}

void union_set (int i, int j) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		p[x] = y;
		size[y] += size[x];
	}
}

bool inside_circle (int i, int j) {
	return (r[i] > r[j] && dist_point(i, j) + r[j] <= r[i]);
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	while (cin>>n, n != -1) {
		for (i=0; i<n; i++) {
			cin>>x[i]>>y[i]>>r[i];
			p[i] = i;
			size[i] = 1;
		}
		for (i=0; i<n; i++) for (j=i+1; j<n; j++) if (dist_point(i, j) < r[i]+r[j]) {
			if (inside_circle(i, j) || inside_circle(j, i)) continue;
			union_set(i, j);
		}
		ans = 0;
		for (i=0; i<n; i++) if (size[find_set(i)] > ans) ans = size[find_set(i)];
		if (ans != 1) cout<<"The largest component contains "<<ans<<" rings."<<endl;
		else cout<<"The largest component contains "<<ans<<" ring."<<endl;
	}
	
	return 0;
}
