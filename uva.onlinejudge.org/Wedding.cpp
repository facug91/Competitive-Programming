/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2269
	Name: Wedding
	Date: 02/10/2015
*/

#include <bits/stdc++.h>
#define next asjkdbg1238dv8ydf38gy832gf8yd
#define prev asjkdbuiqdg783gdiu3dg79832dui
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
typedef vector<int> vi;    typedef vector<ii> vii;              typedef vector<iii> viii;

int n, m, u, v;
vi adj[MAXN];
string a, b;

stack<int> stk;
bool mark[MAXN];

bool dfs (int x) {  
	if (mark[x^1]) return false;  
	if (mark[x]) return true;  
	mark[x] = true;  
	stk.push(x); 
	for(int i=0; i<adj[x].size(); i++)  
		if(!dfs(adj[x][i])) return false;  
	return true;  
}  

bool solve() {  
	for(int i=0; i<n*2; i+=2) {
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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	while (cin>>n>>m, n || m) {
		for (i=0; i<n*2; i++) adj[i].clear();
		while (m--) {
			cin>>a>>b;
			u = stoi(a.substr(0, a.length()-1)) * 2;
			if (a.back() == 'w') u++;
			v = stoi(b.substr(0, b.length()-1)) * 2;
			if (b.back() == 'w') v++;
			adj[u^1].emplace_back(v);
			adj[v^1].emplace_back(u);
		}
		adj[0].emplace_back(1);
		memset(mark, 0, sizeof mark);
		bool ok = solve();
		if (!ok) cout<<"bad luck"<<endl;
		else {
			bool first = true;
			for (i=1; i<n; i++) {
				if (first) first = false;
				else cout<<" ";
				if (mark[i*2]) cout<<i<<"h";
				else cout<<i<<"w";
			}
			cout<<endl;
		}
	}
	
	return 0;
}
