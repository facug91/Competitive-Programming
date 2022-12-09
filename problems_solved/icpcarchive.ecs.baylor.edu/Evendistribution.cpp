/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=658&page=show_problem&problem=4837
        Name: Even distribution
        Date: 19/12/2014
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

int is, s, a, b, candys[10005];
set<int> ans, act[10005];
vector<int> graph[10005];
bool vis[10005];

int gcd (int a, int b) {
	if (a == 0) return b;
	return gcd(b%a, a);
}

void dfs (int idx, int father) {
	act[idx].insert(candys[idx]);
	vis[idx] = true;
	if (father != 0) {
		vector<int> aux;
		for (set<int>::iterator i=act[idx].begin(); i!=act[idx].end(); i++)
			for (set<int>::iterator j=act[father].begin(); j!=act[father].end(); j++)
				aux.push_back(gcd(*i, *j));
		for (int i=0; i<(int)aux.size(); i++)
			act[idx].insert(aux[i]);
	}
	int v;
	for (int i=(int)graph[idx].size()-1; i>=0; i=(int)graph[idx].size()-1) {
		v = graph[idx][i];
		graph[idx].pop_back();
		dfs(v, idx);
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>is>>s) {
		for (i=1; i<=is; i++) {
			act[i].clear();
			graph[i].clear();
			cin>>candys[i];
			vis[i] = false;
		}
		ans.clear();
		for (i=0; i<s; i++) {
			cin>>a>>b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for (i=1; i<=is; i++) {
			if (!vis[i]) {
				dfs(i, 0);
			}
		}
		for (i=1; i<=is; i++) {
			for (set<int>::iterator j=act[i].begin(); j!=act[i].end(); j++) {
				ans.insert(*j);
			}
		}
		cout<<ans.size()<<endl;
	}
	
	return 0;
}
