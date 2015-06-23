/*
        By: facug91
        From: http://coj.uci.cu/contest/cproblem.xhtml?pid=3286&cid=1453
        Name: Toby and Graph
        Date: 05/06/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, m, u, v, p[10005], number_of_sets;

int find_set (int i) {return (i == p[i]) ? i : (p[i] = find_set(p[i]));}

void union_set (int i, int j) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		number_of_sets--;
		p[x] = y;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n>>m;
		for (i=0; i<n; i++) p[i] = i;
		number_of_sets = n;
		for (i=0; i<m; i++) {
			cin>>u>>v; u--; v--;
			union_set(u, v);
		}
		cout<<number_of_sets*(number_of_sets-1)/2<<"\n";
	}
	
	return 0;
}
