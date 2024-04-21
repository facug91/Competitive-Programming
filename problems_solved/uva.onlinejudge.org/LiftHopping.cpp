/*
        By: facug91
        From: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1742
        Name: 10801 - Lift Hopping
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
	//priority_queue<tuple<WeightType, int>, vector<tuple<WeightType, int>>, greater<>> pq;
	priority_queue<pair<WeightType, int>, vector<pair<WeightType, int>>, greater<pair<WeightType, int>>> pq;
	dist[root] = 0;
	pq.push({ 0, root });
	while (!pq.empty()) {
		//auto [d, u] = pq.top();
		auto curr = pq.top();
		int d = curr.first;
		int u = curr.second;
		pq.pop();
		if (!vis[u]) {
			vis[u] = true;
			for (int i = 0; i < graph[u].size(); i++) {
				edge t = graph[u][i];
				if (dist[t.dest] >= dist[u] + t.weight) {
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

	int src = 500, dest = 501;
	vector<vector<edge>> graphIni(502);
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 400; j += 100) {
			for (int k = j + 100; k < 500; k += 100) {
				graphIni[i + j].push_back({ i + k, 60 });
				graphIni[i + k].push_back({ i + j, 60 });
			}
		}
	}
	for (int i = 0; i < 500; i += 100)
		graphIni[src].push_back({ i, 0 });

	int n, k;
	vector<int> t, dist;
	vector<bool> vis;
	vector<vector<int>> f;
	vector<vector<edge>> graph;

	string line;
	stringstream ss;
	while (getline(cin, line)) {
		ss << line;
		ss >> n >> k;
		ss.clear();
		t.resize(n);
		getline(cin, line);
		ss << line;
		for (int i = 0; i < n; i++)
			ss >> t[i];
		ss.clear();
		f.assign(n, vector<int>());
		for (int i = 0; i < n; i++) {
			getline(cin, line);
			ss << line;
			int aux;
			while (ss >> aux)
				f[i].push_back(aux);
			ss.clear();
		}
		graph = graphIni;
		for (int i = 0; i < n; i++)
			for (int j = 1; j < f[i].size(); j++) {
				graph[f[i][j - 1] + i * 100].push_back({ f[i][j] + i * 100, t[i] * (f[i][j] - f[i][j - 1]) });
				graph[f[i][j] + i * 100].push_back({ f[i][j - 1] + i * 100, t[i] * (f[i][j] - f[i][j - 1]) });
			}

		for (int i = 0; i < 500; i += 100)
			graph[k + i].push_back({ dest, 0 });

		int ans = 2e9;
		dijkstra<int>(graph, src, dist, vis);
		if (vis[dest]) cout << dist[dest] << endl;
		else cout << "IMPOSSIBLE" << endl;
	}


	return 0;
}
