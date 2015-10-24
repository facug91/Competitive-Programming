/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=54
        Name: Mutant Flatworld Explorers
        Date: 18/10/2015
*/
 
#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, m, x, y, w, z, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool mat[55][55], ok;
char act_or, to_char[] = {'N', 'E', 'S', 'W'};
string moves;
map<char, int> to_idx;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j, l;
	
	to_idx['N'] = 0;
	to_idx['S'] = 2;
	to_idx['E'] = 1;
	to_idx['W'] = 3;
	
	cin>>n>>m; n++; m++;
	while (cin>>x>>y>>act_or) {
		cin>>moves;
		ok = true; i = 0;
		while (ok && i<moves.length()) {
			if (moves[i] == 'F') {
				w = x; z = y;
				x += dx[to_idx[act_or]];
				y += dy[to_idx[act_or]];
				if (x < 0 || x >= n || y < 0 || y >= m) {
					x = w; y = z;
					if (!mat[x][y]) ok = false;
				}
			} else {
				if (moves[i] == 'R') 	act_or = to_char[(to_idx[act_or]+1)%4];
				else 					act_or = to_char[(4+to_idx[act_or]-1)%4];
			}
			i++;
		}
		cout<<x<<" "<<y<<" "<<act_or;
		if (!ok) {
			cout<<" LOST"<<endl;
			mat[x][y] = true;
		} else cout<<endl;
	}
	
	return 0;
}
