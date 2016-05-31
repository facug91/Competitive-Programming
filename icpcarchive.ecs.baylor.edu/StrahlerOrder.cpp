/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=617&page=show_problem&problem=4478
	Name: Strahler Order
	Date: 23/05/2016
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
#define MOD 100000007
//#define MAXN 30015

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int dt;
int n, m, u, v, in[1005], ord[1005], nf[1005];
vi adj[1005];
queue<int> q;

int topo_sort () {
    int i, j;
    memset(ord, -1, sizeof ord);
    memset(nf, 0, sizeof nf);
    for (i=0; i<n; i++) if (in[i] == 0) {
        q.push(i);
        ord[i] = 1;
        nf[i] = 1;
    }
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            in[v]--;
            if (ord[v] < ord[u]) {
                ord[v] = ord[u];
                nf[v] = 1;
            } else if (ord[v] == ord[u]) {
                nf[v]++;
            }
            if (in[v] == 0) {
                q.push(v);
                if (nf[v] > 1) ord[v]++;
            }
        }
    }
    int ans = 0;
    for (i=0; i<n; i++) ans = max(ans, ord[i]);
    return ans;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j, k;
	
	cin>>tc;
    while (tc--) {
        cin>>dt>>n>>m;
        memset(in, 0, sizeof in);
        for (i=0; i<n; i++) adj[i].clear();
        for (i=0; i<m; i++) {
            cin>>u>>v; u--; v--;
            adj[u].push_back(v);
            in[v]++;
        }
        cout<<dt<<" "<<topo_sort()<<endl;
    }
	
	return 0;
}
