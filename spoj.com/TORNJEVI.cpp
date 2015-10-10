/*
	By: facug91
	From: http://www.spoj.com/problems/TORNJEVI/
	Name: TORNJEVI
	Date: 03/10/2015
*/

#include <bits/stdc++.h>
#define next 	asjkdbg1238dv8ydf38gy832gf8yd
#define prev 	jasdjksadjsadho32r80ejd8h3rsd
#define right 	nkdbj3dsbuhdfhu32rbhkdfhubj38
#define down 	pjasfias3dbasdgsauidb39dgsa92
#define EPS 1e-9
#define MP make_pair
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
#define MAXN 500

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, m, enemy[105][105], tower[105][105], en, tow, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
string mat[105];
vi adj[20020];
vii enemyPointedBy[10010];

bool search (int i, int j, int d, int t, int tv) {
	if (i < 0 || i == n || j < 0 || j == m || mat[i][j] == '#') return true;
	if (mat[i][j] == 'T') return false;
	bool ret = search(i+dx[d], j+dy[d], d, t, tv);
	if (ret && mat[i][j] == 'n') enemyPointedBy[enemy[i][j]].emplace_back(t, tv);
	return ret;
}

// Start 2SAT algorithm
void force (int i, int v) {
	int u = i * 2 + v;
	adj[u^1].emplace_back(u);
}

void addOR (int i, int v1, int j, int v2) {
	int u = i * 2 + v1;
	int v = j * 2 + v2;
    adj[u^1].emplace_back(v);
    adj[v^1].emplace_back(u);
}

stack<int> stk;
bool mark[20020]; // Initialize to 0

bool dfs (int x) { 
    if (mark[x^1]) return false;
    if (mark[x]) return true;
    mark[x] = true;  
    stk.push(x);
    for (auto v : adj[x])
        if(!dfs(v)) return false;  
    return true;  
}  

bool solve() {  
    for(int i=0; i<tow*4; i+=2) {
        if(!mark[i] && !mark[i+1]) {  
            while (stk.size()) stk.pop();
            if(!dfs(i)) {
                while (stk.size()) {
                    mark[stk.top()] = false;
                    stk.pop();
                }
                if(!dfs(i+1)) return false;
            }  
        }
    }
    return true;  
} 
// End 2SAT algorithm


int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j, d;
	
	cin>>n>>m;
	for (i=0; i<n; i++) cin>>mat[i];
	en  = 0; memset(enemy, 0, sizeof enemy);
	tow = 0; memset(tower, 0, sizeof tower);
	for (i=0; i<n; i++) for (j=0; j<m; j++) {
		if (mat[i][j] == 'n') enemy[i][j] = en++;
		if (mat[i][j] == 'T') tower[i][j] = tow++;
	}
	for (i=0; i<n; i++) for (j=0; j<m; j++) if (mat[i][j] == 'T') for (d=0; d<4; d++) {
		int t = (tower[i][j]+(d%2)*tow);
		if (!search(i+dx[d], j+dy[d], d, t, (int)(d<2))) force(t, (int)(d<2)^1);
	}
	for (i=0; i<en; i++) {
		if (enemyPointedBy[i].size() == 1) force(enemyPointedBy[i][0].first, enemyPointedBy[i][0].second);
		else if (enemyPointedBy[i].size() == 2) 
			addOR(enemyPointedBy[i][0].first, enemyPointedBy[i][0].second, enemyPointedBy[i][1].first, enemyPointedBy[i][1].second);
	}
	memset(mark, 0, sizeof mark);
	solve();
	for (i=0; i<n; i++) for (j=0; j<m; j++) if (mat[i][j] == 'T') {
		if (mark[tower[i][j]*2+1]  &&  mark[(tower[i][j]+tow)*2+1])  mat[i][j] = '2';
		if (!mark[tower[i][j]*2+1] &&  mark[(tower[i][j]+tow)*2+1])  mat[i][j] = '1';
		if (mark[tower[i][j]*2+1]  && !mark[(tower[i][j]+tow)*2+1])  mat[i][j] = '3';
		if (!mark[tower[i][j]*2+1] && !mark[(tower[i][j]+tow)*2+1])  mat[i][j] = '4';
	}
	for (i=0; i<n; i++) cout<<mat[i]<<endl;
	
	return 0;
}
