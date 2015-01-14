/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=666&page=show_problem&problem=1057
        Name: Robot Motion
        Number: 10116
        Date: 01/09/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 6005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m, s, vis[15][15];
char mat[15][15];
map<char, ii > move;

bool check_pos(int x, int y) {
	return (x >= 0) && (x < n) && (y >= 0) && (y < m); }

ii solve () {
	memset(vis, 0, sizeof vis);
	ii act = ii(0, s-1), ant;
	int cont = 1;
	while (check_pos(act.first, act.second) && !vis[act.first][act.second]) {
		vis[act.first][act.second] = cont++;
		ant.first = act.first;
		ant.second = act.second;
		act.first += move[mat[ant.first][ant.second]].first;
		act.second += move[mat[ant.first][ant.second]].second;
	}
	if (check_pos(act.first, act.second)) return ii(vis[act.first][act.second] - 1, vis[ant.first][ant.second] - vis[act.first][act.second] + 1);
	else return ii(vis[ant.first][ant.second], 0);
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	move['N'] = ii(-1, 0);
	move['S'] = ii(1, 0);
	move['E'] = ii(0, 1);
	move['W'] = ii(0, -1);
	
	while (scanf("%d %d %d", &n, &m, &s), n || m || s) {
		for (i=0; i<n; i++)
			scanf("%s", mat[i]);
		ii ans = solve();
		if (ans.second == 0) printf("%d step(s) to exit\n", ans.first);
		else printf("%d step(s) before a loop of %d step(s)\n", ans.first, ans.second);
	}
	
	return 0;
}

