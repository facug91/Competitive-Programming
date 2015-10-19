/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1175
        Name: Jane and the Frost Giants
        Date: 27/08/2015
*/
 
#include <bits/stdc++.h>
#define y1 		nd03dnqwuidg1odbnw9uddu0132d
#define clock 	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
//#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int r, c, ans, dis[205][205];
string mat[205];
bool visf[205][205], visj[205][205];

bool bfs () {
	queue<pair<ii, char> > q;
	memset(visf, 0, sizeof visf);
	memset(visj, 0, sizeof visj);
	int i, j, x, y, w, z, d, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
	ii ori;
	for (i=0; i<r; i++) for (j=0; j<c; j++) {
		if (mat[i][j] == 'F') {
			visf[i][j] = true;
			q.push(MP(MP(i, j), 'F'));
		} else if (mat[i][j] == 'J') {
			visj[i][j] = true;
			dis[i][j] = 1;
			ori = ii(i, j);
		}
	}
	q.push(MP(ori, 'J'));
	pair<ii, char> act;
	while (q.size()) {
		act = q.front(); q.pop();
		x = act.first.first;
		y = act.first.second;
		for (d=0; d<4; d++) {
			w = x + dx[d]; z = y + dy[d];
			if (w >= 0 && w < r && z >= 0 && z < c && mat[w][z] != '#') {
				if (act.second == 'F') {
					if (!visf[w][z]) {
						visf[w][z] = true;
						q.push(MP(MP(w, z), 'F'));
					}
				} else if (!visj[w][z] && !visf[w][z]) {
					visj[w][z] = true;
					dis[w][z] = dis[x][y] + 1;
					q.push(MP(MP(w, z), 'J'));
					if (w == 0 || w == r-1 || z == 0 || z == c-1) {
						ans = dis[w][z];
						return true;
					}
				}
			}
		}
	}
	return false;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>r>>c;
		for (i=0; i<r; i++) cin>>mat[i];
		if (!bfs()) cout<<"Case "<<it<<": IMPOSSIBLE\n";
		else cout<<"Case "<<it<<": "<<ans<<"\n";
	}
	
	return 0;
}
