/*
        By: facug91
        From: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=679&page=show_problem&problem=1219
        Name: 10278 - Fire Station
        Date: 21/04/2024
        Solution: Dijkstra
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#define endline std::endl
#define LOG(x) std::cerr << "#" << (#x) << ": " << (x) << std::endl
#else
#define endline "\n"
#define LOG(x)
#endif

template<typename T>
T fastMod(const T input, const T ceil) { return input >= ceil ? input % ceil : input; }

#define y0 dbnw9uddu0132dnd03dnqwuidg1o
#define y1 nd03dnqwuidg1odbnw9uddu0132d
const double EPS = 1e-9;
const double PI = 2.0 * acos(0.0);
using ll = long long;
using ii = pair<int, int>;

const int MAX_N = 1e5 + 5;
const int MAX_Q = 1e5 + 5;
const int MOD = 1e9 + 7;

struct edge {
	int dest;
	int weight;
};

template<typename WeightType = int>
void dijkstra(const vector<vector<edge>>& graph, int root, vector<int>& dist, vector<bool>& vis) {
	int vertices = graph.size();
	const WeightType INF = std::numeric_limits<WeightType>::max();
	dist.assign(vertices, INF);
	vis.assign(vertices, false);
//	priority_queue<tuple<WeightType, int>, vector<tuple<WeightType, int>>, greater<>> pq;                    // C++17
	priority_queue<pair<WeightType, int>, vector<pair<WeightType, int>>, greater<pair<WeightType, int>>> pq; // C++11
	dist[root] = 0;
	pq.push({ 0, root });
	while (!pq.empty()) {
//		auto [d, u] = pq.top(); // C++17
		auto curr = pq.top();   // C++11
		int d = curr.first;     // C++11
		int u = curr.second;    // C++11
		pq.pop();
		if (!vis[u]) {
			vis[u] = true;
			for (int i = 0; i < graph[u].size(); i++) {
				edge t = graph[u][i];
				if (dist[t.dest] > dist[u] + t.weight) {
					dist[t.dest] = dist[u] + t.weight;
					pq.push({ dist[t.dest], t.dest });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc;
	string line;
	stringstream ss;
	getline(cin, line);
	ss << line;
	ss >> tc;
	ss.clear();
	getline(cin, line); // read empty line
	vector<vector<edge>> graph;
	for (int itc = 0; itc < tc; itc++) {
		int f, n;

		getline(cin, line);
		ss << line;
		ss >> f >> n;
		ss.clear();

		graph.clear();
		graph.resize(n+1);
		int src = 0, fi;
		set<int> fs;

		for (int i = 0; i < f; i++) {
			getline(cin, line);
			ss << line;
			ss >> fi;
			ss.clear();
			graph[src].push_back({ fi, 0 });
			fs.insert(fi);
		}

		int v1, v2, w;
		while (getline(cin, line)) {
			if (line.empty()) break;
			ss << line;
			ss >> v1 >> v2 >> w;
			ss.clear();
			graph[v1].push_back({ v2, w });
			graph[v2].push_back({ v1, w });
		}

		int ans = INT_MAX, ansi = 1;
		vector<int> dist;
		vector<bool> vis;
		for (int i = 1; i <= n; i++) {
			if (fs.count(i)) continue;
			graph[src].push_back({ i, 0 });
			dijkstra(graph, src, dist, vis);
			int mx = -1;
			for (int j = 1; j <= n; j++)
				mx = max(mx, dist[j]);
			if (mx < ans) {
				ans = mx;
				ansi = i;
			}
			graph[src].pop_back();
		}

		cout << ansi << endl;
		if (itc != tc - 1)
			cout << endl;
	}

	return 0;
}
