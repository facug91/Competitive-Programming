/*
        By: facug91
        From: http://www.spoj.com/problems/TAP2014E/
        Name: Erdos et al
        Date: 15/12/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int a, n, c, p, erdos_number[100005], d, m, s;
vector<int> article[100005], author[100005];
bool vis_art[100005], vis_aut[100005];
queue<int> q;

void bfs () {
	memset(vis_art, false, sizeof vis_art);
	memset(vis_aut, false, sizeof vis_aut);
	vis_aut[1] = true;
	q.push(1);
	int act, i, j, art, aut;
	while (!q.empty()) {
		act = q.front(); q.pop();
		for (i=0; i<(int)author[act].size(); i++) {
			art = author[act][i];
			if (!vis_art[art]) {
				vis_art[art] = true;
				for (j=0; j<(int)article[art].size(); j++) {
					aut = article[art][j];
					if (!vis_aut[aut]) {
						vis_aut[aut] = true;
						erdos_number[aut] = erdos_number[act] + 1;
						q.push(aut);
					}
				}
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>a>>n;
	for (i=0; i<a; i++) {
		cin>>c;
		for (j=0; j<c; j++) {
			cin>>p;
			article[i].push_back(p);
			author[p].push_back(i);
		}
	}
	memset(erdos_number, -1, sizeof erdos_number);
	erdos_number[1] = 0;
	bfs();
	d = m = s = 0;
	for (i=1; i<=n; i++) {
		if (erdos_number[i] != -1) d++;
		if (erdos_number[i] > m) m = erdos_number[i];
		if (erdos_number[i] != -1) s += erdos_number[i];
	}
	cout<<d<<" "<<m<<" "<<s<<endl;
	
	return 0;
}
