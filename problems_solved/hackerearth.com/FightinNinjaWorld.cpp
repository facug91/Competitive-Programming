/*
        By: facug91
        From: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/containers-of-choclates-1/
        Name: Fight in Ninja World
        Date: 30/11/2022
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#define endline std::endl;
#define LOG(x) std::cout << "#" << (#x) << ": " << (x) << std::endl
#else
#define endline "\n"
#define LOG(x)
#endif

const double EPS = 1e-9;
const double PI = 2.0 * acos(0.0);
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAX_N = 2e4 + 5;
const int MAX_K = 16;
const int MOD = 1e9 + 7;

int t, n, a, b, ans, vis[MAX_N];
vector<int> edges[MAX_N];

pair<int, int> dfs(int v, int cnt) {
	if (vis[v]) return { 0, 0 };
	vis[v] = true;
	pair<int, int> ans;
	for (int i = 0; i < edges[v].size(); i++) {
		auto res = dfs(edges[v][i], cnt + 1);
		ans.first += res.first;
		ans.second += res.second;
	}
	if (cnt % 2 == 0) ans.first++;
	else ans.second++;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	for (int it = 1; it <= t; it++) {
		cin >> n;
		for (int i=0; i<MAX_N; i++) {
			edges[i].clear();
			vis[i] = false;
		}
		while (n--) {
			cin >> a >> b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		ans = 0;
		for (int i=0; i<MAX_N; i++) {
			if (edges[i].empty()) continue;
			auto res = dfs(i, 0);
			ans += max(res.first, res.second);
		}
		cout << "Case " << it << ": " << ans << endline;
	}


	return 0;
}
