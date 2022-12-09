/*
        By: facug91
        From: http://www.spoj.com/problems/TAP2016G/
        Name: Efficient managing
        Date: 04/10/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
#define right sabasiudgasdbsakdbaskjdbk321e
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

vii tree[100005];
int n, u, v, w, val[100005], trie[3000005][2], size;

stack<pair<int, ii>> stk;
void dfs () {
	stk.push(MP(0, MP(0, -1)));
	pair<int, ii> u;
	while (stk.size()) {
		u = stk.top(); stk.pop();
		val[u.F] = u.S.F;
		for (ii v : tree[u.F]) {
			if (v.F == u.S.S) continue;
			stk.push(MP(v.F, MP(v.S^u.S.F, u.F)));
		}
	}
}

void insert_word (int idx, int val, int pos) {
	if (pos == -1) return;
	int b = ((val & (1<<pos)) != 0);
	if (trie[idx][b] == -1) {
		trie[size][0] = trie[size][1] = -1;
		trie[idx][b] = size++;
	}
	insert_word(trie[idx][b], val, pos-1);
}

int travel_cost (int u) {
	int ans = 0, curr = 0, aux = 0, cnt = 30, b;
	while (cnt >= 0) {
		b = ((val[u] & (1<<cnt)) != 0);
		if (trie[aux][b^1] != -1) {
			ans += (1<<cnt);
			aux = trie[aux][b^1];
		} else {
			aux = trie[aux][b];
		}
		curr = trie[curr][b];
		cnt--;
	}
	return ans;
}

int main () {
	//#ifdef ONLINE_JUDGE
		//ios_base::sync_with_stdio(0); cin.tie(0);
	//#endif
	//cout<<fixed<<setprecision(6); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	while (scanf("%d", &n)  != EOF) {
		for (i=0; i<n; i++) tree[i].clear();
		if (n < 2 || n > 100000) return 0;
		for (i=0; i<n-1; i++) {
			scanf("%d %d %d", &u, &v, &w); 
			if (u <= 0 || v <= 0 || u > 100000 || v > 100000) return 0;
			u--; v--;
			tree[u].push_back(ii(v, w));
			tree[v].push_back(ii(u, w));
		}
		dfs();
		trie[0][0] = trie[0][1] = -1;
		size = 1;
		for (i=0; i<n; i++) insert_word(0, val[i], 30);
		for (i=0; i<n; i++) printf("%d\n", travel_cost(i));
	}
	
	return 0;
}
