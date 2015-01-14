/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1452
        Name: Councilling
        Date: 13/01/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 105

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef vector<int> vi;
typedef vector<ii> vii;

int m, c, p, res[5000][5000], mf, s, t, level[5000];
string str;
vector<int> ady[5000];
map<string, int> member_to_int, club_to_int, party_to_int;
map<int, string> to_string;

bool bfs () {
	queue<int> q; q.push(s);
	memset(level, -1, sizeof level);
	level[s] = 0;
	int u, v;
	while (!q.empty()) {
		u = q.front(); q.pop();
		for (int i=0; i<(int)ady[u].size(); i++) {
			v = ady[u][i];
			if (level[v] == -1 && res[u][v] > 0) {
				level[v] = level[u] + 1;
				q.push(v);
				if (v == t) return true;
			}
		}
	}
	return level[t] != -1;
}

int dfs (int u, int min_edge) {
	if (u == t) return min_edge;
	int v, faux, fsum = 0;
	for (int i=0; i<(int)ady[u].size(); i++) {
		v = ady[u][i];
		if (res[u][v] > 0 && level[v] == level[u] + 1) {
			faux = dfs(v, min(min_edge, res[u][v]));
			if (faux) {
				fsum += faux;
				res[u][v] -= faux;
				res[v][u] += faux;
				min_edge -= faux;
				if (min_edge == 0) break;
			}
		}
	}
	return fsum;
}

int max_flow () {
	mf = 0;
	while (bfs()) mf += dfs(s, MAX_INT);
	return mf;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j, k, im, ic, ip;
	
	s = 0; t = 1;
	cin>>TC;
	getline(cin, str);
	getline(cin, str);
	while (TC--) {
		memset(res, 0, sizeof res);
		i = 2; j = 1002; k = 2002;
		ady[0].clear(); ady[1].clear();
		member_to_int.clear(); club_to_int.clear(); party_to_int.clear();
		to_string.clear();
		m = p = c = 0;
		while (getline(cin, str), str.length()) {
			istringstream ss(str);
			ss>>str; //name
			m++;
			ady[i].clear();
			im = member_to_int[str] = i;
			to_string[i++] = str;
			ss>>str; //party
			if (party_to_int.find(str) == party_to_int.end()) {
				p++;
				ady[j].clear();
				party_to_int[str] = j;
				to_string[j++] = str;
			}
			ip = party_to_int[str];
			ady[im].push_back(ip);
			ady[ip].push_back(im);
			res[im][ip] = 1;
			while (ss>>str) { //clubs
				if (club_to_int.find(str) == club_to_int.end()) {
					ady[k].clear();
					c++;
					club_to_int[str] = k;
					to_string[k++] = str;
				}
				ic = club_to_int[str];
				ady[ic].push_back(im);
				ady[im].push_back(ic);
				res[ic][im] = 1;
				ady[0].push_back(ic);
				ady[ic].push_back(0);
				res[0][ic] = 1;
			}
		}
		for (i=1002; i<p+1002; i++) {
			ady[i].push_back(1);
			ady[1].push_back(i);
			res[i][1] = (c-1)/2;
		}
		if (max_flow() == c) {
			for (i=2002; i<c+2002; i++) {
				for (j=0; res[i][ady[i][j]]!=0; j++);
				cout<<to_string[ady[i][j]]<<" "<<to_string[i]<<endl;
			}
		} else cout<<"Impossible."<<endl;
		
		
		
		if (TC) cout<<endl;
	}
	
	return 0;
}
