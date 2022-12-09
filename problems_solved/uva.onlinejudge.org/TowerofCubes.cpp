/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=992
        Name: Tower of Cubes
        Date: 20/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, col[6], DP[3005], move[3005], mx, mx_idx;
vector<int> graph[3005], color[105];
string to_face[6];

void init () {
	to_face[0] = "front";
	to_face[1] = "back";
	to_face[2] = "left";
	to_face[3] = "right";
	to_face[4] = "top";
	to_face[5] = "bottom";
}

int dp (int idx) {
	if (DP[idx] != -1) return DP[idx];
	DP[idx] = 1;
	move[idx] = idx;
	int aux;
	for (int j=0; j<(int)graph[idx].size(); j++) {
		dp(graph[idx][j]);
		if (DP[graph[idx][j]] + 1 > DP[idx]) {
			DP[idx] = DP[graph[idx][j]] + 1;
			move[idx] = graph[idx][j];
		}
	}
	return DP[idx];
}

void print (int idx) {
	cout<<(idx/6)+1<<" "<<to_face[idx%6]<<endl;
	if (idx != move[idx]) print(move[idx]);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC = 1, i, j, k;
	
	init();
	while (cin>>n, n) {
		if (TC != 1) cout<<endl;
		for (i=1; i<=100; i++) color[i].clear();
		for (i=0; i<n; i++) {
			for (j=0; j<6; j++) {
				cin>>col[j];
				graph[i*6+j].clear();
				for (k=0; k<(int)color[col[j]].size(); k++) {
					graph[color[col[j]][k]].push_back(i*6+j);
				}
			}
			for (j=0; j<6; j++) color[col[j^1]].push_back(i*6+j);
		}
		mx = -1;
		memset(DP, -1, sizeof DP);
		for (i=0; i<n*6; i++) {
			if (DP[i] == -1) {
				dp(i);
				if (mx < DP[i]) {
					mx = DP[i];
					mx_idx = i;
				}
			}
		}
		cout<<"Case #"<<TC++<<endl;
		cout<<mx<<endl;
		print(mx_idx);
	}
	
	return 0;
}
