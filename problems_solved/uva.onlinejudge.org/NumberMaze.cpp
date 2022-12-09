/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=870
        Name: Number Maze
        Date: 18/10/2015
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
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1100000000000000ll
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

int n, m, mat[1005][1005], dis[1005][1005], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool vis[1005][1005];
priority_queue<iii, viii, greater<iii> > pq;

int dijkstra () {
	int i, j, a, b, c, d;
	for (i=0; i<n; i++) for (j=0; j<m; j++) {
		vis[i][j] = false;
		dis[i][j] = INF;
	}
	dis[0][0] = mat[0][0];
	pq.push(MP(0, MP(0, 0)));
	iii act;
	while (pq.size()) {
		act = pq.top(); pq.pop();
		a = act.second.first;
		b = act.second.second;
		if (vis[a][b]) continue;
		vis[a][b] = true;
		for (i=0; i<4; i++) {
			c = a + dx[i];
			d = b + dy[i];
			if (c >= 0 && c < n && d >= 0 && d < m && dis[c][d] > dis[a][b] + mat[c][d]) {
				dis[c][d] = dis[a][b] + mat[c][d];
				pq.push(MP(dis[c][d], MP(c, d)));
			}
		}
	}
	return dis[n-1][m-1];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n>>m;
		for (i=0; i<n; i++) for (j=0; j<m; j++) cin>>mat[i][j];
		cout<<dijkstra()<<endl;
	}
	
	return 0;
}
