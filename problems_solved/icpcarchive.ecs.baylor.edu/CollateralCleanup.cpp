/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3903
	Name: Collateral Cleanup
	Date: 30/04/2016
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

int n, in[1000005], p[][6] = {{0, 1, 2}, {1, 2, 0}, {2, 0, 1}, {1, 0, 2}, {2, 1, 0}, {0, 2, 1}};
map<iiii, int> to_vertex;
vi adj[1000005];
ii t[1000005][3];

ii to_vec (ii a, ii b) {
	return ii(b.F-a.F, b.S-a.S);
}

ll cross (ii a, ii b) {
	return (ll)a.F*(ll)b.S - (ll)a.S*(ll)b.F;
}

bool ccw (ii p, ii q, ii r) {
	return cross(to_vec(p, q), to_vec(p, r)) < 0ll;
}

void topological_sort () {
	bool first = true;
	queue<int> q;
	for (int i=0; i<n; i++) if (in[i] == 0) q.push(i);
	while (q.size()) {
		int u = q.front(); q.pop();
		if (first) first = false;
		else cout<<" ";
		cout<<u+1;
		for (int v : adj[u]) {
			in[v]--;
			if (in[v] == 0) q.push(v);
		}
	}
	cout<<endl;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		to_vertex.clear();
		for (i=0; i<n; i++) {
			adj[i].clear();
			in[i] = 0;
		}
		for (i=0; i<n; i++) {
			for (j=0; j<3; j++) cin>>t[i][j].F>>t[i][j].S;
			for (j=0; j<6; j++) {
				//cerr<<"i "<<i<<" j "<<j<<" ("<<t[i][p[j][0]].F<<", "<<t[i][p[j][0]].S<<") -> "<<t[i][p[j][1]].F<<", "<<t[i][p[j][1]].S<<endl;
				if (t[i][p[j][0]].F == t[i][p[j][1]].F) continue;
				if (to_vertex.find(MP(t[i][p[j][0]], t[i][p[j][1]])) != to_vertex.end()) {
					int v = to_vertex[MP(t[i][p[j][0]], t[i][p[j][1]])];
					if (ccw(t[i][p[j][0]], t[i][p[j][1]], ii((t[i][p[j][0]].F+t[i][p[j][1]].F)/2, -1)) == 
						ccw(t[i][p[j][0]], t[i][p[j][1]], t[i][p[j][2]])) {
						// Below
						//cerr<<"i "<<i<<" v "<<v<<endl;
						adj[i].push_back(v);
						in[v]++;
					} else { //Above
						//cerr<<" v "<<v<<"i "<<i<<endl;
						adj[to_vertex[MP(t[i][p[j][0]], t[i][p[j][1]])]].push_back(i);
						in[i]++;
					}
				} else to_vertex[MP(t[i][p[j][0]], t[i][p[j][1]])] = i;
			}
		}
		topological_sort();
	}
	
	return 0;
}
