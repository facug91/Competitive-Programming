/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=53
        Name: The Postal Worker Rings Once
        Date: 08/11/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int adj[30][30], odd[2], sum;
string s;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(6); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j, k;
	
	while (cin>>s) {
		for (i=0; i<26; i++) for (j=0; j<26; j++) adj[i][j] = INF;
		sum = 0;
		while (s != "deadend") {
			adj[s[0]-'a'][s.back()-'a'] = s.length();
			adj[s.back()-'a'][s[0]-'a'] = s.length();
			sum += (int)s.length();
			cin>>s;
		}
		int idx = 0;
		for (i=0; i<26; i++) {
			int cnt = 0;
			for (j=0; j<26; j++) cnt += (adj[i][j] != INF);
			if (cnt % 2 == 1) odd[idx++] = i;
		}
		if (idx == 2) {
			for (k=0; k<26; k++)
				for (i=0; i<26; i++)
					for (j=0; j<26; j++)
						adj[i][j] = min(adj[i][k]+adj[k][j], adj[i][j]);
			sum += adj[odd[0]][odd[1]];
		}
		cout<<sum<<endl;
	}
	turn 0;
}
