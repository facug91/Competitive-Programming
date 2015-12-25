/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5222
        Name: Height map
        Date: 16/11/2015
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
//#define MOD 1000000007ll
//#define MAXN 10005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

int n, m, mat[105][105], ans, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool vis[105][105];

void dfs (int i, int j) {
	vis[i][j] = true;
	for (int d=0; d<4; d++) {
		int x = i + dx[d];
		int y = j + dy[d];
		if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && mat[x][y] == mat[i][j]) dfs(x, y);
	}
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k, l;
	
	while (cin>>n>>m) {
		for (i=0; i<n; i++) for (j=0; j<m; j++) cin>>mat[i][j];
		ans = 5;
		for (i=0; i<n; i++) for (j=0; j<m; j++) {
			if (i+1 < n && mat[i][j] != mat[i+1][j]) ans++;
			if (j+1 < m && mat[i][j] != mat[i][j+1]) ans++;
		}
		for (i=0; i<n-1; i++) for (j=0; j<m-1; j++) {
			if (mat[i][j] < mat[i+1][j] && mat[i][j+1] < mat[i+1][j+1] && max(mat[i][j], mat[i][j+1]) < min(mat[i+1][j], mat[i+1][j+1])) ans--;
			if (mat[i][j] > mat[i+1][j] && mat[i][j+1] > mat[i+1][j+1] && min(mat[i][j], mat[i][j+1]) > max(mat[i+1][j], mat[i+1][j+1])) ans--;
			if (mat[i][j] < mat[i][j+1] && mat[i+1][j] < mat[i+1][j+1] && max(mat[i][j], mat[i+1][j]) < min(mat[i][j+1], mat[i+1][j+1])) ans--;
			if (mat[i][j] > mat[i][j+1] && mat[i+1][j] > mat[i+1][j+1] && min(mat[i][j], mat[i+1][j]) > max(mat[i][j+1], mat[i+1][j+1])) ans--;
		}
		memset(vis, 0, sizeof vis);
		for (i=0; i<n; i++) for (j=0; j<m; j++) if (!vis[i][j]) {
			ans++;
			dfs(i, j);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
