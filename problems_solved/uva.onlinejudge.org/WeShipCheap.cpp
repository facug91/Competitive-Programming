/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=703
        Name: We Ship Cheap
        Date: 28/12/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000ll
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, father[1005];
map<string, int> to_number;
vector<int> graph[1005];
string s1, s2, to_string[1005];
stack<int> path;
bool vis[1005];

void bfs (int origin, int dest) {
	memset(vis, 0, sizeof vis);
	queue<int> q;
	vis[origin] = true;
	q.push(origin);
	int act;
	while (!q.empty()) {
		act = q.front(); q.pop();
		for (int i=0; i<(int)graph[act].size(); i++) {
			if (!vis[graph[act][i]]) {
				vis[graph[act][i]] = true;
				father[graph[act][i]] = act;
				if (graph[act][i] == dest) return;
				q.push(graph[act][i]);
			}
		}
	}
	
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	bool first = true;
	
	while (cin>>n) {
		if (first) first = false;
		else cout<<endl;
		
		j = 0; to_number.clear();
		for (i=0; i<n; i++) {
			cin>>s1>>s2;
			if (to_number.find(s1) == to_number.end()) {
				graph[j].clear();
				to_string[j] = s1;
				to_number[s1] = j++;
			}
			if (to_number.find(s2) == to_number.end()) {
				graph[j].clear();
				to_string[j] = s2;
				to_number[s2] = j++;
			}
			graph[to_number[s1]].push_back(to_number[s2]);
			graph[to_number[s2]].push_back(to_number[s1]);
		}
		
		cin>>s1>>s2;
		if ((to_number.find(s1) == to_number.end()) || (to_number.find(s2) == to_number.end())) {
			cout<<"No route"<<endl;
			continue;
		}
		
		memset(father, -1, sizeof father);
		bfs(to_number[s1], to_number[s2]);
		if (father[to_number[s2]] == -1) {
			cout<<"No route"<<endl;
		} else {
			i = to_number[s2];
			path.push(i);
			while (father[i] != -1) {
				i = father[i];
				path.push(i);
			}
			path.pop();
			while (!path.empty()) {
				cout<<to_string[father[path.top()]]<<" "<<to_string[path.top()]<<endl;;
				path.pop();
			}
		}
		
	}
	
	return 0;
}
