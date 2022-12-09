/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2813
        Name: Hyperactive Girl
        Date: 19/10/2015
*/
 
#include <bits/stdc++.h>
#define y1		nd03dnqwuidg1odbnw9uddu0132d
#define clock	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define move	df53y5fgsf43fdsfsdtg4j6hfdg4
#define count	nkwdfj111afbjdfsbj32r8yfwejb
#define prev	asdnklgbgbjfasdbhksdva4t9jds
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
#define MOD 100000000
//#define MAXN 10005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

int m, n, S[105], F[105], DP[105][105];
vi adj[105];

int dp (int u, int p) {
	if (F[u] == m) return 1;
	if (DP[u][p] != -1) return DP[u][p];
	int ans = 0;
	for (auto v : adj[u]) if (u == 0 || F[p] < S[v]) ans = (ans + dp(v, u)) % MOD;
	return DP[u][p] = ans;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	while (cin>>m>>n, m || n) {
		for (i=1; i<=n; i++) cin>>S[i]>>F[i];
		for (i=0; i<=n; i++) adj[i].clear();
		S[0] = F[0] = -1;
		for (i=1; i<=n; i++) {
			if (S[i] == 0) adj[0].push_back(i);
			for (j=1; j<=n; j++) if (S[i] < S[j] && F[i] < F[j] && F[i] >= S[j]) adj[i].push_back(j);
		}
		memset(DP, -1, sizeof DP);
		cout<<dp(0, 0)<<endl;
	}
	
	return 0;
}
