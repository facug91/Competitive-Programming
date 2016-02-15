/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=104
        Name: Theseus and the Minotaur
        Date: 21/01/2015
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-2
#define MP make_pair
#define F first
#define S second
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

vi adj[30];
char x, y;
int a, b, s, t, k;
string graph;
bool candle[30];

void dfs (int u, int f, int cont) {
	bool trapped = true;
	for (int v : adj[u]) {
		if (v != f && !candle[v]) {
			trapped = false;
			break;
		}
	}
	if (trapped) {
		cout<<"/"<<(char)(u+'A')<<endl;
		return;
	}
	if (cont == k) {
		candle[u] = true;
		cont = 0;
		cout<<(char)(u+'A')<<" ";
	}
	for (int v : adj[u]) {
		if (v != f && !candle[v]) {
			dfs(v, u, cont+1);
			return;
		}
	}
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	while (cin>>graph, graph[0] != '#') {
		for (i=0; i<26; i++) adj[i].clear();
		memset(candle, 0, sizeof candle);
		cin>>x>>y>>k;
		s = x - 'A';
		t = y - 'A';
		i = 0;
		while (true) {
			a = graph[i] - 'A';
			i += 2;
			while (graph[i] >= 'A' && graph[i] <= 'Z') adj[a].push_back(graph[i++]-'A');
			if (graph[i] == '.') break;
			else i++;
		}
		dfs(s, t, 1);
	}
	
	return 0;
}
