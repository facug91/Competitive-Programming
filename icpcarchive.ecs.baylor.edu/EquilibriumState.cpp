/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5239
	Name: Equilibrium State
	Date: 27/04/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define next sbjkdfh329re9fdshfd98fyh
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 1000000007ll
#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

struct point {
	double x, y;
	point () {x = y = 0.0;}
	point (double x, double y) : x(x), y(y) {}
};

int k, m, n, u, v, curr;
double x, y, w;
point p[2][1500];
vector<pair<int, double> > adj[1500];

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>k>>m>>n;
		for (i=0; i<k; i++) {
			cin>>p[0][i].x>>p[0][i].y;
			p[1][i] = p[0][i];
		}
		for (i=k; i<k+n; i++) p[0][i].x = p[0][i].y = p[1][i].x = p[1][i].y = 0.0;
		for (i=0; i<k+n; i++) adj[i].clear();
		while (m--) {
			cin>>w>>u>>v;
			if (u < 0) u = -u - 1;
			else u = u - 1 + k;
			if (v < 0) v = -v - 1;
			else v = v - 1 + k;
			adj[u].push_back(MP(v, w));
			adj[v].push_back(MP(u, w));
		}
		curr = 0;
		point vec;
		double delta = 0.01;
		for (i=0; i<1000; i++) {
			for (u=k; u<k+n; u++) {
				vec.x = vec.y = 0.0;
				for (pair<int, double> e : adj[u]) {
					v = e.first;
					w = e.second;
					vec.x += (w * (p[curr][v].x - p[curr][u].x));
					vec.y += (w * (p[curr][v].y - p[curr][u].y));
				}
				p[curr^1][u].x = p[curr][u].x + vec.x * delta;
				p[curr^1][u].y = p[curr][u].y + vec.y * delta;
			}
			curr ^= 1;
		}
		curr ^= 1;
		cout<<"Test case number : "<<it<<endl;
		for (i=k; i<k+n; i++) cout<<i-k+1<<" "<<p[curr][i].x<<" "<<p[curr][i].y<<endl;
	}
	
	return 0;
}
