/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=1941
        Name: Meeting Prof. Miguel
        Date: 12/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, c, adj[2][26][26], ans;
char a, d, u, v, s, t;
map<char, int> age;
set<char> places;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j, k, l;
	
	age['Y'] = 0;
	age['M'] = 1;
	while (cin>>n, n) {
		for (i=0; i<26; i++) for (j=0; j<26; j++) adj[0][i][j] = adj[1][i][j] = INF;
		for (i=0; i<26; i++) adj[0][i][i] = adj[1][i][i] = 0;
		for (i=0; i<n; i++) {
			cin>>a>>d>>u>>v>>c;
			if (adj[age[a]][u-'A'][v-'A'] > c) adj[age[a]][u-'A'][v-'A'] = c;
			if (d == 'B' && adj[age[a]][v-'A'][u-'A'] > c) adj[age[a]][v-'A'][u-'A'] = c;
		}
		cin>>s>>t;
		for (l=0; l<2; l++)
			for (k=0; k<26; k++)
				for (i=0; i<26; i++)
					for (j=0; j<26; j++)
						adj[l][i][j] = min(adj[l][i][j], adj[l][i][k]+adj[l][k][j]);
		ans = INT_MAX; places.clear();
		for (i=0; i<26; i++) {
			if (ans > adj[0][s-'A'][i]+adj[1][t-'A'][i]) {
				ans = adj[0][s-'A'][i]+adj[1][t-'A'][i];
				places.clear();
				places.insert(i+'A');
			} else if (ans == adj[0][s-'A'][i]+adj[1][t-'A'][i]) {
				places.insert(i+'A');
			}
		}
		if (ans >= INF) cout<<"You will never meet.\n";
		else {
			cout<<ans;
			for (set<char>::iterator itr=places.begin(); itr!=places.end(); itr++) cout<<" "<<*itr;
			cout<<endl;
		}
	}
	
	return 0;
}
