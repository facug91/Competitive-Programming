/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3008
        Name: Flip Five
        Date: 26/12/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int p, n, DP[1<<9];
int move[] = {416, 464, 200, 308, 186, 89, 38, 23, 11};
string s;
queue<int> q;

void bfs () {
	DP[0] = 0;
	q.push(0);
	int act, next;
	while (!q.empty()) {
		act = q.front();
		q.pop();
		for (int i=0; i<9; i++) {
			next = act ^ move[i];
			if (DP[next] == -1) {
				DP[next] = DP[act] + 1;
				q.push(next);
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	memset(DP, -1, sizeof DP);
	bfs();
	cin>>p;
	while (p--) {
		n = 0;
		for (i=0; i<3; i++) {
			cin>>s;
			for (j=0; j<3; j++) {
				if (s[j] == '*') {
					n |= (1<<(3*i+j));
				}
			}
		}
		cout<<DP[n]<<endl;
	}
	
	return 0;
}
